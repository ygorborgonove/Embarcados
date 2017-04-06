#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "bib_arqs.h"

int main(){

char arquivo[100];
int tamanhoarq;
int fp;
	
	scanf("%s", arquivo);

	tamanhoarq = tam_arq_texto(arquivo);	
	tamanhoarq = tamanhoarq-1;

	printf("o tamanho do arquivo é: %d\n", tamanhoarq);
	//write(fp, "o tamanho do arquivo é: ", 20);
	//write(fp, &tamanhoarq, sizeof(int));
	//write(fp, "\n", 1);
	

return 0;
}
