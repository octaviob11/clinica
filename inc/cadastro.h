#ifndef CADASTRO_H
#define CADASTRO_H
#include<stdio.h>
#include <stdlib.h>


void cadastrar( char * nome_arquivo);
void cadastrar_via_argumentos( char * nome_arquivo, char * nome,
							   char * telefone, char * cpf, uint8_t dia,
							   uint8_t mes, uint16_t ano);
							   
uint64_t tamanho_arquivo(char * nome_arquivo);
paciente_t * reaver( char * nome_arquivo, uint64_t index);
void carregar_arquivo(paciente_t **p, char * nome_arquivo);

#endif