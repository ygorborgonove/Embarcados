#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(){

char arquivo[100];
int tamanhoarq;
char cont[100];
	
	scanf("%s", arquivo);

	le_arq_texto(arquivo, cont);	
	

	printf("%s\n", cont);

return 0;
}
