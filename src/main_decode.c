#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


#define BUFF_SIZE 1024

int soustraction(int lhs, int rhs, int taillalpha) {
	int result = lhs - rhs;

	if(result < 0) {
		result += taillalpha;
	}

	printf("Math time! %d - %d = %d\n", lhs, rhs, result);
	return result;
}

int main(int argc, char **argv)
{

	/*char * tab = "ckitec";*/
	char * alphabet = "abcdefghijklmnopqrstuvwxyz";
	char * clef = "notaverysmartkey";
	char * tab;
	int taillalpha;
	int tailletab;	
	int tailleclef;
	int * iclef;
	int * itab;
	Boolean casetwo = FALSE;


	int c;

   while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"alphabet", required_argument, 0, 'a'},
            {"help",  no_argument,       0,  'h' },
            {"skip",  no_argument, 0,  's' },
            {"key", required_argument, 0, 'k'}
        };

       c = getopt_long(argc, argv, "a:hk:s",
                 long_options, &option_index);
        if (c == -1)
            break;

       switch (c) {
        
       case 'a':
            printf("option awith value '%s'\n", optarg);
            alphabet=filetostring(optarg);
            break;

       case 'h':
            printf("man\n");
            return 0;
            break;

       case 's':
            printf("option c with value '%s'\n", optarg);
            break;

       case 'k':
            printf("option d with value '%s'\n", optarg);
            clef=filetostring(optarg);
            break;

       default:
            printf("?? getopt returned character code 0%o ??\n", c);
            break;
        }
    }

   switch(argc - optind){
      case 0:
        printf("pas d'argument entrer une chaine\n");
        tab=calloc(100,sizeof(char));
        fgets(tab,100,stdin);
      break;
      case 1:
        printf("arg 1 %s\n",argv[optind] );
        tab=filetostring(argv[optind]);
        printf("tableau lue dans %s = %s\n",argv[optind],tab );
      break;
      case 2:
        printf("arg2 %s\n",argv[optind-1] );
        casetwo=TRUE;
        tab=filetostring(argv[optind]);
      break;
}


	tailletab =strlen(tab)-1;
	tailleclef=strlen(clef)-1;
  taillalpha=strlen(alphabet)-1;
	itab=malloc(tailletab*sizeof(int));
	iclef=malloc(tailleclef*sizeof(int));

	printf("taille clef %d\n", tailleclef );

	string_to_int (tab,alphabet,itab);
	afficheint(itab,tailletab);
	string_to_int (clef,alphabet,iclef);
	afficheint(iclef,tailleclef);
  testclef(iclef, tailleclef);

	codclef(iclef, itab, tailletab, tailleclef, taillalpha, &soustraction);

	inttoalpha(itab, tab, alphabet, tailletab);

	if(casetwo==FALSE){
    	printf("message final: %s\n",tab);
  	}
	else{
		printf("ecriture de %s dans %s\n",tab,argv[optind+1]);
		write_file(argv[optind+1],tab);
	}	
	
	return 0;
}