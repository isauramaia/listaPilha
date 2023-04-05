#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#define TRUE 1 
#define FALSE 0

typedef struct{
    char nome [31];
    int idade;
} Elem;

typedef struct no{ 
    Elem elemento;
struct no *proximo;
} No;

typedef struct{
No *topo;
} Pilha;


void Cria (Pilha *pilha);
int Vazia (Pilha pilha);
int Quantidade (Pilha pilha);

int Pop (Pilha *pilha, Elem *elem); 
int Push (Pilha *pilha, Elem novo_elemento); 
int Topo (Pilha pilha, Elem *elem);


//#include "pilha_encadeada.h"

void Cria (Pilha *pilha) { 
    pilha->topo = NULL;
}


//inserindo no topo da pilha (empilhamento)
int Push (Pilha *pilha, Elem novo_elemento) {
    No *novo;

    if ((novo = malloc(sizeof (No))) == NULL)
        return FALSE;
    novo->elemento = novo_elemento; 
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    return TRUE;
}

//removendo no topo da pilha (desempilhamento)
int Pop (Pilha *pilha, Elem *elem) {
    No *atual;
    if (Vazia (*pilha)) return FALSE;
    atual = pilha->topo;
    pilha->topo = atual->proximo;
    *elem = atual->elemento;
    free (atual);
    return TRUE;
}

//lendo o topo da pilha
int Topo (Pilha pilha, Elem *elem) { 
    if (Vazia (pilha)) return FALSE; 
    *elem = pilha.topo->elemento; 
    return TRUE;
}

//indicando se a pilha esta vazia
int Vazia (Pilha pilha) {
    return pilha.topo == NULL;
}

//retornando o tamanho da pilha
int Quantidade (Pilha pilha) {
    int qtde = 0;
    No *atual = pilha.topo; 
    while (atual != NULL) {
        ++qtde;
        atual = atual->proximo;
    }
    return qtde;
}  

