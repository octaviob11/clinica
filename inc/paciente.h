#ifndef PACIENTE_H
#define PACIENTE_H
#include<stdio.h>
#include <stdlib.h>


typedef struct nascimento_struct nascimento_t;
typedef struct paciente_struct paciente_t;


paciente_t * criar_paciente();
/*SETTERs*/
void set_nome(paciente_t * p, char * nome);
void set_cpf(paciente_t * p, char * cpf);
void set_telefone(paciente_t * p, char * telefone);
void set_dia_nascimento(paciente_t * p, uint8_t * dia);
void set_mes_nascimento(paciente_t * p, uint8_t * mes);
void set_ano_nascimento(paciente_t * p, uint16_t * ano);

/*GETTERs*/

char * get_nome(paciente_t * p);
char * get_cpf(paciente_t * p);
char * get_telefone(paciente_t * p);
uint8_t get_dia_nascimento(paciente_t * p);
uint8_t get_mes_nascimento(paciente_t * p);
uint16_t get_ano_nascimento(paciente_t * p);

/*Utilidades*/
ssize_t sizeof_paciente();
uint64_t h31_hash(const char* s, size_t len);
#endif