#include <stdio.h>
#include "htab.h"


int main() {
    htab_t * ht = htab_init(10);
    htab_free(ht);
    return 0;
}