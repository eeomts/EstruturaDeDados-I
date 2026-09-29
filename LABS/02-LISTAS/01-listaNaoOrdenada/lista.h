typedef struct lista *Lista;

Lista createLista();

int listaVazia(Lista lst);

int listaCheia(Lista lst);

int insertElem(Lista lst, int elem);

int deleteElem(Lista lst, int elem);

int getValorElem(Lista lst, int pos, int *valor);

void deleteLista(Lista *lst);
