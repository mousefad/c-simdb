#include "db.h"
#include "second.h"

void second()
{
    db(db_i, "This is function: %s\n", __func__);
}
