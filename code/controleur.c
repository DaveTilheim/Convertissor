#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "modele.h"
#include "vue.h"
#include "controleur.h"
#include "list.h"
#include "util-gtk.h"

#define MAXC 10

Controleur_t *creer_controleur(Vue_t *v, Modele_t *m){

	assert(v != NULL && m != NULL);

	Controleur_t *c = malloc(sizeof(Controleur_t));
	if(c == NULL)
		return NULL;
	c->m = m;
	c->v = v;
	c->spinBase[0] = gtk_spin_button_new_with_range(2, 16, 1);
	c->spinBase[1] = gtk_spin_button_new_with_range(2, 16, 1);
	c->entryNumber = gtk_entry_new_with_max_length(MAXC);
	c->checkButtonMode[0] = gtk_check_button_new_with_label("non signé");
	c->checkButtonMode[1] = gtk_check_button_new_with_label("complément à 1");
	c->checkButtonMode[2] = gtk_check_button_new_with_label("complément à 2");
	c->checkButtonMode[3] = gtk_check_button_new_with_label("IEEE754");
	c->buttonConfirm = gtk_button_new_with_label("convertir");

	return c;
}

void destroy_controleur(Controleur_t *c){

	assert(c != NULL);

	free(c);
}


