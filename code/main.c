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

	gtk_table_attach(GTK_TABLE(v->tableBase), v->labelBase[0], 0, 1, 0,1, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->spinBase[0], 1,2, 0,1, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), v->labelBase[1], 2,3, 0,1, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->spinBase[1], 3,4, 0,1, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), v->labelEntryNumber, 0,2, 1,2, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->entryNumber, 2,4, 1,2, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->checkButtonMode[0], 0,1, 2,3, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->checkButtonMode[1], 1,2, 2,3, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->checkButtonMode[2], 2,3, 2,3, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->checkButtonMode[3], 3,4, 2,3, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), c->buttonConfirm, 0,4, 3,4, FALSE, FALSE, 5,5);
	gtk_table_attach(GTK_TABLE(v->tableBase), v->labelResult, 0,4, 4,5, FALSE, FALSE, 5,5);

	fill_box(v->vboxAll, 1, v->tableBase);
	gtk_container_add(GTK_CONTAINER(v->window), v->vboxAll);
	gtk_widget_show_all(v->window);

	

	gtk_main();




	destroy_modele(m);
	destroy_vue(v);
	destroy_controleur(c);

	return 0;
}
