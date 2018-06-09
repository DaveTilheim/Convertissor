#include <gtk/gtk.h>
#include "modele.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include "list.h"
#include "itoa.h"

Modele_t *creer_modele(void){

	Modele_t *m = malloc(sizeof(Modele_t));
	if(m == NULL)
		return NULL;

	return m;
}

void destroy_modele(Modele_t *m){
	
	assert(m != NULL);

	free(m);
}

inline void set_entry_base(Modele_t *m, unsigned short base){

	m->baseEntry = base;
}

inline void set_dest_base(Modele_t *m, unsigned short base){

	m->baseDest = base;
}

static int check_entry_number(Modele_t *m ,char *number){

	char *index = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < strlen(number); i++){
		for(int j = 0; j < strlen(index); j++){
			if(number[i] == index[j])
				break;
			else if(j == strlen(index)-1)
				return 0;
		}
	}
	char limit = '0';
	for(int i = 1; i < m->baseEntry; ++i){
		limit++;
		if(limit == ':')
			limit = 'A';
	}
	
	for(int i = 0; i < strlen(number); ++i){
		if(number[i] >= 'A' && number[i] <= 'Z'){
			if(number[i] > limit)
				return 0;
		}
		else if(number[i] >= 'a' && number[i] <= 'z'){
			if(number[i] > limit+32)
				return 0;
		}
		else{
			if(number[i] > limit)
				return 0;
		}
	}

	return 1;
}

int set_entry_number(Modele_t *m, char *number){

	if(!check_entry_number(m, number))
		return 0;
	strcpy(m->entryNumber, number);

	return 1;
}


static int convert_base10(Modele_t *m){

	char *index = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int result = 0;
	int factor = 0;
	if(m->baseEntry == 10){
		result = atoi(m->entryNumber);
		itoa(result, m->result);
		return 1;
	}
	for(int i = strlen(m->entryNumber)-1; i >= 0; i--){
		for(int j = 0; j < strlen(index); j++){
			if(m->entryNumber[i] == index[j] || m->entryNumber[i] == index[j]+32){
				result += j*pow(m->baseEntry, factor);
				break;
			}
		}
		factor++;
	}
	if(result < 0)
		return 0;
	itoa(result, m->result);
	return 1;
	
}


static void incr_str(Modele_t *m, char *str, int i, char *index){
	
	
	if(str[i] != index[m->baseDest]-1){
		str[i]++;
		if(m->baseDest > 10){
			if(str[i] == ':')
				str[i] = 'A';
		}
		return;
	}
	str[i] = '0';
	
	incr_str(m, str, i-1, index);
	
}

static void convert_base10_basex(Modele_t *m){

	if(m->baseDest == 10){
		return;
	}

	char *index = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int res = atoi(m->result);
	char new[MAXC_R*2+1];
	strcpy(new,"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	int i = strlen(new)-1;
	while(res > 0){
		incr_str(m, new, i, index);
		res--;
	}

	int end = 0;
	int oc = 0;
	for(int i = 0; i < strlen(new); i++){
		if(end == 0 && new[i] == '0'){
			continue;
		}
		end = 1;
		m->result[oc] = new[i];
		oc++;
	}
	m->result[oc] = '\0';
	
}

int operation(Modele_t *m){

	if(!convert_base10(m))
		return 0;
	convert_base10_basex(m);

	return 1;
}






