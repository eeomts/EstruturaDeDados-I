typedef struct fracao *Fracao;

Fracao generate(int numerador, int denominador);

void setValue(Fracao f, int numerador, int denominador);

int getDenominador(Fracao f);

int getNumerador(Fracao f);

Fracao sum(Fracao f1, Fracao f2);

void delete(Fracao f);
