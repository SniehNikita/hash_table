#include <stdio.h>
#include "htab.h"


int main() {
    htab_t * ht = htab_init(10);
    htab_pair_t *p = htab_lookup_add(ht, "cat");
    p->value = 10;
    htab_print(ht);
    htab_free(ht);
    return 0;
}