#include "tad.h"
#include <stdio.h>

int main(){
    Fracao a = generate(2, 4);
    Fracao b = generate(1, 3);
    Fracao c = sum(a, b);

    printf("%d/%d + %d/%d = %d/%d\n", getNumerador(a), getDenominador(a), getNumerador(b), getDenominador(b),getNumerador(c), getDenominador(c));

    delete(a);
    delete(b);
    delete(c);

    return 0;
}
