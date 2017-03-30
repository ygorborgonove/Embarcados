#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(){

char arquivo[100];
int tamanhoarq;
	
	scanf("%s", arquivo);

	tamanhoarq = tam_arq_texto(arquivo);	
	tamanhoarq = tamanhoarq-1;

	printf("o tamanho do arquivo é: %d\n", tamanhoarq);

return 0;
}
