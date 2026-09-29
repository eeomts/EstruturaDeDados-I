#include "lista.h"
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define TAM_NOME 20

struct bebida
{
    char nome[TAM_NOME];
    int volume;
    float preco;
};

struct lista
{
    struct bebida vet[MAX];
    int fim;
};

Lista createLista()
{
    Lista lst = malloc(sizeof(struct lista));
    if (lst != NULL)
        lst->fim = 0;

    return lst;
}

int listaVazia(Lista lst)
{
    if (lst->fim == 0)
        return 1;
    return 0;
}

int listaCheia(Lista lst)
{
    if (lst->fim == MAX)
        return 1;
    return 0;
}

int insertBebida(Lista lst, char *nome, int volume, float preco)
{
    if (lst == NULL || listaCheia(lst))
        return 0;

    struct bebida *nova = &lst->vet[lst->fim];
    strncpy(nova->nome, nome, TAM_NOME - 1);
    nova->nome[TAM_NOME - 1] = '\0';
    nova->volume = volume;
    nova->preco = preco;
    lst->fim++;

    return 1;
}

int deleteUltimaBebida(Lista lst)
{
    if (lst == NULL || listaVazia(lst))
        return 0;

    lst->fim--;

    return 1;
}

int getBebida(Lista lst, int pos, char *nome, int *volume, float *preco)
{
    if (lst == NULL || pos < 0 || pos >= lst->fim)
        return 0;

    strcpy(nome, lst->vet[pos].nome);
    *volume = lst->vet[pos].volume;
    *preco = lst->vet[pos].preco;

    return 1;
}

void deleteLista(Lista *lst)
{
    free(*lst);
    *lst = NULL;
}
