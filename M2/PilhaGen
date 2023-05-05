#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED



using namespace std;


template<typename T >
struct PilhaDinamicaGen
{
    int cardinalidade;
    T* elementos;
};

template<typename T>
void cria(PilhaDinamicaGen<T> &pilha){ // CRIA OK
    pilha.cardinalidade = 0;
    pilha.elementos = new T;
}

template<typename T>
void insere (PilhaDinamicaGen<T> &pilha, T elemento) // EMPILHA
{
    pilha.elementos[pilha.cardinalidade] = elemento;
    pilha.cardinalidade++;
}


template<typename T>
void mostra (PilhaDinamicaGen<T> pilha)
{
    for (int i = 0; i < pilha.cardinalidade; i++)
        cout << pilha.elementos[i] << " ";
    cout << endl;
}

template<typename T>
bool ehVazia (PilhaDinamicaGen<T> pilha){
    return pilha.cardinalidade == 0;
}

template<typename T>
T umElemento (PilhaDinamicaGen<T> pilha, int posicao){
    if(posicao < 1 || posicao > pilha.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    return pilha.elementos[pilha.cardinalidade - posicao];
}

template<typename T>
T topo (PilhaDinamicaGen<T> pilha){
    return pilha.elementos[pilha.cardinalidade - 1];
}

template<typename T>
void retira (PilhaDinamicaGen<T> &pilha) // DESEMPILHA
{
    if(pilha.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    pilha.cardinalidade--;
}

template<typename T>
void ocorrenciaElemento (PilhaDinamicaGen<T> pilha, T elemento){
    int cont = 0;
    for (int i = 0; i < pilha.cardinalidade; i++)
        if (pilha.elementos[i] == elemento)
            cont++;
    cout<<"O elemento: " << elemento << ", apareceu " << cont << " vezes.";
}

template<typename T>
void destroi(PilhaDinamicaGen<T> &pilha)
{
    delete[] pilha.elementos;
    pilha.elementos = NULL;
    pilha.cardinalidade = 0;
}

template<typename T>
int numeroDeElementos (PilhaDinamicaGen<T> pilha){
    return pilha.cardinalidade;
}


/*

template<typename T, int MAX>
bool temEspaco (PilhaDinamicaGen<T, MAX> pilha){
    return pilha.cardinalidade < MAX;
}





template<typename T, int MAX>
int existePosicao (PilhaDinamicaGen<T, MAX> pilha, int posicao){
    return (posicao >= 1) && (posicao <= pilha.cardinalidade);
}


template<typename T, int MAX>
int posicao (PilhaDinamicaGen<T, MAX> pilha, T elemento){
    if (!existeElemento(pilha, elemento))
    {
        throw "ELEMENTO NAO ESTA NA pilha";
    }
    for (int i = 0; i < pilha.cardinalidade; i++)
        if (pilha.elementos[i] == elemento)
            return pilha.cardinalidade - i;
}

template<typename T, int MAX>
T topo (PilhaDinamicaGen<T, MAX> pilha){
    return pilha.elementos[pilha.cardinalidade - 1];
}


template<typename T, int MAX>
void retira (PilhaDinamicaGen<T, MAX> &pilha)
{
    if(pilha.cardinalidade == 0)
    {
        throw "UNDERFLOW";
    }
    pilha.cardinalidade--;
}


*/




#endif // PILHADINAMICA_H_INCLUDED
