#include "lista.h"
#include <stdlib.h>
#define MAX 20

struct lista
{
    int vet[MAX];
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

int insertElemOrdenado(Lista lst, int elem)
{
    if (lst == NULL || listaCheia(lst))
        return 0;

    if (listaVazia(lst) || elem >= lst->vet[lst->fim - 1])
    {
        lst->vet[lst->fim] = elem;
    }
    else
    {
        int posNova = 0;
        while (elem >= lst->vet[posNova])
            posNova++;

        for (int i = lst->fim; i > posNova; i--)
            lst->vet[i] = lst->vet[i - 1];

        lst->vet[posNova] = elem;
    }

    lst->fim++;

    return 1;
}

int deleteElemOrdenado(Lista lst, int elem)
{
    if (lst == NULL || listaVazia(lst) ||
        elem < lst->vet[0] || elem > lst->vet[lst->fim - 1])
        return 0;

    int posAtual = 0;
    while (posAtual < lst->fim && lst->vet[posAtual] < elem)
        posAtual++;

    if (posAtual == lst->fim || lst->vet[posAtual] > elem)
        return 0;

    for (int i = posAtual + 1; i < lst->fim; i++)
        lst->vet[i - 1] = lst->vet[i];

    lst->fim--;

    return 1;
}

int getValorElem(Lista lst, int pos, int *valor)
{
    if (lst == NULL || pos < 0 || pos >= lst->fim)
        return 0;

    *valor = lst->vet[pos];

    return 1;
}

void deleteLista(Lista *lst)
{
    free(*lst);
    *lst = NULL;
}
