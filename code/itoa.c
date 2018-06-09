#include "itoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void itoa(unsigned int number, char *str){

	int cptr = 0;
	int saveNumber = number;
	while(number > 0){
		number /= 10;
		cptr++;
	}
	cptr++;

	int i = 0;
	while(i < cptr-1){
		str[i] = '0'+(saveNumber/pow(10, cptr-2-i));
		saveNumber-= (str[i]-'0')*pow(10, cptr-2-i);
		i++;
	}
	str[i] = '\0';

}
