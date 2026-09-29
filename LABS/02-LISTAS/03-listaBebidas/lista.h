typedef struct lista *Lista;

Lista createLista();

int listaVazia(Lista lst);

int listaCheia(Lista lst);

int insertBebida(Lista lst, char *nome, int volume, float preco);

int deleteUltimaBebida(Lista lst);

int getBebida(Lista lst, int pos, char *nome, int *volume, float *preco);

void deleteLista(Lista *lst);
