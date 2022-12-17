#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include "lib/mpc.h"

// Language 
const char* LANGUAGE = "                                \
    number :   /-?[0-9]+/;                              \
    operator: '+' | '-' | '*' | '/';                    \
    expression: <number> | '(' <operator> <expression>+ ')' ; \
    program: /^/ <operator> <expression>+ /$/;                \
  ";

int main(int argc, char **argcv)
{
    // Number
    mpc_parser_t* Number = mpc_new("number");
    // Operator
    mpc_parser_t* Operator = mpc_new("operator");
    // Expression
    mpc_parser_t* Expression = mpc_new("expression");
    // Program
    mpc_parser_t* Program = mpc_new("program");

    mpca_lang(MPCA_LANG_DEFAULT ,LANGUAGE ,Number ,Operator ,Expression ,Program);

    puts("Lisp 0.0.0.1");
    puts("Press Ctrl+c to Exit");

    while (1)
    {
        /* output prompot */
        char *input = readline("lisp> ");

        /* get user input of max size 2048*/
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Program, &r)) {
            /* On Success Print the AST */
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        } else {
            /* Otherwise Print the Error */
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        /* Free input memory*/
        free(input);
    }

    mpc_cleanup(4, Number, Operator, Expression, Program);

    return 0;
}