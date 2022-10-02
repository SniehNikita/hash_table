#include <stdio.h>
#include "htab.h"


int main() {
    htab_t * ht = htab_init(10);
    htab_lookup_add(ht, "cat");
    htab_lookup_add(ht, "food");
    htab_lookup_add(ht, "sky");
    htab_lookup_add(ht, "song");
    htab_lookup_add(ht, "net");
    htab_lookup_add(ht, "cpp");
    htab_lookup_add(ht, "htable");
    htab_lookup_add(ht, "function");
    htab_print(ht);
    printf("\n\n\n\n");
    htab_resize(ht, 5);
    htab_print(ht);
    printf("\n\n\n\n");
    htab_resize(ht, 20);
    htab_print(ht);
    printf("\n\n\n\n");
    htab_resize(ht, 11);
    htab_print(ht);
    printf("\n\n\n\n");
    htab_resize(ht, 50);
    htab_print(ht);
    htab_free(ht);
    return 0;
}