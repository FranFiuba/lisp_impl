#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

int main(int argc, char **argcv)
{
    puts("Lisp 0.0.0.1");
    puts("Press Ctrl+c to Exit");

    while (1)
    {
        /* output prompot */
        char *input = readline("lisp> ");

        /* get user input of max size 2048*/
        add_history(input);

        /* echo the user input */
        printf("No you're a %s", input);

        /* Free input memory*/
        free(input);
    }

    return 0;
}