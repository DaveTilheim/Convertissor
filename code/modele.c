#include <gtk/gtk.h>
#include "modele.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "list.h"

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




