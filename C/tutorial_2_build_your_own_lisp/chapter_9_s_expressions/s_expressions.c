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
    int err;
} lval;

/**
 * Create a new lval
 */
lval lval_num(long x)
{
    lval v;
    v.type = LVAL_NUM,
    v.num = x;
    return v;
}

/**
 * Create a new lval err
 */
lval lval_err(int x)
{
    lval v;
    v.type = LVAL_ERR;
    v.err = x;
    return v;
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
