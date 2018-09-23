#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "modele.h"
#include "vue.h"
#include "controleur.h"
#include "util-gtk.h"



Controleur_t *creer_controleur(Vue_t *v, Modele_t *m){

	assert(v != NULL && m != NULL);

	Controleur_t *c = malloc(sizeof(Controleur_t));
	if(c == NULL)
		return NULL;
	c->m = m;
	c->v = v;
	c->spinSrcBase = gtk_spin_button_new_with_range((float)MIN_BASE, (float)MAX_BASE, 1.0);
	c->entryNumber = gtk_entry_new_with_max_length(MAX_BIT);
	c->buttonConvert = gtk_button_new_with_label("convert");
	c->buttonQuit = gtk_button_new_with_label("QUIT");


	return c;
}

void convert(GtkWidget *w, gpointer pData){
	Controleur_t *c = (Controleur_t *) pData;
	unsigned srcv = (unsigned)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(c->spinSrcBase));
	char number[MAX_BIT+1];
	strcpy(number, (char *)gtk_entry_get_text(GTK_ENTRY(c->entryNumber)));
	set_bases(c->m, srcv, 0);
	switch(number_error(number)){
		case 1:
			set_message(c->v, "no number in the number field");
			return;
		case 2:
			set_message(c->v, "space in the number field");
			return;

		default:
			break;
	}
	if(!set_number(c->m, number)){
		set_message(c->v, "bad value for the src base");
		return;
	}
	for(int base = 2; base <= MAX_BASE; base++){
		set_bases(c->m, srcv, base);
		run_convertion(c->m);
		set_result(c->v, base, c->m->numberConvert);
	}
}

void select_base(GtkWidget *w, gpointer pData){
	Controleur_t *c = (Controleur_t *) pData;
	set_message(c->v, (char*)gtk_button_get_label(GTK_BUTTON(w)));
}

void destroy_controleur(Controleur_t *c){

	assert(c != NULL);

	free(c);
}


