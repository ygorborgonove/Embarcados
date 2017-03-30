#include <stdio.h>
#include <stdlib.h>

int tam_arq_texto(char *nome_arquivo){

FILE *fp;
char q;
int c=0;	

	fp = fopen(nome_arquivo, "r");

	while((q = getc(fp)) != EOF){
	c++;
	}

fclose(fp);

return c;
}

void le_arq_texto(char *nome_arquivo, char *conteudo){

FILE *fp;
int c=0;
char q;
	

	fp = fopen(nome_arquivo, "r");
	
	while((q = getc(fp)) != EOF){
	conteudo[c] = q;	
	c++;
	}

fclose(fp);

return c;
}
