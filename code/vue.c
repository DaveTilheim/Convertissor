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
	v->vboxAll = gtk_vbox_new(FALSE, 0);
	v->vboxWidget = gtk_vbox_new(TRUE, 5);
	v->hboxWidget = gtk_hbox_new(FALSE, 0);
	v->labelSrc = gtk_radio_button_new_with_label(NULL, "base of the initial value\nmin 2\nmax 36");
	v->labelNumber = gtk_radio_button_new_with_label(NULL, "value to convert");
	v->labelError = gtk_label_new("no error");
	v->hboxResult = gtk_hbox_new(TRUE, 3);
	for(int i = 0; i < 3; i++) v->vboxBase[i] = gtk_vbox_new(TRUE, 3);
	for(int i = 0; i < MAX_BASE-1; i++){
		char base[7+1] = "base ";
		base[5] = '0'+i+2;
		if(i+2 > 9){
			base[5] = '0'+(i+2)/10;
			base[6] = '0'+(i+2)%10;
		}
		v->labelBase[i] = gtk_radio_button_new_with_label(NULL, base);
		v->labelResult[i] = gtk_button_new_with_label("result here");
		if(i < 12) fill_box(v->vboxBase[0], 2, v->labelBase[i], v->labelResult[i]);
		else if(i < 24) fill_box(v->vboxBase[1], 2, v->labelBase[i], v->labelResult[i]);
		else fill_box(v->vboxBase[2], 2, v->labelBase[i], v->labelResult[i]);
	}
	fill_box(v->hboxResult, 3, v->vboxBase[0], v->vboxBase[1], v->vboxBase[2]);
	v->hboxNumericNumber = gtk_hbox_new(FALSE, 0);
	for(int i = 0; i < 6; i++) v->vboxNumericNumber[i] = gtk_vbox_new(FALSE, 0);



	return v;
}

void set_message(Vue_t *v, char *message){
	gtk_label_set_text(GTK_LABEL(v->labelError), message);
}

void set_result(Vue_t *v, unsigned base, char *result){
	gtk_button_set_label(GTK_BUTTON(v->labelResult[base-2]), result);
}

void destroy_vue(Vue_t *v){

	assert(v != NULL);

	free(v);
}


