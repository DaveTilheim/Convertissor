#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "modele.h"
#include "vue.h"
#include "controleur.h"
#include "list.h"
#include "util-gtk.h"



Controleur_t *creer_controleur(Vue_t *v, Modele_t *m){

	assert(v != NULL && m != NULL);

	Controleur_t *c = malloc(sizeof(Controleur_t));
	if(c == NULL)
		return NULL;
	c->m = m;
	c->v = v;

	return c;
}

void destroy_controleur(Controleur_t *c){

	assert(c != NULL);

	free(c);
}


