#ifndef __VUE__
#define __VUE__

#include <gtk/gtk.h>
#include "modele.h"

/**
@struct Vue_t
*/
typedef struct{

	Modele_t *m; /*!< the modele of the app */
	GtkWidget *window;
	GtkWidget *vboxWidget;
	GtkWidget *hboxWidget;
	GtkWidget *vboxAll;
	GtkWidget *labelSrc;
	GtkWidget *labelNumber;
	GtkWidget *labelError;
	GtkWidget *hboxResult;
	GtkWidget *vboxBase[3];
	GtkWidget *labelResult[MAX_BASE-1];
	GtkWidget *labelBase[MAX_BASE-1];
	
}Vue_t;

/**
@fn Vue_t *creer_vue(Modele_t *m)
@brief create the vue
@param m the modele
@pre m != NULL
@post vue created
@return a Vue_t pointer
*/
Vue_t *creer_vue(Modele_t *m);

/**
@fn void destroy_vue(Vue_t *v)
@brief destroy the vue
@param v the vue of the app
@pre v != NULL
@post vue destroy
*/
void destroy_vue(Vue_t *v);

void set_message(Vue_t *v, char *message);
void set_result(Vue_t *v, unsigned base, char *result);

#endif
