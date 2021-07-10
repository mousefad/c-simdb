#include "simdb.h"

int main(int argc, char** argv)
{
    // Send debug to stderr
    // prog-id from binary name
    // debug level db_3
    // color output
    db_init(stderr, argv[0], db_3, 1);

    db(db_i, "library version: %d.%d\n", simple_c_debugging_VERSION_MAJOR, simple_c_debugging_VERSION_MINOR);
    db(db_5, "this is debug level %d\n", 5); // won't print - level below db_3 
    db(db_4, "this is debug level %d\n", 4); // won't print - level below db_3
    db(db_3, "this is debug level %d\n", 3);
    db(db_2, "this is debug level %d\n", 2);
    db(db_1, "this is debug level %d\n", 1);
    db(db_i, "this is info\n");
    db(db_w, "this is warning\n");
    db(db_e, "this is an >%14s<\n", "error");
    db(db_f, "this is %.3f fatal\n", 3.1415926); // calls exit(EXIT_FAILURE)
    return 0;  // we won't reach this line because of the fatal error
}

