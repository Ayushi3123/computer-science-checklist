#include <stdlib.h>
#include <stdio.h>
#include "mpc.h"

// Declare a buffer for user input with size 2048
static char input[2048];

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
