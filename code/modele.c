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
	int size = strlen(number);
	if(!size) return 1;
	int no0 = 0;
	for(int i = 0; i < size; i++){
		if(number[i] != '0') no0 = 1;
		if(number[i] == ' ') return 2;
	}
	if(!no0) return 3;
	return 0;
}

int set_number(Modele_t *m, char *number){
	int size = strlen(number);
	for(int i = 0; i < size; i++){
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
	unsigned short size = strlen(m->numberToConvert);
	unsigned long numb10 = 0;
	int pos = 0;
	for(int i = size-1; i >= 0; i--){
		unsigned short position = get_position_from_char_base(m->numberToConvert[i], m->baseSrc);
		numb10 += position * pow(m->baseSrc, pos);
		pos++;
	}
	return numb10;
}

static void reverse_number(Modele_t *m){
	unsigned short size = strlen(m->numberConvert);
	char newNumber[MAX_BIT-1];
	int i ; 
	for(i = 0; i < size; i++)
		newNumber[i] = m->numberConvert[size-1-i];
	newNumber[i] = '\0';
	strcpy(m->numberConvert, newNumber);
}

static void set_char_final_number(Modele_t *m, int k){
	char new[2];
	if(k>MAX_BASE) return;
	if(k >= 0 && k <= 9){
		new[0]='0'+k;
		strcat(m->numberConvert, new);
	}
	else{
		new[0] = 'A'+k-10;
		strcat(m->numberConvert, new);
	}
}

static void base10_to_base_dest(Modele_t *m, unsigned long numb10){
	strcpy(m->numberConvert, "");
	while(numb10 > 0){
		set_char_final_number(m, numb10%m->baseDest);
		numb10 /= m->baseDest;
	}
	reverse_number(m);
}

int run_convertion(Modele_t *m){
	unsigned long numb10 = get_base10_from_number_to_convert(m);
	base10_to_base_dest(m, numb10);
	return 1;
}

void set_char_number(Modele_t *m, char *c){
	if(strlen(m->numberToConvert)+1 >= MAX_BIT-1) return;
	strcat(m->numberToConvert, c);
}


void destroy_modele(Modele_t *m){
	
	assert(m != NULL);

	free(m);
}




