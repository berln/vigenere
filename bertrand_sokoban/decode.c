#include <stdio.h>
#include <stdlib.h>
#include "decode.h"

int main(int argc, char const *argv[])
{

	char * tab = "finalckihe";
	char * alphabet = "abcdefghijklmnopqrstuvwxyz";
	int taillalpha =26;
	char * clef = "cle";
	int tailletab = 6;
	int itab [tailletab];
	int tailleclef =3;
	int iclef [tailleclef];
	char result [tailletab];
	

	encode (tab,alphabet,itab);
	afficheint(itab,tailletab);
	encode (clef,alphabet,iclef);
	afficheint(iclef,tailleclef);
	return 0;
}