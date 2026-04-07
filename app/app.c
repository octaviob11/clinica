/*
* Autor: Octavio Bottoni Neto
* PROGRMA: Cadastrar.c
* @Brief: Cadastrar pacientes via linha de comando
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "cadastro.h"


int main(){
	
	char * nome_arquivo = "Paciente.bin";
	char * nome = "Octavio Bottoni Neto";
	char * telefone = "55118777722";
	char * cpf = "333344094";
	long int dia = 12;
	long int mes = 2;
	long int ano = 99;
	printf("Nome = %s, telefone = %s, cpf = %s, nascimento %ld/%ld/%ld\n", nome, telefone, cpf, dia, mes, ano);
	//printf("Sizeof atring =%d", strlen(nome));
	cadastrar_via_argumentos(nome_arquivo, nome, telefone, cpf, dia, mes, ano);
	return 0;
}
