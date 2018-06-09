#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "vue.h"
#include "modele.h"
#include "controleur.h"
#include "list.h"
#include "util-gtk.h"


Vue_t *creer_vue(Modele_t *m){

	assert(m != NULL);

	Vue_t *v = malloc(sizeof(Vue_t));
	if(v == NULL)
		return NULL;

	v->m = m;
	
	return v;
}

void destroy_vue(Vue_t *v){

	assert(v != NULL);

	free(v);
}


