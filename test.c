#include <stdio.h>
#include<stdlib.h>
#define MAX 100

FILE *fp;

typedef struct{
    char cod_terminal;
    char data[8];
    char hr[4];
    char placa_onibus[7];
    char cod_empresa;
} lista_bus;

lista_bus tadLista[MAX];

void limpatela(){
  system("clear");
}

int carrega_lista() {
  if((fp = fopen("2019-09-06.txt", "r")) == NULL) return 0;
  char c;
  int subControler = 0;
  int controler = 0;
  int listSize = 0;
  do {
    fscanf(fp, "%c", &c);
    if(feof(fp)) break;

    switch(c) {
      case ' ': {
        subControler = 0;
        controler++;
        break;
      }
      case '\n': {
        subControler = 0;
        controler = 0;
        listSize++;
        break;
      }
      default: {
        switch(controler) {
          case 0: {
            tadLista[listSize].cod_terminal = c;
            break;
          }
          case 1: {
            tadLista[listSize].data[subControler] = c;
            subControler++;
            break;
          }
          case 2: {
            tadLista[listSize].hr[subControler] = c;
            subControler++;
            break;
          }
          case 3: {
            tadLista[listSize].placa_onibus[subControler] = c;
            subControler++;
            break;
          }
          case 4: {
            tadLista[listSize].cod_empresa = c;
            break;
          }
        }
      }
    }
    //printf("%c(%d)", c, controler);
  } while (1 == 1);

  fclose(fp);
  return 1;
}

int imprime_lista(){
  for(int i = 0; i < MAX; i++) {
    if(tadLista[i].cod_terminal == NULL) break;
    printf("\n%c ", tadLista[i].cod_terminal);

    for(int j = 0; j < 8; j++) {
      printf("%c", tadLista[i].data[j]);
    }

    printf(" ");

    for(int j = 0; j < 4; j++) {
      printf("%c", tadLista[i].hr[j]);
    }

    printf(" ");
    
    for(int j = 0; j < 7; j++) {
      printf("%c", tadLista[i].placa_onibus[j]);
    }
    
    printf(" %c", tadLista[i].cod_empresa);
  }
  printf("\n");
  return 1;
}

int main(){
  carrega_lista();
  imprime_lista();

  return 1;
}
