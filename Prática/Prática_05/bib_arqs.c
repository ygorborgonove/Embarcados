#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int tam_arq_texto(char *nome_arquivo){

int fp;
char q;
int c=0;	

	fp = open(nome_arquivo, O_RDWR);

	while(read(fp, &q, 1)){
	c++;
	}

close(fp);

return c;
}

void le_arq_texto(char *nome_arquivo, char *conteudo){

int fp;
int c=0;
char q;
	

	fp = open(nome_arquivo, O_RDWR | O_CREAT, S_IRWXU);
	
	while(read(fp, &q, 1)){
	conteudo[c] = q;	
	c++;
	}

close(fp);

return 0;
}
