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
    htab_lookup_add(ht, "function2");
    
    htab_print(ht);

    htab_pair_t *pair = htab_find(ht, "cat");
    pair->value++;

    printf("Items count: %ld, Size of a table: %ld", htab_items_count(ht), htab_size(ht));

    htab_resize(ht, htab_size(ht) + 5);

    htab_erase(ht, "song");

    htab_print(ht);

    htab_clear(ht);
    
    htab_free(ht);
    return 0;
}