#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>
#include "layout.h"

int main(int argc, char *argv[])
{
    if ( argc == 1 ) {
        printf("give some path\n");
        return 1;
    }

    PMEMobjpool *pop = pmemobj_create(argv[1], LAYOUT_NAME, PMEMOBJ_MIN_POOL, 0666);
    if ( pop == NULL ) {
        perror("pmemobj_create");
        return 1;
    }

    char buf[MAX_BUF_LEN] = "nice try..";

    strcpy(pop, buf);

    pmemobj_close(pop);

    return 0;
}
