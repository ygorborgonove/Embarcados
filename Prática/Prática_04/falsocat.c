#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(int argc, char **argv){

FILE *fp;
char cont[100];

	le_arq_texto(argv[1], cont);	
	

	printf("%s\n", cont);


fclose(fp);

return 0;
}
