#include <gtk/gtk.h>
#include "modele.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>


Modele_t *creer_modele(void){

	Modele_t *m = malloc(sizeof(Modele_t));
	if(m == NULL)
		return NULL;
	m->baseDest = MIN_BASE;
	m->baseSrc = MIN_BASE;

	return m;
}

void set_bases(Modele_t *m, unsigned srcv, unsigned destv){
	m->baseSrc = srcv;
	m->baseDest = destv;
}

int number_error(char *number){
	if(!strlen(number)) return 1;
	for(int i = 0; i < strlen(number); i++)
		if(number[i] == ' ') return 2;
	return 0;
}

int set_number(Modele_t *m, char *number){
	for(int i = 0; i < strlen(number); i++){
		int exists = 0;
		for(int j = 0; j < m->baseSrc; j++)
			if(number[i] == BASE36A[j] || number[i] == BASE36B[j]){
				exists = 1;
				break;
			}
		if(!exists) return 0;
	}
	strcpy(m->numberToConvert, number);
	return 1;
}

static unsigned short get_position_from_char_base(char c, unsigned short baseSrc){
	for(unsigned short i = 0; i < baseSrc; i++)
		if(BASE36A[i] == c || BASE36B[i] == c) return i;
	return 0;
}

static unsigned long get_base10_from_number_to_convert(Modele_t *m){
	unsigned short len = strlen(m->numberToConvert);
	unsigned long numb10 = 0;
	int pos = 0;
	for(int i = len-1; i >= 0; i--){
		unsigned short position = get_position_from_char_base(m->numberToConvert[i], m->baseSrc);
		numb10 += position * pow(m->baseSrc, pos);
		pos++;
	}
	return numb10;
}

static void set_char_final_number(Modele_t *m, int k){
	char new[2];
	new[0]='0'+k;
	if(k>MAX_BASE) return;
	if(k >= 0 && k <= 9) strcat(m->numberConvert, new);
	if(k > 9){
		new[0] = 'A'+k-10;
		strcat(m->numberConvert, new);
	}
	printf("%s\n", m->numberConvert);

}

static void base10_to_base_dest(Modele_t *m, unsigned long numb10){
	strcpy(m->numberConvert, "");
	unsigned short exp = 0;
	while(pow(m->baseDest, exp) <= numb10) exp++; exp--;
	for(int i = exp; i >= 0; i--){
		unsigned long value = pow(m->baseDest, i);
		int k;
		for(k = 0; ; k++)
			if(value*k > numb10) break;
		numb10 -= value*(k-1);
		set_char_final_number(m, k-1);
	}
}

int run_convertion(Modele_t *m){
	unsigned long numb10 = get_base10_from_number_to_convert(m);
	base10_to_base_dest(m, numb10);
	return 1;
}

void destroy_modele(Modele_t *m){
	
	assert(m != NULL);

	free(m);
}




