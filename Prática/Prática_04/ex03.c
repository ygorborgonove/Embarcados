#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

FILE *fp;

char *nome = argv[1];
char *nome1 = argv[1];
char *idade = argv[2];
	
	sprintf(nome1, "%s", nome);
	fp = fopen(nome, "w");
	fprintf(fp, "Nome: %s\n Idade: %s anos\n", nome, idade);


fclose(fp);

return 0;
}
