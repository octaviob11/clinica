#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "cadastro.h"

void cadastrar( char * nome_arquivo){
	paciente_t * p = criar_paciente();
	char * string = NULL; /* Ponteiro do tipo char, que irá conter a primeira letra da string PRECISA SER NULL*/
	size_t tamanho; /* tamanho da string*/
	uint8_t dia;
	uint8_t mes;
	uint16_t ano;
	printf("Bem vindo a Clinica AJM\n");
	printf("Criando novo paciente\n");

	printf("Digite o nome\n");
	getline(&string,&tamanho,stdin);
	set_nome(p, string);

	printf("Digite o cpf\n");
	getline(&string,&tamanho,stdin);
	set_cpf(p,string);
	
	printf("Digite o telefone\n");
	getline(&string,&tamanho,stdin);
	set_telefone(p,string);

	printf("Digite o dia de nascimento\n");
	scanf("%hhu", &dia);
	printf("Digite o mes de nascimento\n");
	scanf("%hhu", &mes);
	printf("Digite o ano de nascimento\n");
	scanf("%hu", &ano);

	set_dia_nascimento(p,&dia);
	set_mes_nascimento(p,&mes);
	set_ano_nascimento(p,&ano);
	FILE *arquivo =fopen(nome_arquivo,"ab");
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        
    }
    	fwrite(p, sizeof_paciente(), 1, arquivo);
    fclose(arquivo);
	free(p);
}

void cadastrar_via_argumentos( char * nome_arquivo, char * nome,
							   char * telefone, char * cpf, uint8_t dia,
							   uint8_t mes, uint16_t ano){
	paciente_t * p = criar_paciente();
	set_nome(p, nome);
	set_telefone(p,telefone);
	set_cpf(p,cpf);
	set_dia_nascimento(p,&dia);
	set_mes_nascimento(p,&mes);
	set_ano_nascimento(p,&ano); 
	
	FILE *arquivo =fopen(nome_arquivo,"ab");
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        
    }
    	fwrite(p, sizeof_paciente(), 1, arquivo);
    fclose(arquivo);
	free(p);

}

uint64_t tamanho_arquivo(char * nome_arquivo){
	FILE *arquivo = fopen(nome_arquivo, "rb");
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
    }
	    fseek(arquivo, 0, SEEK_END);
	    uint64_t tamanho = ftell(arquivo);
	    rewind(arquivo);
	    fclose(arquivo);
	    return tamanho;
	    
}

paciente_t * reaver( char * nome_arquivo,  uint64_t index){

	paciente_t * p = criar_paciente();
	FILE *arquivo = fopen(nome_arquivo, "rb");
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
    }
    /**/
     fseek(arquivo, sizeof_paciente()*index, SEEK_SET);

    fread(p, sizeof(char), sizeof_paciente(), arquivo);
    fclose(arquivo);
    return p;
}

void carregar_arquivo(paciente_t **p, char * nome_arquivo){
	uint64_t tamanho = tamanho_arquivo(nome_arquivo);
	uint64_t quantidade = tamanho/sizeof_paciente();
	FILE *arquivo = fopen(nome_arquivo, "rb");
	if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
    }

    for(uint64_t i=0;i<quantidade;i++){
    	p[i]= criar_paciente();
    	fread(p[i], sizeof(char), sizeof_paciente(), arquivo);
    }
	fclose(arquivo);
}

