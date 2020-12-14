#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char cod_terminal;
    char data[8];
    char hr[4];
    char placa_onibus[7];
    char cod_empresa;
} lista_bus;

lista_bus tadLista[MAX];
/* DECLARACOES GLOBAIS DE CONSTANTES */

#include "tad_lst2.c"

tipo_lista lista;

void monta_tela() {
	printf("\n0 - carregar lista");
 	printf("\n1 - listar");
  printf("\n2 - media de tempo");
  printf("\n3 - valor pago por empresa");
  printf("\n4 - inverter");
  printf("\n5 - tamanho por quantidade de nodos");
 	printf("\n9 - sair\n");
}

char escolhe_opcao() {
	return getchar();
}

void limpa_tela() {
	system("clear");
}

int main() {
	char opcao;
	inicializa_lista(&lista);
  do {
    limpa_tela();	
   	monta_tela();
    opcao = escolhe_opcao();
   	switch (opcao) {
      case '0':
        carregar_lista();
        //limpa_tela();
        break;
      case '1':
        //limpa_tela();
        listar();getchar();getchar();
        break;
      case '2':
        break;
      case '3':
        break;
      case '9':
       	exit(1);
      break;
    }
  } while (1);
}