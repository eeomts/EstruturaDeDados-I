#include "tad.h"
#include <stdlib.h>

struct fracao
{
    int numerador;
    int denominador;
};


Fracao generate(int numerador, int denominador)
{
    Fracao newfracao = malloc(sizeof(struct fracao));
    if (newfracao == NULL){
        return NULL;
    }

    newfracao->numerador = numerador;
    newfracao->denominador = denominador;
    return newfracao;
}

void setValue(Fracao f, int numerador, int denominador)
{
    f->numerador = numerador;
    f->denominador = denominador;
}

int getDenominador(Fracao f)
{
    return f->denominador;
}

int getNumerador(Fracao f)
{
    return f->numerador;
}

Fracao sum(Fracao f1, Fracao f2)
{
    int numerador = (f1->numerador * f2->denominador) + (f2->numerador * f1->denominador);
    int denominador = f1->denominador * f2->denominador;

    return generate(numerador, denominador);
}

void delete(Fracao f)
{
    free(f);
}
