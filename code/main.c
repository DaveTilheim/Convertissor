#include "modele.h"	
#include "vue.h"
#include "controleur.h"
#include "util-gtk.h"


int main(int argc, char **argv){

	gtk_init(&argc, &argv);

	Modele_t *m = creer_modele();
	if(!m){
		fprintf(stderr, "ERROR\n");
		return -1;
	}
	Vue_t *v = creer_vue(m);
	if(!v){
		fprintf(stderr, "ERROR\n");
		destroy_modele(m);
		return -1;
	}
	Controleur_t *c = creer_controleur(v, m);
	if(!c){
		fprintf(stderr, "ERROR\n");
		destroy_modele(m);
		destroy_vue(v);
		return -1;
	}

	g_signal_connect(G_OBJECT(c->buttonConvert), "clicked", G_CALLBACK(convert), c);
	g_signal_connect(G_OBJECT(c->buttonQuit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	for(int i = 0; i < MAX_BASE-1; i++) g_signal_connect(G_OBJECT(v->labelResult[i]), "clicked", G_CALLBACK(select_base), c);
	fill_box(v->vboxWidget, 4, v->labelSrc, c->spinSrcBase,
	v->labelNumber, c->entryNumber);
	fill_box(v->hboxWidget, 3, v->vboxWidget, gtk_vseparator_new(), v->hboxResult);
	fill_box(v->vboxAll, 5, v->hboxWidget, gtk_hseparator_new(), c->buttonConvert, v->labelError, c->buttonQuit);
	gtk_container_add(GTK_CONTAINER(v->window), v->vboxAll);
	gtk_widget_show_all(v->window);

	

	gtk_main();




	destroy_modele(m);
	destroy_vue(v);
	destroy_controleur(c);

	return 0;
}
