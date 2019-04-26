#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>
#include "layout.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("give some path\n");
        return 1;
    }

    PMEMobjpool *pop = pmemobj_open(argv[1], LAYOUT_NAME);
    if (pop == NULL) {
        perror("pmemobj_open");
        return 1;
    }

    PMEMoid root = pmemobj_root(pop, sizeof(struct my_root));
    struct my_root *rootp = pmemobj_direct(root);

    char my_buf[MAX_BUF_LEN];
    scanf("%9s", my_buf);

    rootp->len = strlen(my_buf);
    pmemobj_persist(pop, &rootp->len, sizeof(rootp->len));
    pmemobj_memcpy_persist(pop, rootp->buf, my_buf, rootp->len);

    if (rootp->len == strlen(rootp->buf))
        printf("%s\n", rootp->buf);

    pmemobj_close(pop);

    return 0;
}
