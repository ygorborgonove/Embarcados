#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(){

int fp;
char idade[5];
char nome[15];
char nome1[15];
int f=0;
int l=0;
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	printf("Digite a sua idade: ");
	scanf("%s", idade);
	
	sprintf(nome1, "%s.txt", nome);
	fp = open(nome, O_RDWR | O_CREAT, S_IRWXU);
	
	l=strlen(nome);
	f=strlen(idade);
	
	write(fp, "Nome: ", 6);
	write(fp, &nome, l);
	write(fp, "\n", 1);
	write(fp, "Idade:", 6);
	write(fp, &idade, f);
	write(fp, " anos", 5);
	write(fp, "\n", 1);


	close(fp);

return 0;
}
