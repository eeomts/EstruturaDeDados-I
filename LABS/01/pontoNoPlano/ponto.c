#include "ponto.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct coord
{
    int x;
    int y;
};

Coord generatePoint(int valueX, int valueY)
{
    Coord point = malloc(sizeof(struct coord));

    if (point == NULL){
        printf("deu null krl");
        return NULL;
    }
        

    point->x = valueX;
    point->y = valueY;
    // printf("valor de x %d", point->x);

    return point;
}

void freePoint(Coord **point)
{
    free(point);
}

double distacePoints(Coord a, Coord b)
{
    return sqrt(pow(a->x - b->x, 2) + pow(b->y - a->y, 2));
}
