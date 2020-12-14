typedef struct nodo * ptr_nodo;
struct nodo 	{
	lista_bus elem;
	ptr_nodo prox;
};

typedef struct {
	ptr_nodo lista;
	int tamanho;
} lista_encadeada;

typedef lista_encadeada tipo_lista;
FILE *f;

/* Implementações */

int carregar_lista() {
  if((f = fopen("2019-09-06.txt", "r")) == NULL) return 0;
  char c;
  int subControler = 0;
  int controler = 0;
  int listSize = 0;
  do {
    fscanf(f, "%c", &c);
    if(feof(f)) break;

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

  fclose(f);
  return 1;
}

int listar() {
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

int tamanho(lista_encadeada le) {
	return le.tamanho;
}


int obter_elemento(lista_encadeada le, int i, lista_bus *e) {
	int j; ptr_nodo pnodo;
	if ((i <= le.tamanho) && (i > 0)) {
		pnodo = le.lista;
		for(j=2;j<=i;j++)
			pnodo = pnodo->prox;
		*e = pnodo->elem;
    return 1;
	}
	else {
    return 0;
	}
}


void inicializa_lista(lista_encadeada *le) {
	le->tamanho = 0;
	le->lista = NULL;
}


int incluir_elemento(lista_encadeada *le, int i, lista_bus e) {
	int j; ptr_nodo pnodo_incluido, pnodo_anterior;
  if ((i <= le->tamanho+1) && (i > 0)) {
    pnodo_incluido = (ptr_nodo)malloc(sizeof(struct nodo));
  	if (pnodo_incluido == NULL) {
		  return 0;   /* FALTA MEMÓRIA */
    }
  	else {
     	pnodo_incluido->elem = e;
    	if (i == 1) {
   			pnodo_incluido->prox = le->lista;
    		le->lista = pnodo_incluido;
      }
    	else {
        pnodo_anterior = le->lista;
     		for (j=2; j<i; j++)
			    pnodo_anterior = pnodo_anterior->prox;
        pnodo_incluido->prox = pnodo_anterior->prox;
        pnodo_anterior->prox = pnodo_incluido;
			}
     	le->tamanho = le->tamanho + 1;
     	return 1;
  	}
  }
  else
  	return 0;    /* POSIÇÃO INVÁLIDA */
}


int alterar_elemento(lista_encadeada *le, int i, lista_bus e) {
	int j; ptr_nodo pnodo;
  if ((i <= le->tamanho) && (i > 0)) {
   	pnodo = le->lista;
		for (j=2; j<=i;j++)
		  pnodo = pnodo->prox;
    pnodo->elem = e;
    return 1;
  }
  else
  	return 0; /* POSIÇÃO INVÁLIDA */
}


int excluir_elemento(lista_encadeada *le, int i) {
	int j; ptr_nodo pnodo_excluido, pnodo_anterior;
  if ((i <= le->tamanho) && (i > 0)) {
    if (i == 1) {
     	pnodo_excluido = le->lista;
      le->lista = pnodo_excluido->prox;
		}
    else {
      pnodo_anterior = le->lista;
      for (j=2;j<i; j++)
			  pnodo_anterior =  pnodo_anterior->prox;
       	pnodo_excluido = pnodo_anterior->prox;
      	pnodo_anterior->prox = pnodo_excluido->prox;
		}
    free(pnodo_excluido);
    le->tamanho = le->tamanho - 1;
    return 1;
	}
  else
    return 0; /* POSIÇÃO INVÁLIDA */
}