#include "pilha.hpp"

void FPVazia(Pilha *p) {
	p->base = (BlockPilha *)malloc(sizeof(BlockPilha));
	p->top = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, ItemPilha d) {
	BlockPilha *aux = (BlockPilha *)malloc(sizeof(BlockPilha));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, ItemPilha *d) {
	BlockPilha *aux;

	if (p->base == p->top || p == NULL) {
		printf("PILHA VAZIA!\n");
		return;
	}

	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}


void PImprime(Pilha *p) {
	BlockPilha *aux;
	float conta = 0;
	float soma = 0;

	aux = p->top;
	while (aux != p->base) {

		printf("%c", aux->data.val);
		aux = aux->prox;
	}
	cout << endl;
}