//------------------------------------------
//	author	: SniehNikita
//	github	: https://github.com/SniehNikita
//	date	: 01.10.2022
//	
//	!!! Built and tested in Linux !!!
//
//------------------------------------------



#include "htab.h"
#include <stdint.h>
#include <string.h>

size_t htab_hash_function(const char *str) {
    uint32_t h=0;     // musí mít 32 bitů

    for (size_t i = 0; i < strlen(str); i++) {
        h = h*58293 + (int)str[i];
    }

    h = h*58293;

    return h;
}