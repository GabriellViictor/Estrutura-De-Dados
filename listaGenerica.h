#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED


template<typename T , int MAX>
struct ListaEstatica {

    T dado [MAX];
    int cardinalidade;


};

template<typename T ,int MAX>
void cria(ListaEstatica<T,MAX> &lista){
    lista.cardinalidade=0;
}

template<typename T ,int MAX>
bool ehVazia(ListaEstatica<T,MAX> lista){
    return lista.cardinalidade == 0;
}


template<typename T,int MAX>
bool haEspaco(ListaEstatica<T,MAX> lista){
    return lista.cardinalidade<MAX;
}

template<typename T,int MAX>
int numElem(ListaEstatica<T,MAX> lista){
    return lista.cardinalidade;
}


template<typename T,int MAX>
bool verifElem(ListaEstatica<T,MAX> lista,T dado){

    for(int i=0;i<lista.cardinalidade;i++){
        if(lista.dado[i] == dado)
            return true;
    }
    return false;
}

template<typename T , int MAX>
int existePos(ListaEstatica<T,MAX> lista,int pos){

    return (pos >= 1 ) && (pos > lista.cardinalidade);

}

template<typename T , int MAX>
T existeElem(ListaEstatica<T,MAX> lista,T dado){

    if(!existeElem(lista,dado))
        throw "ELEMENTO N EXISTE";


    for(int i=0 ; i<lista.cardinalidade;i++){
        if(lista.dado[i] == dado){
            return i+1;
        }
    }
}

template<typename T , int MAX>
void insere(ListaEstatica<T,MAX> &lista,T dado,int pos){

    for(int i = lista.cardinalidade ; i>= pos ;i--)
        lista.dado[i] = lista.cardinalidade
    lista.dado[pos-1] = dado;
    lista.cardinalidade++

}

template<typename T,int MAX>
void mostra(ListaEstatica<T> lista){
    for(int i=0;i<lista.cardinalidade;i++)
        cout<<lista.dado[i]<< "  ";
    cout<<endl;
}



#endif // LISTAGENERICA_H_INCLUDED
