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
	char * telefone = "5511967836177";
	char * cpf = "39248096824";
	long int dia = 11;
	long int mes = 6;
	long int ano = 95;
	printf("Nome = %s, telefone = %s, cpf = %s, nascimento %ld/%ld/%ld\n", nome, telefone, cpf, dia, mes, ano);
	//printf("Sizeof atring =%d", strlen(nome));
	cadastrar_via_argumentos(nome_arquivo, nome, telefone, cpf, dia, mes, ano);
	return 0;
}