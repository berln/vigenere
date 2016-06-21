#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void string_to_int(char * tab, char * alphabet, int * itab){
	int i;
	for (i = 0; tab [i] !='\0' ; ++i)
	{
		
		itab[i]=alpha_to_int(tab[i],alphabet);
	}
}

int alpha_to_int(char l,char * alphabet){
	int i;
	for (i = 0; alphabet [i] != '\0' ; ++i)
	{
		if (l == alphabet[i])
			return i;
	}
	/*la lettre n'est pas dans l'alphabet*/
	return -1;
}

void codclef (int * iclef,int * itab,int tailletab,int tailleclef,int taillalpha, operation_t operation){
	int i,j;
	for (i=0, j=0; i < tailletab; ++i, j = (j + 1) % tailleclef)
	{

		/* itab[i]=itab[i]+iclef[j];

		passage d'une fonction en parametre par pointeur
		resolution du pointeur et appele de la fonction*/
		if ((itab[i]>=0)&&(iclef[j]>=0))
			itab[i] = (*operation)(itab[i], iclef[j], taillalpha);

		/* code */
	}
}

void int_to_alpha(int * itab, char * tab, char * alphabet,int tailletab){
	int i;
	for (i = 0; i < tailletab ; ++i)
	{
		if (itab[i]>=0){
			tab[i] = alphabet[itab[i]];
		}
	}

	tab[tailletab] = '\0';
	/*transcript num to alpha*/

}

void afficheint(int * tab,int tailletab){
	int i;
	for (i = 0; i < tailletab; ++i)
	{
		printf("%d;",tab[i] );
		/* code */
	}
	printf("\n");
}

char * file_to_string(char * read_file){
	/*alloc of buffer befor reding file*/
    char * buffer;
    FILE *file;
    buffer= malloc(100*sizeof(char));
    if(buffer==NULL)
    	error(1);
    file = fopen(read_file, "r");
    if (file == NULL) {
    	/*perror standard fuction for explaining fopent errors*/
    	perror("Error");
    	/*free buffer in case of problem*/
    	free(buffer);
    	exit (1);
    } else {
    		fscanf(file,"%s",buffer);
	printf("CONTENT: %s\n",buffer);

      fclose(file);
      
    }

   /*return address of the buffer*/
    return buffer;
}

void write_file(char * filename, char * var)
{
    FILE *file;
 	
    file = fopen(filename, "r+");
    if (file== NULL){
    	/*perror standard fuction for explaining fopent errors*/
    	perror("Error");
    	free(var);
    	exit (1);
    }
    	  	
    fprintf(file,"%s\n",var);
    fclose(file);
      
}


void rm_unknown_char(char * tab, char * alphabet){
	int i;
	int j=0;
	for (i = 0; tab[i+1] != '\0'; ++i)
	{
		/* parsing tab in search of uknown cahr */
		if ((alpha_to_int(tab[i], alphabet))<0)
			j++;
		else
			tab[i-j]=tab[i];
	}
	tab[i-j]='\0';
}

void testclef(int * iclef, int tailleclef){
	int i;
	for (i = 0; i < tailleclef; ++i)
	{
		if (iclef[i]<0)
		{
			error(2);
		}
	}
}


void error(int e){
	switch(e){
		case 1: printf("erreur d'alloc\n"); break;
		case 2: printf("carac not in alphabet\n"); break;
		default: printf("error incunue\n"); break;
	}
	exit(e);
}

void print_man(Boolean option){
	printf("Options : [-sh] [--help] [--skip] [-a alphabet] [-k clé] [--alphabet=alphabet] [--key=clé]\n");
	
	/*fuction called by main if it's decode argument is TRUE else argument is FASE*/  
	if (option==TRUE)
	{
		printf("Le programme code encode un texte en utilisant le code Vigenere.\n Lorsqu aucun fichier n est fourni, l encodage se fait depuis l entree standard vers la sortie standard, ligne par ligne.\nLorsqu un seul fichier est fourni, l encodage se fait depuis le fichier vers la sortie standard.\nLorsque deux fichiers sont fournis, l encodage se fait depuis le premier vers le deuxieme.\nL option -s (--skip), lorsqu elle est presente, indique que les lettres du\n");
		printf("texte à encoder non présentes dans l alphabet sont supprimees.\nLorsqu elle est absente, ces lettres restent en clair dans le message code.\n");
		printf("Les options -a (--alphabet) et -k (--key) permettent de specifier les fichiers contenant respectivement l alphabet et la cle. Si elles sont absentes,\nlealphabet est l alphabet latin non accentue compose uniquement de lettres minuscules (abcdefghijklmnopqrstuvwxyz) et la cle est notaverysmartkey.\nL option -h (--help) affiche ce manuel.\n");
	}
	else
	{
		printf("Le programme decode decode un texte en utilisant le code Vigenere.\nLorsqu aucun fichier n est fourni, le decodage se fait depuis l entree standard vers la sortie standard, ligne par ligne.\nLorsqu un seul fichier est fourni, le decodage se fait depuis le fichier vers la sortie standard.\nque deux fichiers sont fournis, l encodage se fait depuis le premier vers le deuxieme.\nL otion -s (--skip), lorsqu elle est presente, indique que les lettres du texte à decoder non presentes dans l alphabet");
		printf("sont supprimees. Lorsqu elle est absente, ces lettres sont restituees telles quelles dans le message decode.\nLes options -a (--alphabet) et -k (--key) permettent de specifier les fichiers contenant respectivement l alphabet et la cle.\nSi elles sont absentes, l alphabet est l alphabet latin non accentue compose uniquement de lettres minuscules (abcdefghijklmnopqrstuvwxyz)\net la cle est notaverysmartkey\nL option -h (--help) affiche ce manuel.\n");
	}
}