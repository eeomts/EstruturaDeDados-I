typedef struct lista *Lista;

Lista createLista();

int listaVazia(Lista lst);

int listaCheia(Lista lst);

int insertElemOrdenado(Lista lst, int elem);

int deleteElemOrdenado(Lista lst, int elem);

int getValorElem(Lista lst, int pos, int *valor);

void deleteLista(Lista *lst);
