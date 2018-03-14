#include <stdlib.h>
#include <stdio.h>
#include "..\__lib__\mpc\mpc.h"

// Declare a buffer for user input with size 2048
static char input[2048];

/**
 * Counts the number of nodes in a tree from the mpc node
 */
int number_of_nodes(mpc_ast_t *t)
{
    if (t->children_num == 0)
    {
        return 1;
    }
    if (t->children_num >= 1)
    {
        int totalChildren = 1;
        for (int i = 0; i < t->children_num; i++)
        {
            totalChildren += number_of_nodes(t->children[i]);
        }
        return totalChildren;
    }
    return 0;
}

long eval_op(long x, char *op, long y)
{
    if (strcmp(op, "+") == 0)
    {
        return x + y;
    }
    if (strcmp(op, "-") == 0)
    {
        return x - y;
    }
    if (strcmp(op, "*") == 0)
    {
        return x * y;
    }
    if (strcmp(op, "/") == 0)
    {
        return x / y;
    }

    return 0;
}

long eval(mpc_ast_t *t)
{
    // if it is a number, return it as a number
    if (strstr(t->tag, "number"))
    {
        return atoi(t->contents);
    }

    // the operator always appears as the second child
    char *op = t->children[1]->contents;

    // store the third child in the variable x, so that we can use the op on it
    long x = eval(t->children[2]);

    // iterate the remaining children and appy the operator
    int i = 3;
    while (strstr(t->children[i]->tag, "expr"))
    {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}

/**
 * Main entry point of the application
 */
int main(int argc, char **argv)
{
    // Create some mpc parsers
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lispy = mpc_new("lispy");

    // define the parser rules
    mpca_lang(MPCA_LANG_DEFAULT,
              "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
  ",
              Number, Operator, Expr, Lispy);

    // guess we should tell them this is a very useless version, as well as how to close this useless version
    puts("Lispy Version 0.0.0.0.1"); // so far to go...
    puts("Press ctrl+c to exit");

    // This seems like a good idea...
    while (1)
    {
        // cool looking prompt text
        fputs("lispy> ", stdout);

        // get a line of user input with maximum size of 2048
        fgets(input, 2048, stdin);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r))
        {
            mpc_ast_print(r.output);

            // // Load the ast from the parse
            // mpc_ast_t *a = r.output;
            // printf("Tag: %s\n", a->tag);
            // printf("Content: %s\n", a->contents);
            // printf("Number of children: %i\n", a->children_num);

            // // Check out the first child
            // mpc_ast_t *c0 = a->children[0];
            // printf("First child's tag: %s\n", c0->tag);
            // printf("First child's content: %s\n", c0->contents);
            // printf("First child's number of children: %i", c0->children_num);

            // mpc_ast_t *b = r.output;
            // printf("Number of node: %i", number_of_nodes(b));

            long result = eval(r.output);
            printf("%li\n",result);
            
            mpc_ast_delete(r.output);
        }
        else
        {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
    }

    // clean up the parsers
    mpc_cleanup(4, Number, Operator, Expr, Lispy);

    return 0;
}
