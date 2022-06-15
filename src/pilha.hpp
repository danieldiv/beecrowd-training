#ifndef PILHA_H
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include <iostream>
using namespace std;

typedef struct ItemPilha ItemPilha;
typedef struct BlockPilha BlockPilha;
typedef struct Pilha Pilha;

struct ItemPilha {
	char val;
};

struct BlockPilha {
	ItemPilha data;
	BlockPilha *prox;
};

struct Pilha {
	BlockPilha *base;
	BlockPilha *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, ItemPilha d);
void Pop(Pilha *p, ItemPilha *d);
void PImprime(Pilha *p);

#endif