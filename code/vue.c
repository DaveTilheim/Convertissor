#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "vue.h"
#include "modele.h"
#include "controleur.h"
#include "util-gtk.h"


Vue_t *creer_vue(Modele_t *m){

	assert(m != NULL);

	Vue_t *v = malloc(sizeof(Vue_t));
	if(v == NULL)
		return NULL;

	v->window = create_window_with_title("convertissor");
	v->m = m;
	v->vboxAll = gtk_vbox_new(TRUE, 5);
	v->labelSrc = gtk_label_new("src base");
	v->labelDest = gtk_label_new("dest base");
	v->labelNumber = gtk_label_new("number to convert");
	v->labelResult = gtk_label_new("result here");
	
	return v;
}

void set_message(Vue_t *v, char *message){
	gtk_label_set_text(GTK_LABEL(v->labelResult), message);
}

void destroy_vue(Vue_t *v){

	assert(v != NULL);

	free(v);
}


