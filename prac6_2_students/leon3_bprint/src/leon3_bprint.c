#include "leon3_bprint.h"
#include "leon3_uart.h"

int8_t leon3_print_string(char* str)
{
	int i = 0;
	while(str [i] != '\0'){
		leon3_putchar(str[i]);
		i++;
	}
	return leon3_uart_tx_fifo_is_empty();
}

int8_t leon3_print_uint8(uint8_t i)
{
	if(i/10 == 0){
		char unidad = i + '0';
		leon3_putchar(unidad);
	}
	else{
		if(i/10 < 10){
			char unidad = (i%10) + '0';
			char decena = (i/10) + '0';
			leon3_putchar(unidad);
			leon3_putchar(decena);
		}
		else{
			char unidad = (i%10) + '0';
			char centena = (i/100) + '0';
			int num = (i%100);
			char decena = (num/10) + '0';
			leon3_putchar(unidad);
			leon3_putchar(decena);
			leon3_putchar(centena);
		}

	}

	return leon3_uart_tx_fifo_is_empty();
}

int8_t leon3_print_uint32(uint32_t i)
{
	int8_t error=0;
	uint32_t aux;
	int8_t first_digit=0;

	aux=1000000000;

	if(i==0)
		leon3_putchar('0');
	else{
		while(i && (!error)){
			uint8_t digit;

			digit=i/aux;

			i -= aux*digit;

			aux = aux/10;
			if(first_digit || digit){
				error = leon3_putchar('0' + digit);
				first_digit = 1;
			}
		}
	}
	return error;
}
