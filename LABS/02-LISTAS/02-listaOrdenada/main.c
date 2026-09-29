#include "lista.h"
#include <stdio.h>

void mostraLista(Lista lst)
{
    if (lst == NULL)
    {
        printf("Lista nao inicializada\n");
        return;
    }

    if (listaVazia(lst))
    {
        printf("Lista vazia\n");
        return;
    }

    int pos = 0, valor;
    printf("Lista: { ");
    while (getValorElem(lst, pos, &valor))
    {
        printf("%d ", valor);
        pos++;
    }
    printf("}\n");
}

int main()
{
    Lista lst = NULL;
    int escolha, numero;

    do
    {
        printf("\n---- LISTA ORDENADA ----\n");
        printf("[1] Inicializar lista\n");
        printf("[2] Inserir elemento\n");
        printf("[3] Remover elemento\n");
        printf("[4] Imprimir lista\n");
        printf("[0] Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &escolha) != 1)
            break;

        switch (escolha)
        {
        case 1:
            if (lst != NULL)
                deleteLista(&lst);
            lst = createLista();
            if (lst == NULL)
                printf("Erro ao alocar a lista\n");
            else
                printf("Lista inicializada\n");
            break;

        case 2:
            printf("Numero a inserir: ");
            scanf("%d", &numero);
            if (insertElemOrdenado(lst, numero))
                printf("%d inserido\n", numero);
            else
                printf("Nao foi possivel inserir (lista nao inicializada ou cheia)\n");
            break;

        case 3:
            printf("Numero a remover: ");
            scanf("%d", &numero);
            if (deleteElemOrdenado(lst, numero))
                printf("%d removido\n", numero);
            else
                printf("Nao foi possivel remover (lista vazia ou elemento inexistente)\n");
            break;

        case 4:
            mostraLista(lst);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida\n");
        }
    } while (escolha != 0);

    if (lst != NULL)
        deleteLista(&lst);

    return 0;
}
