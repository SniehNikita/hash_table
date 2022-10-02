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
    
    htab_erase(ht, "function2");
    htab_erase(ht, "function");
    htab_erase(ht, "cpp");
    htab_erase(ht, "htable");
    htab_erase(ht, "net");

    htab_print(ht);
    
    htab_free(ht);
    return 0;
}