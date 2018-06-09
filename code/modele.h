#ifndef __MODELE__
#define __MODELE__


#include "list.h"

/**
@struct Modele_t
*/
typedef struct{

	void *value;

}Modele_t;

/**
@fn Modele_t *creer_modele(void)
@brief create the modele
@post modele created
@return a Modele_t pointer
*/
Modele_t *creer_modele(void);

/**
@fn void destroy_modele(Modele_t *m)
@brief destroy the modele
@pre m != NULL
@post modele destroy
*/
void destroy_modele(Modele_t *m);

#endif
