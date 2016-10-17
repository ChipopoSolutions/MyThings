#include <stdio.h>
#include <stdlib.h>
int main ()
{
    char* my_arg = getenv ("MY_ARG");
    if (my_arg == NULL)
        /* The ARG_NAME environment variable was not set.Use the default. */
        my_arg = "some.default.arg";

    printf ("Proccessing arg: %s\n", my_arg);
    /* Proccess the arg here... */
    return 0;
}