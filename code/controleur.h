#ifndef __CONTROLEUR__
#define __CONTROLEUR__

#include <gtk/gtk.h>
#include "modele.h"
#include "vue.h"

/**
@struct Controleur_t
*/
typedef struct{

	Vue_t *v; /*!< the vue of the app */
	Modele_t *m; /*!< the modele of the app */
	GtkWidget *spinSrcBase;
	GtkWidget *entryNumber;
	GtkWidget *buttonConvert;
	GtkWidget *buttonQuit;
	GtkWidget *buttonNumericNumber[MAX_BASE];
	GtkWidget *buttonClearNumericNumber;
	GtkWidget *checkButtonSignedMode;
	GtkWidget *checkButtonFloatMode;

}Controleur_t;

/**
@fn Controleur_t *creer_controleur(Vue_t *v, Modele_t *m)
@brief create the controleur
@param v the vue
@param m the modele
@pre v != NULL, m != NULL
@post controleur created
@return a Controleur_t pointer
*/
Controleur_t *creer_controleur(Vue_t *v, Modele_t *m);

/**
@fn void destroy_controleur(Controleur_t *c)
@brief destroy the controleur
@param c the controleur
@param m the modele
@pre c != NULL
@post controleur destroyed
*/
void destroy_controleur(Controleur_t *c);

void convert(GtkWidget *w, gpointer pData);
void select_base(GtkWidget *w, gpointer pData);
void activate_numeric_button(GtkWidget *w, gpointer pData);
void clear_numeric(GtkWidget *w, gpointer pData);
void disable_part_of_numeric(GtkWidget *w, gpointer pData);
void able_disable_clear(GtkWidget *w, gpointer pData);



#endif
