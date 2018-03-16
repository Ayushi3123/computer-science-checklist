/**
 * Switched to the final version of the tutor code for this one, even though
 * my code complied, wanted the ifdef, just in case
 */

#include <stdlib.h>
#include <stdio.h>
#include "..\__lib__\mpc\mpc.h"

#ifdef _WIN32

static char buffer[2048];

char *readline(char *prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

void add_history(char *unused) {}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

// Create enumeration of possible lval types
enum
{
    LVAL_NUM,
    LVAL_ERR,
    LVAL_SYM,
    LVAL_SEXPR
};

// Enumeration of possible error types
enum
{
    LERR_DIV_ZERO,
    LERR_BAD_OP,
    LERR_BAD_NUM
};

/**
 * lval struct - lval = Lisp Value
 */
typedef struct
{
    int type;
    long num;
    //error and symbol types have some string data
    char *err;
    char *sym;
    //count and pointer to a list of 'lval'
    int count;
    struct lval **cell;
} lval;

/**
 * Create a new lval and return the pointer
 */
lval *lval_num(long x)
{
    lval *v = malloc(sizeof(lval));
    v->type = LVAL_NUM,
    v->num = x;
    return v;
}

/**
 * Create a new lval err and return the pointer
 */
lval *lval_err(char *m)
{
    lval *v = malloc(sizeof(lval));
    v->type = LVAL_ERR;
    v->err = malloc(strlen(m) + 1);
    strcopy(v->err, m);
    return v;
}

lval *lval_sym(char *s)
{
    lval *v = malloc(sizeof(lval));
    v->type = LVAL_SYM;
    v->sym = malloc(strlen(s) + 1);
    strcopy(v->sym, s);
    return v;
}

lval *lval_sexpr(void)
{
    lval *v = malloc(sizeof(lval));
    v->type = LVAL_SEXPR;
    v->count = 0;
    v->cell = NULL;
    return v;
}

void lval_del(lval *v)
{
    switch (v->type)
    {
    case LVAL_NUM:
        break;
    case LVAL_ERR:
        free(v->err);
        break;
    case LVAL_SYM:
        free(v->sym);
        break;
    case LVAL_SEXPR:
        for (int i = 0; i < v->count; i++)
        {
            lval_del(v->cell[i]);
        }
        free(v->cell);
        break;
    }

    // SET V FREE !!!
    free(v);
}

/**
 * Returns an lval_num lval if no error is set
 */
lval *lval_read_num(mpc_ast_t *t)
{
    errno = 0;
    long x = strtol(t->contents, NULL, 10);
    return errno != ERANGE ? lval_num(x) : lval_err("invalid number");
}

lval *lval_add(lval *v, lval *x)
{
    v->count++;
    v->cell = realloc(v->cell, sizeof(lval *) * v->count);
    v->cell[v->count - 1] = x;
    return v;
}

lval *lval_read(mpc_ast_t *t)
{

    // return the symbol and number types
    if (strstr(t->tag, "number"))
    {
        return lval_read_num(t);
    }
    if (strstr(t->tag, "symbol"))
    {
        return lval_sym(t->contents);
    }

    lval *x = NULL;

    // if it is root or sexpr create an empty list
    // code seems a bit redundant, might change later in
    // tutorial?
    if (strcmp(t->tag, ">") == 0)
    {
        x = lval_sexpr();
    }
    if (strcmp(t->tag, "sexpr") == 0)
    {
        x = lval_sexpr();
    }

    // fill with all the valid expressions in children list
    for (int i = 0; i < t->children_num; i++)
    {
        // more redundant code ??? oh well
        if (strcmp(t->children[i]->contents, "(") == 0)
        {
            continue;
        }
        if (strcmp(t->children[i]->contents, ")") == 0)
        {
            continue;
        }
        if (strcmp(t->children[i]->contents, "regex") == 0)
        {
            continue;
        }

        x = lval_add(x, lval_read(t->children[i]));
    }
}

/**
 * Prints an lval
 */
void lval_print(lval v)
{
    switch (v.type)
    {
    // print if just a number
    case LVAL_NUM:
        printf("%li", v.num);
        break;

    // error type handling
    case LVAL_ERR:
        if (v.err == LERR_DIV_ZERO)
        {
            printf("Error : Division By Zero!");
        }
        else if (v.err == LERR_BAD_OP)
        {
            printf("Error: Invalid Operator!");
        }
        else if (v.err == LERR_BAD_NUM)
        {
            printf("Error: Invalid Number!");
        }
        break;
    }
}

/**
 * Print a lval with a newline
 */
void lval_printLn(lval v)
{
    lval_print(v);
    putchar('\n');
}

/**
 * Use operator string to see which operation to perform
 */
lval eval_op(lval x, char *op, lval y)
{
    // if there is an error, return the lval that contains is
    if (x.type == LVAL_ERR)
    {
        return x;
    }
    if (y.err == LVAL_ERR)
    {
        return y;
    }

    // otherwise we need to continue with the operation
    if (strcmp(op, "+") == 0)
    {
        return lval_num(x.num + y.num);
    }
    if (strcmp(op, "-") == 0)
    {
        return lval_num(x.num - y.num);
    }
    if (strcmp(op, "*") == 0)
    {
        return lval_num(x.num * y.num);
    }
    if (strcmp(op, "/") == 0)
    {
        return y.num == 0 ? lval_err(LERR_DIV_ZERO) : lval_num(x.num / y.num);
    }

    return lval_err(LERR_BAD_OP);
}

/**
 * Evaluate polish notation
 */
lval eval(mpc_ast_t *t)
{

    /* If tagged as number return it directly. */
    if (strstr(t->tag, "number"))
    {
        // check if there is an error in conversion
        errno = 0;
        long x = strtol(t->contents, NULL, 10);
        return errno != ERANGE ? lval_num(x) : lval_err(LERR_BAD_NUM);
    }

    /* The operator is always second child. */
    char *op = t->children[1]->contents;

    /* We store the third child in `x` */
    lval x = eval(t->children[2]);

    /* Iterate the remaining children and combining. */
    int i = 3;
    while (strstr(t->children[i]->tag, "expr"))
    {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}

/**
 * The entry point of the application
 */
int main(int argc, char **argv)
{
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Symbol = mpc_new("symbol");
    mpc_parser_t *Sexpr = mpc_new("sexpr");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT,
              "                              \
    number : /-?[0-9]+/ ;                    \
    symbol : '+' | '-' | '*' | '/' ;         \
    sexpr  : '(' <expr>* ')' ;               \
    expr   : <number> | <symbol> | <sexpr> ; \
    lispy  : /^/ <expr>* /$/ ;               \
    ",
              Number, Symbol, Sexpr, Expr, Lispy);

    puts("Lispy Version 0.0.0.0.3");
    puts("Press Ctrl+c to Exit\n");

    while (1)
    {

        char *input = readline("lispy> ");
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r))
        {

            lval result = eval(r.output);
            lval_printLn(result);
            //printf("%li\n", result);
            mpc_ast_delete(r.output);
        }
        else
        {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }

    mpc_cleanup(5, Number, Symbol, Sexpr, Expr, Lispy);

    return 0;
}
