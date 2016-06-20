#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


int soustraction(int lhs, int rhs, int taillalpha) {
	int result = lhs - rhs;

	if(result < 0) {
		result += taillalpha;
	}
	return result;
}

int main(int argc, char **argv)
{

	/*init of all tabs and vars*/
	char * alphabet = "abcdefghijklmnopqrstuvwxyz";
	char * clef = "notaverysmartkey";
	char * tab;
	int taillalpha;
	int tailletab;	
	int tailleclef;
	int * iclef;
	int * itab;
	Boolean casetwo = FALSE;
	Boolean unknown_char = FALSE;

  /*test options */
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
            print_man(FALSE);
            return 0;
            break;

       case 's':
            printf("option c with value '%s'\n", optarg);
            unknown_char = TRUE;
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

    /*test args*/

   switch(argc - optind){
      case 0:
      /*in no argument read tab from keyboard*/
        printf("pas d'argument entrez une chaine\n");
        tab=calloc(100,sizeof(char));
        fgets(tab,99,stdin);
      break;
      case 1:
      /* if one argument then read file and put it in tab*/
        printf("arg 1 %s\n",argv[optind] );
        tab=filetostring(argv[optind]);
        printf("tableau lue dans %s = %s\n",argv[optind],tab );
      break;
      case 2:
      /*if 2 argumpent read file an put it in tab then set casetow to true*/
        printf("arg2 %s\n",argv[optind-1] );
        casetwo=TRUE;
        tab=filetostring(argv[optind]);
      break;

      default:
        print_man(FALSE);
            return 0;
            break;
}

	if (unknown_char == TRUE)
		{
			/* remove uknow char if -s */
			printf("remove unknown char\n");
			rm_unknown_char(tab, alphabet);
		}

	tailletab =strlen(tab);
	tailleclef=strlen(clef);
  taillalpha=strlen(alphabet);
	itab=malloc(tailletab*sizeof(int));
	iclef=malloc(tailleclef*sizeof(int));


  /*convert tab and key to int tab*/
	string_to_int (tab,alphabet,itab);

	string_to_int (clef,alphabet,iclef);
	
  /*test invalid char in the key*/
  testclef(iclef, tailleclef);

  /*decod tab with the key, minus done with a pointer to the fuction*/ 
	codclef(iclef, itab, tailletab, tailleclef, taillalpha, &soustraction);

  /*convert the final int tab to a char tab*/
	inttoalpha(itab, tab, alphabet, tailletab);

  /*if a dest file have been specified write the result into the file elese print the result */
	if(casetwo==FALSE){
    	printf("message final: %s\n",tab);
  	}
	else{
    /*argv[optind+1] = file name*/
		printf("ecriture de %s dans %s\n",tab,argv[optind+1]);
		write_file(argv[optind+1],tab);
	}	
	
	return 0;
}