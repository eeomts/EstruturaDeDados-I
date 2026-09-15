#include <stdio.h>
#include<stdlib.h>
#include"ponto.h"

int main()
{
    Coord pontoA = generatePoint(1, 2);
    Coord pontoB = generatePoint(2, 3);

    int distanciaPontos = distacePoints(pontoA, pontoB);

    printf("a distancia deles e: %d", distanciaPontos);

}