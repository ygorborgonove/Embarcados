#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv){

int fp;

char nome[15];
char nome1[15];
char idade[5];
int l=0;
int f=0;
	
	strcpy(nome, argv[1]);
	strcpy(idade, argv[2]);
	
	sprintf(nome1, "%s", nome);
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
