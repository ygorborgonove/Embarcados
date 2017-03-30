#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *fp;
int idade;
char nome[15];
char nome1[15];
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	printf("Digite a sua idade: ");
	scanf("%d", &idade);
	
	sprintf(nome1, "%s.txt", nome);
	fp = fopen(nome, "w");
	
	fprintf(fp, "Nome: %s \n Idade: %d anos\n", nome, idade);


fclose(fp);

return 0;
}
