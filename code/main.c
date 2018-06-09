#include "modele.h"	
#include "vue.h"
#include "controleur.h"



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

	
	gtk_widget_show_all(v->window);

	

	gtk_main();




	destroy_modele(m);
	destroy_vue(v);
	destroy_controleur(c);

	return 0;
}
