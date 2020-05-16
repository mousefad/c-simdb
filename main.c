#include "db.h"
#include "second.h"

int main(int argc, char** argv)
{
    db_init(stderr, "testapp", db_3, 1);
    db(db_f, "this is %.3f fatal\n", 3.1415926);
    db(db_e, "this is an >%14s<\n", "error");
    db(db_w, "this is warning\n");
    db(db_i, "this is info\n");
    db(db_1, "this is debug level %d\n", 1);
    db(db_2, "this is debug level %d\n", 2);
    db(db_3, "this is debug level %d\n", 3);
    db(db_4, "this is debug level %d\n", 4);
    db(db_5, "this is debug level %d\n", 5);
    second();
    return 0;
}

