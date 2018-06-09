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


void entry_base(GtkWidget *widget, gpointer pData){

	Controleur_t *c = (Controleur_t *) pData;

	set_entry_base(c->m, (unsigned short) gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(c->spinBase[0])));
	set_dest_base(c->m, (unsigned short) gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(c->spinBase[1])));
	if(!set_entry_number(c->m, (char *) gtk_entry_get_text(GTK_ENTRY(c->entryNumber)))){
		set_result_label(c->v, "error: doesn't correspond with the entry base");
		return;
	}
	operation(c->m);
}

