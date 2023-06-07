#ifndef LEON3_BPRINT_H
#define LEON3_BPRINT_H

#include "leon3_types.h"

//Transmite a traves del puerto serie la cadena de caracteres pasada por parametro
int8_t leon3_print_string(char* str);

//Transmite a traves del puerto serie el entero transformado en cadena de caracteres
int8_t leon3_print_uint8(uint8_t i);

int8_t leon3_print_uint32(uint32_t i);

#endif /* LEON3_PRINTB_H_*/
