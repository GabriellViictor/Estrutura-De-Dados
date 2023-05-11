#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo
{
    T elemento;
    Nodo<T> *prox;
};

template<typename T>
struct PilhaDinamicaGen
{
    int cardinalidade;
    Nodo<T> *fim;
};


template<typename T>
void cria(PilhaDinamicaGen<T>& pilha)
{
    pilha.cardinalidade = 0;
    pilha.fim = NULL;
}

template<typename T>
void destroi(PilhaDinamicaGen<T>& pilha)
{
    Nodo<T>* aux;
    while (pilha.fim != NULL)
    {
        aux = pilha.fim;
        pilha.fim = aux->prox;
        delete aux;
    }
    pilha.cardinalidade = 0;
}


template<typename T>
bool ehVazia(PilhaDinamicaGen<T> pilha)
{
    return pilha.cardinalidade == 0;
}



template<typename T>
int numeroDeElementos(PilhaDinamicaGen<T> pilha)
{
    return pilha.cardinalidade;
}

template<typename T>
int ocorrenciaElemento(PilhaDinamicaGen<T> pilha, T elemento)
{
    int qtd = 0;
    Nodo<T>* aux = pilha.fim;
    while (aux != NULL)
    {
        if (aux->elemento == elemento)
            qtd++;
        aux = aux->prox;
    }
    return qtd;
}

template<typename T>
T umElemento(PilhaDinamicaGen<T> pilha, int posicao)
{
    Nodo<T>* aux = pilha.fim;
    for (int i = 1;i < posicao;i++)
    {
        aux = aux->prox;
    }
    return aux->elemento;
}


template<typename T>
T topo(PilhaDinamicaGen<T> pilha)
{
    return pilha.fim->elemento;
}

template<typename T>
void insere(PilhaDinamicaGen<T>& pilha, T elemento)
{
    Nodo<T>* aux = new Nodo<T>;
    aux->elemento = elemento;
    aux->prox = pilha.fim;
    pilha.fim = aux;
    pilha.cardinalidade++;


}

template<typename T>
void retira(PilhaDinamicaGen<T>& pilha)
{
    Nodo<T>* aux = pilha.fim;
    pilha.fim = aux->prox;
    delete aux;
    pilha.cardinalidade--;
}


template<typename T>
void mostra(PilhaDinamicaGen<T> pilha)
{
    Nodo<T>* p = pilha.fim;
    while (p != NULL)
    {
        cout<< p->elemento <<" " ;
        p = p->prox;
    }
}
#endif // PILHADINAMICA_H_INCLUDED
