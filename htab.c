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