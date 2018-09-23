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
	g_signal_connect(G_OBJECT(c->spinSrcBase), "value-changed", G_CALLBACK(disable_part_of_numeric), c);
	c->entryNumber = gtk_entry_new_with_max_length(MAX_BIT);
	g_signal_connect(G_OBJECT(c->entryNumber), "activate", G_CALLBACK(able_disable_clear), c);
	c->buttonConvert = gtk_button_new_with_label("convert");
	c->buttonQuit = gtk_button_new_with_label("QUIT");
	for(int i = 0; i < MAX_BASE; i++){
		char label[2];
		if(i < 10) label[0] = '0'+i;
		else label[0] = 'A'+i-10;
		label[1] = '\0';
		c->buttonNumericNumber[i] = gtk_button_new_with_label(label);
		if(i != 0 && i != 1) gtk_widget_set_sensitive(c->buttonNumericNumber[i], FALSE);
		g_signal_connect(G_OBJECT(c->buttonNumericNumber[i]), "clicked", G_CALLBACK(activate_numeric_button), c);
	}
	int n = 0;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++)
			fill_box(c->v->vboxNumericNumber[i], 1, c->buttonNumericNumber[n++]);
		fill_box(c->v->hboxNumericNumber, 1, c->v->vboxNumericNumber[i]);
	}
	c->buttonClearNumericNumber = gtk_button_new_with_label("clear");
	g_signal_connect(G_OBJECT(c->buttonClearNumericNumber), "clicked", G_CALLBACK(clear_numeric), c);
	fill_box(c->v->hboxNumericNumber, 1, c->buttonClearNumericNumber);
	gtk_widget_set_sensitive(c->buttonClearNumericNumber, FALSE);

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
			fprintf(stderr, "\a");
			return;
		case 2:
			set_message(c->v, "space in the number field");
			fprintf(stderr, "\a");
			return;
		case 3:
			set_message(c->v, "put a number");
			fprintf(stderr, "\a");
			return;
		default:
			break;
	}
	if(!set_number(c->m, number)){
		set_message(c->v, "bad value for the src base");
		fprintf(stderr, "\a");
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

void activate_numeric_button(GtkWidget *w, gpointer pData){
	Controleur_t *c = (Controleur_t *) pData;
	gtk_widget_set_sensitive(c->buttonClearNumericNumber, TRUE);
	set_char_number(c->m, (char *)gtk_button_get_label(GTK_BUTTON(w)));
	gtk_entry_set_text(GTK_ENTRY(c->entryNumber), c->m->numberToConvert);
}

void clear_numeric(GtkWidget *w, gpointer pData){
	Controleur_t *c = (Controleur_t *) pData;
	strcpy(c->m->numberToConvert, "");
	gtk_entry_set_text(GTK_ENTRY(c->entryNumber), "");
	gtk_widget_set_sensitive(c->buttonClearNumericNumber, FALSE);
}

void destroy_controleur(Controleur_t *c){

	assert(c != NULL);

	free(c);
}

void disable_part_of_numeric(GtkWidget *w, gpointer pData){
	Controleur_t *c = (Controleur_t *) pData;
	unsigned stop = (unsigned)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(c->spinSrcBase));
	for(int i = 0; i < MAX_BASE; i++){
		if(i >= stop) gtk_widget_set_sensitive(c->buttonNumericNumber[i], FALSE);
		else gtk_widget_set_sensitive(c->buttonNumericNumber[i], TRUE);
	}
}

void able_disable_clear(GtkWidget *w, gpointer pData){
	Controleur_t *c = (Controleur_t *) pData;
	if(strlen((char*)gtk_entry_get_text(GTK_ENTRY(w)))<=0)
		gtk_widget_set_sensitive(c->buttonClearNumericNumber, FALSE);
	else
		gtk_widget_set_sensitive(c->buttonClearNumericNumber, TRUE);

}





