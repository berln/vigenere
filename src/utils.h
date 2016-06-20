#ifndef _DECODE
#define _DECODE
#define BUFF_SIZE 1024

typedef int (*operation_t)(int, int, int);
typedef enum {FALSE,TRUE} Boolean;

void afficheint(int * tab,int tailletab);
void string_to_int(char * tab, char * alaphabet, int * itab);
int alphatoint(char l,char * alaphabet);
void codclef (int * iclef,int * itab,int tailletab,int tailleclef,int taillalpha, operation_t operation);
void inttoalpha(int * itab, char * tab, char * alphabet,int tailletab);
char * filetostring(char * read_file);
void write_file(char * file, char * var);
void rm_unknown_char(char * tab, char * alphabet);
void error(int e);
void testclef(int * itab, int tailleclef);
void print_man(Boolean option);
#endif