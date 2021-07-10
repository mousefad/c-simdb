#include <unistd.h>
#include <stdlib.h>
#include "simdb.h"

void usage(int e)
{
    fprintf(e ? stderr : stdout,
            "Usage:\n\n"
            "  %s [options]\n\n"
            "Options:\n"
            "-c : suppress use of color\n"
            "-d : increase debugging output verbosity (may be provided more than once)\n"
            "-t : use 'T' instead of space to separate date and time in timestamp\n"
            "-u : use UTC instead of localtime for timestamps\n",
            db_prog_name);
    exit(e);
}

int main(int argc, char** argv)
{
    db_init_opt_t options = 0;
    int d_flag = 0;
    int h_flag = -1;
    int c;
    opterr = 0;
    while ((c = getopt (argc, argv, "cdhtu")) != -1) {
        switch (c) {
        case 'c':
            options |= DB_NO_COLOR;
            break;
        case 'd':
            ++d_flag;
            break;
        case 'h':
            h_flag = EXIT_SUCCESS;
            break;
        case 't':
            options |= DB_USE_T_FMT;
            break;
        case 'u':
            options |= DB_UTC;
            break;
        default:
            h_flag = EXIT_FAILURE;
        }
    }

    // we need to do this before printing the usage message so that we have access
    // to db_prog_name, which is the basename of the program binary path, hence the
    // schnanegans with h_flag getting initialized to -1
    db_init(stderr, argv[0], db_i, options);
    if (h_flag != -1) {
        usage(h_flag);
    }
    // for every time -d was specified, increase debug verbosity by 1 *to to db_5
    while(d_flag-- > 0) db_inc_level(db_i);

    db(db_5, "this is debug level %d\n", 5);
    db(db_4, "this is debug level %d\n", 4);
    db(db_3, "this is debug level %d\n", 3);
    db(db_2, "this is debug level %d\n", 2);
    db(db_1, "this is debug level %d\n", 1);
    db(db_i,
       "libsimdb version: %d.%d\n",
       simple_c_debugging_VERSION_MAJOR,
       simple_c_debugging_VERSION_MINOR);
    db(db_w, "this is a warning\n");
    db(db_e, "this is an >%14s<\n", "error");
    db(db_f, "this is fatal error with param %.3f\n", 3.1415926); // calls exit(EXIT_FAILURE)
    return 0;  // we won't reach this line because of the fatal error
}

