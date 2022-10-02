//------------------------------------------
//	author	: SniehNikita
//	github	: https://github.com/SniehNikita
//	date	: 01.10.2022
//	
//	!!! Built and tested in Linux !!!
//
//------------------------------------------



#include "htab.h"

struct htab_item;
typedef struct htab_item htab_item_t;


struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
}; 

struct htab_item {
    htab_pair_t pair;
    htab_item_t *next;
};


htab_t * htab_init(size_t n) {
    if (n < 1) {
        // TODO Bad size of array
        return NULL;
    }

    htab_t *ht;
    
    if ((ht = (htab_t *) malloc(sizeof(htab_t))) == NULL) {
        // TODO Memory alloc error
        return NULL;
    }

    ht->size = 0;
    ht->arr_size = n;

    if ((ht->arr_ptr = (htab_item_t **) malloc(n * sizeof(htab_item_t *))) == NULL) {
        // TODO Memory alloc error
        return NULL;
    }

    // NULLs every pointer in elements
    for (size_t i = 0; i < ht->arr_size; i++) {
        ht->arr_ptr[i] = NULL;
    }

    return ht;
}


// htab pointer
// pointer to the array
// pointer to each elements
void htab_free(htab_t * t) {
    htab_item_t *p = NULL;
    htab_item_t *pd = NULL;

    // Free each element in the array
    for (size_t i = 0; i < t->arr_size; i++) {        
        p = t->arr_ptr[i];
        while (p != NULL) {
            pd = p;
            p = p->next;
            free(pd);
            pd = NULL;
        }
        t->arr_ptr[i] = NULL;
    }

    // Free array
    free(t->arr_ptr);
    t->arr_ptr = NULL;

    t->arr_size = 0;
    t->size = 0;
    // Free pointer
    free(t);
    t = NULL;
}