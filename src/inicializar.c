#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

typedef struct parametros_configuracao_struct {
	uint64_t paciente_id_atual;
	time_t ultimo_update;

}parametros_configuracao_t;
bool verificar_arquivo_configuracao(char * nome_arquivo);

bool criar_configuracao(){
	parametros_configuracao_t * nova_config = malloc(sizeof(parametros_configuracao_t));
	nova_config->paciente_id_atual=0;
	time(&nova_config->ultimo_update);
	return nova_config;
};

bool atualizar_arquivo_configuracao(char * nome_arquivo);

ssize_t sizeof_configuracao(){
	return sizeof(parametros_configuracao_t);
}

#endif