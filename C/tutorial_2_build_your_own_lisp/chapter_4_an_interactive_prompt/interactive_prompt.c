#include <stdlib.h>
#include <stdio.h>

// Declare a buffer for user input with size 2048
static char input[2048];

int main(int argc, char **argv)
{
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

        // print the input to the user
        printf("No you are a %s", input);
    }

    return 0;
}