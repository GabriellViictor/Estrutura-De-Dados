#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

using namespace std;
#include <iostream>

using namespace std;

template<typename T>
struct Nodo
{
    T elemento;
    Nodo<T> *prox;
};

template<typename T>
struct Pilha
{
    int cardinalidade;
    Nodo<T> *fim;
};


template<typename T>
void cria(Pilha<T>& pilha)
{
    pilha.cardinalidade = 0;
    pilha.fim = NULL;
}

template<typename T>
void destroi(Pilha<T>& pilha)
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
bool ehVazia(Pilha<T> pilha)
{
    return pilha.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(Pilha<T> pilha)
{
    return pilha.cardinalidade;
}

template<typename T>
int ocorrenciaElemento(Pilha<T> pilha, T elemento)
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
T umElemento(Pilha<T> pilha, int posicao)
{
//verificar entrada, nao pode ser maior q cardinalidade da pilha
    Nodo<T>* aux = pilha.fim;
    for (int i = 1;i < posicao;i++)
    {
        aux = aux->prox;
    }
    return aux->elemento;
}


template<typename T>
T topo(Pilha<T> pilha)
{
    return pilha.fim->elemento;
}

template<typename T>
void insere(Pilha<T>& pilha, T elemento)
{
    Nodo<T>* aux = new Nodo<T>;
    aux->elemento = elemento;
    aux->prox = pilha.fim;
    pilha.fim = aux;
    pilha.cardinalidade++;
}

template<typename T>
void retira(Pilha<T>& pilha)
{
//verificar entrada, cardinalidade nao pode ser 0
    Nodo<T>* aux = pilha.fim;
    pilha.fim = aux->prox;
    delete aux;
    pilha.cardinalidade--;
}

template<typename T>
void mostra(Pilha<T> pilha)
{
    Nodo<T>* p = pilha.fim;
    while (p != NULL)
    {
        cout << p->elemento << endl;
        p = p->prox;
    }
}


#endif // PILHADINAMICA_H_INCLUDED
