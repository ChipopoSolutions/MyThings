#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* The name of this program.*/
const char* program_name;

/* Prints usage information for this program to STREAM (typically
stdout or stderr), and exit the program with EXIT_CODE. Does not
return. */

void print_usage (FILE* stream, int exit_code)
{
    fprintf (stream, "Usage: %s options [ inputfile ... ]\n", program_name);
    fprintf (stream,
            " -h --help Display this usage information.\n"
            " -o --output filename Write output to file.\n"
            " -v --verbose Print verbose messages.\n");
    exit (exit_code);
}


/* Main program entry point. ARGC contains number of argument list
elements; ARGV is an array of pointers to them. */

int main (int argc, char* argv[])
{
    int next_option;

    /*
    To use getopt_long , we must provide two data structures.The first is a character
    string containing the valid short options, each a single letter. An option that requires
    an argument is followed by a colon. For your program, the string ho:v indicates that
    the valid options are -h , -o , and -v , with the second of these options followed by an
    argument.
    */


    /* A string listing valid short options letters.*/
    const char* const short_options = "ho:v";

    /*
    To specify the available long options, we construct an array of struct option ele-
    ments. Each element corresponds to one long option and has four fields. In normal
    circumstances, the first field is the name of the long option (as a character string, with-
    out the two hyphens); the second is 1 if the option takes an argument, or 0 otherwise;
    the third is NULL ; and the fourth is a character constant specifying the short option
    synonym for that long option.The last element of the array should be all zeros.We
    could construct the array like this:
    */


    /* An array describing valid long options. */
    const struct option long_options[] = {
        { "help", 0, NULL, 'h' },
        { "output", 1, NULL, 'o' },
        { "verbose", 0, NULL, 'v' },
        { NULL, 0, NULL, 0    } /* Required at end of array. */
    };

    /* The name of the file to receive program output, or NULL for
    standard output. */
    const char* output_filename = NULL;

    /* Whether to display verbose messages. */
    int verbose = 0;

    /* Remember the name of the program, to incorporate in messages.
    The name is stored in argv[0]. */
    program_name = argv[0];

        do {

            /*
            -   Each time you call getopt_long , it parses a single option, returning the short-
            option letter for that option, or –1 if no more options are found.

            -   Typically, you’ll call getopt_long in a loop, to process all the options the user has
            specified, and you’ll handle the specific options in a switch statement.

            -   If getopt_long encounters an invalid option (an option that you didn’t specify as a valid short
            or long option), it prints an error message and returns the character ? (a question mark). Most
            programs will exit in response to this, possibly after displaying usage information.

            -   When handling an option that takes an argument, the global variable optarg points to
            the text of that argument.

            -   After getopt_long has finished parsing all the options, the global variable optind contains the
            index (into argv ) of the first nonoption argument.
            */

            next_option = getopt_long (argc, argv, short_options, long_options, NULL);

            switch (next_option)
            {
                case 'h':
                /* -h or --help */
                /* User has requested usage information. Print it to standard
                output, and exit with exit code zero (normal termination). */
                print_usage (stdout, 0);

                case 'o':
                /* -o or --output */
                /* This option takes an argument, the name of the output file.*/
                output_filename = optarg;
                break;

                case 'v':
                /* -v or --verbose */
                verbose = 1;
                break;

                case '?':
                /* The user specified an invalid option. */
                /* Print usage information to standard error, and exit with exit
                code one (indicating abnormal termination). */
                print_usage (stderr, 1);

                case -1:
                break;
                /* Done with options.*/

                default:
                /* Something else: unexpected.*/
                abort ();
            }

        }
        while (next_option != -1);

    /* Done with options. OPTIND points to first nonoption argument.
    For demonstration purposes, print them if the verbose option was
    specified. */

    if (verbose) {
        int i;

        for (i = optind; i < argc; ++i)
            printf ("Argument: %s\n", argv[i]);
    }

    /* The main program goes here.*/

    return 0;
}



/*
-   Each time you call getopt_long , it parses a single option, returning the short-
option letter for that option, or –1 if no more options are found.

-   Typically, you’ll call getopt_long in a loop, to process all the options the user has
specified, and you’ll handle the specific options in a switch statement.

-   If getopt_long encounters an invalid option (an option that you didn’t specify as a valid short
or long option), it prints an error message and returns the character ? (a question mark). Most
programs will exit in response to this, possibly after displaying usage information.

-   When handling an option that takes an argument, the global variable optarg points to
the text of that argument.

-   After getopt_long has finished parsing all the options, the global variable optind contains the
index (into argv ) of the first nonoption argument.
*/