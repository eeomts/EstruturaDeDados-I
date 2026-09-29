#include "lista.h"
#include <stdio.h>

void mostraTabela(Lista lst)
{
    if (listaVazia(lst))
    {
        printf("Nenhuma bebida cadastrada\n");
        return;
    }

    char nomeBebida[20];
    int volumeMl, pos = 0;
    float precoBebida;

    printf("+----------------------+-------------+----------+\n");
    printf("| %-20s | %-11s | %-8s |\n", "Nome", "Volume (ml)", "Preco");
    printf("+----------------------+-------------+----------+\n");
    while (getBebida(lst, pos, nomeBebida, &volumeMl, &precoBebida))
    {
        printf("| %-20s | %11d | %8.2f |\n", nomeBebida, volumeMl, precoBebida);
        pos++;
    }
    printf("+----------------------+-------------+----------+\n");
}

int main()
{
    Lista lst = createLista();
    if (lst == NULL)
    {
        printf("Erro ao alocar a lista\n");
        return 1;
    }

    int escolha, volumeMl;
    float precoBebida;
    char nomeBebida[20];

    do
    {
        printf("\n---- CADASTRO DE BEBIDAS ----\n");
        printf("[1] Inserir registro\n");
        printf("[2] Apagar ultimo registro\n");
        printf("[3] Imprimir tabela\n");
        printf("[4] Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &escolha) != 1)
            break;

        switch (escolha)
        {
        case 1:
            printf("Nome: ");
            scanf(" %19[^\n]", nomeBebida);
            printf("Volume (ml): ");
            scanf("%d", &volumeMl);
            printf("Preco: ");
            scanf("%f", &precoBebida);
            if (insertBebida(lst, nomeBebida, volumeMl, precoBebida))
                printf("Registro inserido\n");
            else
                printf("Nao foi possivel inserir (lista cheia)\n");
            break;

        case 2:
            if (deleteUltimaBebida(lst))
                printf("Ultimo registro apagado\n");
            else
                printf("Nao ha registros para apagar\n");
            break;

        case 3:
            mostraTabela(lst);
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida\n");
        }
    } while (escolha != 4);

    deleteLista(&lst);

    return 0;
}
