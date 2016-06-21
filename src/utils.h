#ifndef _DECODE
#define _DECODE
#define BUFF_SIZE 1024

typedef int (*operation_t)(int, int, int);
typedef enum {FALSE,TRUE} Boolean;

/*! \brief Affiche un tableau de int.
 *
 * \param tab le tableau à afficher
 * \param tailletab la taille du tableau
 */
void afficheint(int * tab,int tailletab);
void string_to_int(char * tab, char * alaphabet, int * itab);
int alpha_to_int(char l,char * alaphabet);
void codclef (int * iclef,int * itab,int tailletab,int tailleclef,int taillalpha, operation_t operation);
void int_to_alpha(int * itab, char * tab, char * alphabet,int tailletab);
char * file_to_string(char * read_file);
void write_file(char * file, char * var);
void rm_unknown_char(char * tab, char * alphabet);
void error(int e);
void testclef(int * itab, int tailleclef);
void print_man(Boolean option);
#endif