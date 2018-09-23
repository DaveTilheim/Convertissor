#ifndef __MODELE__
#define __MODELE__

#define MAX_VALUE 18446744073709551615
#define MAX_BIT 64
#define MAX_BASE 36
#define MIN_BASE 2
#define BASE36A "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define BASE36B "0123456789abcdefghijklmnopqrstuvwxyz"

/**
@struct Modele_t
*/
typedef struct{

	unsigned short baseSrc : 6;
	unsigned short baseDest : 6;
	char numberToConvert[MAX_BIT+1];
	char numberConvert[MAX_BIT+1];

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

void set_bases(Modele_t *m, unsigned srcv, unsigned destv);
int set_number(Modele_t *m, char *number);
int number_error(char *number);
int run_convertion(Modele_t *m);
void set_char_number(Modele_t *m, char *c);
void set_filemode(Modele_t *m);

#endif
