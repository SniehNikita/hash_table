//------------------------------------------
//	author	: SniehNikita
//	github	: https://github.com/SniehNikita
//	date	: 01.10.2022
//	
//	!!! Built and tested in Linux !!!
//
//------------------------------------------



#ifndef __HTAB_H__
#define __HTAB_H__



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 


// Key type
typedef const char * htab_key_t;
// Value type
typedef int htab_value_t;

typedef struct htab_pair {
    htab_key_t    key;
    htab_value_t  value;
} htab_pair_t; 

struct htab;
typedef struct htab htab_t;


// Returns hash of the key
size_t htab_hash_function(htab_key_t str);

// Inicialization of a table
htab_t * htab_init(size_t n);

// Returns total number of items
size_t htab_items_count(const htab_t * t);

// Returns size of array
size_t htab_length(const htab_t * t);

// Increases / decreases size of t
void * htab_resize(htab_t *t, size_t n);

// Destructs key-value pair. Returns false if not found
bool htab_erase(htab_t * t, htab_key_t key);

// Returns pointer to the key-value pair in t, NULL if not found
htab_pair_t * htab_find(htab_t * t, htab_key_t key);

// Returns pointer to the key-value pair in t, adds new key-value pair if not found
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);

// Deletes all elements
void htab_clear(htab_t * t);

// Table destructor
void htab_free(htab_t * t);

// Copies table
htab_t * htab_copy(htab_t t);

// Prints table
void htab_print(htab_t * t);



#endif