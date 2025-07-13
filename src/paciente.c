#include "paciente.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

typedef struct nascimento_struct {
	uint8_t dia;
	uint8_t mes;
	uint16_t ano;
} nascimento_t;

typedef struct paciente_struct {
	char nome[96];
	char telefone[16];
	char cpf[16];
	nascimento_t data_nascimento;
} paciente_t;

paciente_t * criar_paciente(){
	paciente_t * novo_paciente = malloc(sizeof(paciente_t));
	strcpy(novo_paciente->nome,"SEM NOME" );
	strcpy(novo_paciente->telefone,"5511999999999");
	/*novo_paciente->cpf="123.456.789-01"  -- Uma string no código é um endereço de memória
	* Por isso não podemos utilizar o código  acima
	*/ 
	strcpy(novo_paciente->cpf,"123.456.789-01");

	novo_paciente->data_nascimento.dia=1;
	novo_paciente->data_nascimento.mes=1;
	novo_paciente->data_nascimento.ano=1970;
	return novo_paciente;
}
/* SETTERs */
void set_nome(paciente_t * p, char * nome){
	uint8_t maximo = strlen(nome);
	uint8_t fim=0;
	uint8_t index=0;
	while(fim !=1){
		if(nome[index]==0x0A){
			nome[index]='\0';
			fim=1;
		}else if(index == maximo){
			fim=1;
		}else{
			index++;
		}
	}
	strcpy(p->nome, nome);
}
void set_cpf(paciente_t * p, char * cpf){
	uint8_t maximo = strlen(cpf);
	uint8_t fim=0;
	uint8_t index=0;
	while(fim !=1){
		if(cpf[index]==0x0A){
			cpf[index]='\0';
			fim=1;
		}else if(index == maximo){
			fim=1;
		}else{
			index++;
		}
	}
	strcpy(p->cpf, cpf);
}
void set_telefone(paciente_t * p, char * telefone){
	uint8_t maximo = strlen(telefone);
	uint8_t fim=0;
	uint8_t index=0;
	while(fim !=1){
		if(telefone[index]==0x0A){
			telefone[index]='\0';
			fim=1;
		}else if(index == maximo){
			fim=1;
		}else{
			index++;
		}
	}
	strcpy(p->telefone, telefone);
}
void set_dia_nascimento(paciente_t * p, uint8_t * dia){
	p->data_nascimento.dia= *dia;
}
void set_mes_nascimento(paciente_t * p, uint8_t * mes){
	p->data_nascimento.mes= *mes;
}
void set_ano_nascimento(paciente_t * p, uint16_t * ano){
	p->data_nascimento.ano= *ano;
}


/*GETTERS*/
char * get_nome(paciente_t * p){
	return p->nome;
}
char * get_cpf(paciente_t * p){
	return p->cpf;
}
char * get_telefone(paciente_t * p){
	return p->telefone;
}
uint8_t get_dia_nascimento(paciente_t * p){
	return p->data_nascimento.dia;
}
uint8_t get_mes_nascimento(paciente_t * p){
	return p->data_nascimento.mes;
}
uint16_t get_ano_nascimento(paciente_t * p){
	return p->data_nascimento.ano;
}

/* Utilidades*/ 
ssize_t sizeof_paciente(){
	return sizeof(paciente_t);
}

uint64_t h31_hash(const char* s, size_t len)
{
    uint64_t h = 0;
    while (len) {
        h = 3 * h + (char*)*s++;
        --len;
    }
    return h;
}
