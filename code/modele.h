#ifndef __MODELE__
#define __MODELE__



#define MAXC 10
#define MAXC_R 100
/**
@struct Modele_t
*/
typedef struct{

	unsigned short baseEntry;
	unsigned short baseDest;
	char entryNumber[MAXC+1];
	char result[MAXC_R*2+1];

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

void set_entry_base(Modele_t *m, unsigned short base);

void set_dest_base(Modele_t *m, unsigned short base);

int set_entry_number(Modele_t *m, char *number);

int operation(Modele_t *m);


#endif
