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


int main( int argc, char** argv){
	
	//printf("Modo de usar: app.exe \"NOME\" \"TELEFONE\" \"CPF\" \"dia\" \"mes\" \"ano\" \n");
	if(argc>1){
		if(!strcmp(argv[1],"-h")) {
		printf("Modo de usar: ./application \"NOME DO ARQUIVO\" \"NOME\" \"TELEFONE\" \"CPF\" \"dia\" \"mes\" \"ano\" \n");
		return 0;
		}
	}
	int a =0;
	char * nome_arquivo = argv[1];
	char * nome = argv[2];
	char * telefone = argv[3];
	char * cpf = argv[4];
	long int dia = strtol(argv[5], NULL, 10);
	long int mes = strtol(argv[6], NULL, 10);
	long int ano = strtol(argv[7], NULL, 10);
	printf("Nome = %s, telefone = %s, cpf = %s, nascimento %ld/%ld/%ld\n", nome, telefone, cpf, dia, mes, ano);
	//printf("Sizeof atring =%d", strlen(nome));
	cadastrar_via_argumentos(nome_arquivo, nome, telefone, cpf, dia, mes, ano);

	


/*
    uint64_t tamanho = tamanho_arquivo("paciente.bin");
    uint64_t quantidade = tamanho/sizeof_paciente();
	printf("Quantidade de pacientes = %llu\n", quantidade);

    //Alocando dinamicamente **p -> *p - > pacinente_t 
    paciente_t **p = malloc(quantidade * sizeof(paciente_t *));
    printf("Carregando arquivo\n");
    carregar_arquivo(p,"paciente.bin");
    printf("Vamos pegar informações co pasciente 1000\n");
    	printf("Nome = %s\n", get_nome(p[1000]));
		printf("Telefone = %s\n", get_telefone(p[1000]));
		printf("CPF = %s\n", get_cpf(p[1000]));
		printf("Data nascimento = %hhu/%hhu/%hu \n", get_dia_nascimento(p[1000]),get_mes_nascimento(p[1000]),get_ano_nascimento(p[1000]) );
    
	int i;
	scanf("%d", &i);

    /// liberar memória 
	for (uint64_t i = 0; i < quantidade; i++) {
    	free(p[i]);
    	p[i] = NULL;
	}
	free(p);
	p = NULL;

	int b;
	scanf("%d", &b);
	printf("i = %d b = %d",i, b);
	*/
	return 0;

}