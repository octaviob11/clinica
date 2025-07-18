#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct parametros_configuracao_struct parametros_configuracao_t;
bool verificar_arquivo_configuracao(char * nome_arquivo);
bool criar_configuracao();
bool atualizar_arquivo_configuracao(char * nome_arquivo);
ssize_t sizeof_configuracao();

#endif