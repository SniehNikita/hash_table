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



htab_item_t * htab_find_item(htab_t * t, htab_key_t key) {
    htab_item_t *item;

    item = t->arr_ptr[htab_hash_function(key) % (t->arr_size)];
    if (item == NULL) {
        return NULL;
    }

    while (item->pair.key != key && item->next != NULL) {
        item = item->next;
    }

    if (item->pair.key == key) {
        return item;
    }
    
    return NULL;
}



htab_pair_t * htab_find(htab_t * t, htab_key_t key) {
    htab_item_t *item;

    item = htab_find_item(t, key);
    
    if (item != NULL) {
        return &item->pair;
    }

    return NULL;
}



size_t htab_items_count(const htab_t * t) {
    return t->size;
}



size_t htab_length(const htab_t * t) {
    return t->arr_size;
}



void htab_print(htab_t * t) {
    printf("array size: %ld\nelements count: %ld\n", t->arr_size, t->size);
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *item = t->arr_ptr[i]; 
        while (item != NULL) {
            printf("[\"%s\": %d]->", item->pair.key, item->pair.value);
            item = item->next;
        }
        printf("NULL\n");
    }
}



htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {
    htab_item_t *item;
    
    item = htab_find_item(t, key);

    if (item != NULL) {
        return &item->pair;
    }    

    if ( (t->size + 1) / t->arr_size > MAX_SPACE_TAKEN) {
        // TODO
    }

    if ((item = (htab_item_t *) malloc(sizeof(htab_item_t))) == NULL) {
        // TODO Memory alloc error
        return NULL;
    }
    item->pair.key = key;
    item->pair.value = 0;

    item->next = t->arr_ptr[htab_hash_function(key) % (t->arr_size)];
    t->arr_ptr[htab_hash_function(key) % (t->arr_size)] = item;

    t->size++;

    return &item->pair;
}



void * htab_resize(htab_t *t, size_t n) {
     if (n < 1) {
        // TODO Bad size of array error
        return NULL;
    }

    htab_item_t **new_arr_ptr;
    if ((new_arr_ptr = (htab_item_t **) malloc(n * sizeof(htab_item_t *))) == NULL) {
        // TODO Memory alloc error
        return NULL;
    }

    // NULLs every pointer in elements
    for (size_t i = 0; i < n; i++) {
        new_arr_ptr[i] = NULL;
    }

    htab_item_t *item;
    for (size_t i = 0; i < t->arr_size; i++) {
        item = t->arr_ptr[i];
        while(item != NULL) {
            htab_item_t *tmp;
            tmp = item->next;
            item->next = new_arr_ptr[htab_hash_function(item->pair.key) % n];
            new_arr_ptr[htab_hash_function(item->pair.key) % n] = item;
            item = tmp;
        }
    }

    // Free array
    free(t->arr_ptr);
    t->arr_ptr = new_arr_ptr;

    t->arr_size = n;

    return (void *)0;
}