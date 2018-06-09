#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "vue.h"
#include "modele.h"
#include "list.h"
#include "util-gtk.h"


Vue_t *creer_vue(Modele_t *m){

	assert(m != NULL);

	Vue_t *v = malloc(sizeof(Vue_t));
	if(v == NULL)
		return NULL;

	v->m = m;
	v->window = create_window_with_title("Convertisseur");
	v->vboxAll = gtk_vbox_new(TRUE, 5);
	v->tableBase = gtk_table_new(5,4,TRUE);
	v->labelBase[0] = gtk_label_new("De la base ");
	v->labelBase[1] = gtk_label_new("vers la base ");
	v->labelEntryNumber = gtk_label_new("Entrez un nombre: ");
	v->labelResult = gtk_label_new("[resultat]");

	
	return v;
}


void destroy_vue(Vue_t *v){

	assert(v != NULL);

	free(v);
}

inline void set_result_label(Vue_t *v, char *str){

	gtk_label_set_text(GTK_LABEL(v->labelResult), str);
}
