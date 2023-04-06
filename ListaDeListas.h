#ifndef LISTADELISTAS_H_INCLUDED
#define LISTADELISTAS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Nodo {
    T dado;
    Nodo<T>* proximoNodo;

};

template<typename T>
struct Lista {
    Nodo<T>* inicioNodo;
    Lista<T>* proximoLista;
    int cardinalidade;
    T dado;
};

template<typename T>
struct ListaDeListas {
    int cardinalidade;
    Nodo<Lista<T>>* proximoNodo;
};

//===================================================================================

template<typename T>
void criaListaDeListas(ListaDeListas<T> &listaDeListas){
    listaDeListas.cardinalidade = 0;
    listaDeListas.proximoNodo = NULL;
}

template<typename T>
void criaLista(Lista<T> &lista){
    lista.cardinalidade = 0;
    lista.inicioNodo = NULL;
}

template <typename T>
void insereElem(Lista<T> &lista, T dado) {
    Nodo<T>* novo = new Nodo<T>;
    novo->dado = dado;
    novo->proximoNodo = lista.inicioNodo;
    lista.inicioNodo = novo;
    lista.cardinalidade++;
}

template <typename T>
void ehVazia(ListaDeListas<T> listaDeListas) {
    return listaDeListas.cardinalidade == 0;
}

template <typename T>
void numeroElementos(ListaDeListas<T> listaDeListas) {
    return listaDeListas.cardinalidade;
}

template <typename T>
void mostraLista(Lista<T> &lista) {
    Nodo<T>* atual = lista.inicioNodo;
        while (atual != NULL) {
            cout << "{" << atual->dado <<"},";
            atual = atual->proximoNodo;
        }
}

template <typename T>
void insereLista(Lista<T> lista , ListaDeListas<T> &listaDeListas) {
    Nodo<Lista<T>>* novo = new Nodo<Lista<T>>;
    novo->dado = lista;
    novo->proximoNodo = listaDeListas.proximoNodo;
    listaDeListas.proximoNodo = novo;
    listaDeListas.cardinalidade++;
}

template <typename T>
void imprimir(ListaDeListas<T> lista_principal) {
    Nodo<Lista<T>>* atual = lista_principal.proximoNodo;
    int i = 0;
    while (atual != NULL) {
        cout << "Lista " << i++ << ": ";
        Nodo<T>* atual_secundario = atual->dado.inicioNodo;
        while (atual_secundario != NULL) {
            cout << atual_secundario->dado << " ";
            atual_secundario = atual_secundario->proximoNodo;
        }
        cout << endl;
        atual = atual->proximoNodo;
    }
}

template <typename T>
void associaAlunoDisciplina(ListaDeListas<T>& lista_principal, T nomeAluno, T disciplina) {
    Nodo<Lista<T>>* nodoAuxiliar = lista_principal.proximoNodo;

    while (nodoAuxiliar != NULL) {
        if (nodoAuxiliar->dado.dado == nomeAluno) {

            insereElem(nodoAuxiliar->dado, disciplina);
            return;
        }
        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }

    Lista<T> novaLista;
    novaLista.inicioNodo = NULL;
    novaLista.cardinalidade = 0;
    novaLista.dado = nomeAluno;

    insereElem(novaLista, disciplina);
    insereLista(novaLista, lista_principal);
}




template<typename T>
void imprimirDisciplinasDeAluno(ListaDeListas<T>& listaDeListas, T nomeAluno) {
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;

    while (nodoAuxiliar != NULL) {
        if (nodoAuxiliar->dado.dado == nomeAluno) {
            Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;
            cout<<"-Aluno: "<<nomeAluno <<"\n  Disciplinas :";
            while (nodoDisciplina != NULL) {
                cout<<nodoDisciplina->dado <<" ";
                nodoDisciplina = nodoDisciplina->proximoNodo;
            }
            cout<<endl;
            return;
        }

        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }

    cout << "Aluno nao encontrado!" << endl;
}


template<typename T>
void alunosEDisciplinas(ListaDeListas<T>& listaDeListas) {
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;

    cout<<"Alunos e suas disciplinas"<<endl;
    while (nodoAuxiliar != NULL) {
            Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;

            cout<<"Aluno: "<< nodoAuxiliar->dado.dado <<"-Disciplinas :";
            while (nodoDisciplina != NULL) {

                cout<<nodoDisciplina->dado <<" ";
                nodoDisciplina = nodoDisciplina->proximoNodo;
            }
            cout<<endl;


        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }

    cout << "Aluno nao encontrado!" << endl;
}

template<typename T>
void alunosEDisciplina(ListaDeListas<T>& listaDeListas) {
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;

    while (nodoAuxiliar != NULL) {
        if(nodoAuxiliar->dado.dado != ""){
            imprimirDisciplinasDeAluno(listaDeListas,nodoAuxiliar->dado.dado );

        }
        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }
}


template<typename T>
void retiraDisciplinaAluno(ListaDeListas<T>& listaDeListas, T nomeAluno , T disciplina) {
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;

        while (nodoAuxiliar != NULL) {
            if (nodoAuxiliar->dado.dado == nomeAluno) {
                Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;
                Nodo<T>* nodoAnt = NULL;
                while (nodoDisciplina != NULL) {
                    if(nodoDisciplina->dado == disciplina){
                        if(nodoAnt == NULL)
                        {
                            nodoAuxiliar->dado.inicioNodo = nodoDisciplina->proximoNodo;
                        }else{
                            nodoAnt->proximoNodo = nodoDisciplina->proximoNodo;
                        }
                        delete nodoDisciplina;
                        return;
                    }
                    nodoAnt = nodoDisciplina;
                    nodoDisciplina = nodoDisciplina->proximoNodo;

                }
                cout << "Disciplina nao encontrado!" << endl;
                return;
            }

           nodoAuxiliar = nodoAuxiliar->proximoNodo;
        }
        cout << "Aluno nao encontrado!" << endl;


}

template<typename T>
void retiraAluno(ListaDeListas<T>& listaDeListas, T nomeAluno) {
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;
    Nodo<Lista<T>>* nodoAnt = NULL;

        while (nodoAuxiliar != NULL) {

            if (nodoAuxiliar->dado.dado == nomeAluno) {
                Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;
                while(nodoDisciplina != NULL){
                    Nodo<T>* temp = nodoDisciplina;
                    nodoDisciplina = nodoDisciplina->proximoNodo;
                    delete temp;
                }

                if(nodoAnt == NULL)
                        {
                           listaDeListas.proximoNodo = nodoAuxiliar->proximoNodo;
                        }else{
                            nodoAnt->proximoNodo = nodoAuxiliar->proximoNodo;
                        }
                        delete nodoAuxiliar;
                        return;
                    }
                nodoAnt = nodoAuxiliar;
            nodoAuxiliar = nodoAuxiliar->proximoNodo;

            }

        cout << "Aluno nao encontrada !" << endl;
}

/*
template<typename T>
void contagemAlunosCursando(ListaDeListas<T> listaDeListas , Lista<T> listaDisciplinas){
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;
    Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;
    Lista<T> novaLista;

    while(nodoAuxiliar != NULL){

        while(nodoDisciplina != NULL){
            Nodo<T>* nodoAnt = NULL;

            if(nodoDisciplina->dado == listaDisciplinas.dado){

                novaLista.dado = nodoDisciplina->dado;
            }
            nodoAnt = nodoDisciplina;
            nodoDisciplina = nodoDisciplina->proximoNodo;
        }

        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }


    novaLista.inicioNodo = NULL;
    novaLista.cardinalidade = 0;


    insereElem(novaLista, "PASSAR DADO AQUI");
    insereLista(novaLista, listaDeListas);


}

*/
/*
template<typename T>
void contagemAlunosCursando(ListaDeListas<T>& listaDeListas) {
    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;

    while (nodoAuxiliar != NULL) {
        int numAlunos = 0;
        Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;

        while (nodoDisciplina != NULL) {
            numAlunos++;
            nodoDisciplina = nodoDisciplina->proximoNodo;
        }

        cout << "Disciplina " << nodoAuxiliar->dado.dado << " tem " << numAlunos << " alunos cursando." << std::endl;

        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }
}
*/

/*
template<typename T>
void contagemAlunosCursando(ListaDeListas<T>& listaDeListas) {
    ListaDeListas<T> listaDisciplinas;
    listaDisciplinas.cardinalidade = 0;
    listaDisciplinas.proximoNodo = NULL;

    Nodo<Lista<T>>* nodoAuxiliar = listaDeListas.proximoNodo;
    while(nodoAuxiliar != NULL) {
        Nodo<T>* nodoDisciplina = nodoAuxiliar->dado.inicioNodo;
        while(nodoDisciplina != NULL) {
            Nodo<Lista<T>>* nodoDisciplinaLista = listaDisciplinas.proximoNodo;
            while(nodoDisciplinaLista != NULL && nodoDisciplinaLista->dado.dado != nodoDisciplina->dado) {
                nodoDisciplinaLista = nodoDisciplinaLista->proximoNodo;
            }
            if(nodoDisciplinaLista == NULL) {
                Lista<T> novaLista;
                novaLista.inicioNodo = NULL;
                novaLista.cardinalidade = 0;
                novaLista.dado = nodoDisciplina->dado;
                insereLista(novaLista, listaDisciplinas);
                nodoDisciplinaLista = listaDisciplinas.proximoNodo;
            }
            nodoDisciplinaLista->dado.cardinalidade += 1;
            nodoDisciplina = nodoDisciplina->proximoNodo;
        }
        nodoAuxiliar = nodoAuxiliar->proximoNodo;
    }

    // Imprime a lista de disciplinas com a contagem de alunos
    Nodo<Lista<T>>* nodoDisciplinaLista = listaDisciplinas.proximoNodo;
    while(nodoDisciplinaLista != NULL) {
        cout << nodoDisciplinaLista->dado.dado << ": " << nodoDisciplinaLista->dado.cardinalidade << endl;
        nodoDisciplinaLista = nodoDisciplinaLista->proximoNodo;
    }
}
*/
/*
template<typename T>
bool existeElemento(ListaSimplesmenteEncadeada<T> lista, T elemento)
{
    Nodo<T> *p = lista.inicio;
    while (p != NULL){
        if (p->elemento == elemento)
            return true;
        p = p->proximo;
    }
 return false;
}
*/

template<typename T>
bool existeElemento(ListaDeListas<T>& listaDeListas, T elemento) {
    Nodo<Lista<T>>* p = listaDeListas.proximoNodo;

    while (p != NULL) {
        Nodo<T>* paux = p->dado.inicioNodo;

        while (paux != NULL) {
            if (paux->dado == elemento) {
                return true;
            }
            paux = paux->proximoNodo;
        }

        p = p->proximoNodo;
    }

    return false;
}


template<typename T>
bool existeElementoAssociado(ListaDeListas<T>& listaDeListas, T elementoLista, T elementoAssociado) {
    Nodo<Lista<T>>* p = listaDeListas.proximoNodo;

    while (p != NULL) {
        if (p->dado.dado == elementoLista) {
            Nodo<T>* paux = p->dado.inicioNodo;

            while (paux != NULL) {
                if (paux->dado == elementoAssociado) {
                    return true;
                }
                paux = paux->proximoNodo;
            }

            break;
        }

        p = p->proximoNodo;
    }

    return false;
}




char outraOp(){
    char c;
    do{
        cout<< "\nMais alguma acao? S/N" << endl;
        c = toupper(cin.get());
    }while(c != 'S' && c != 'N');
    return c;
}


#endif // LISTADELISTAS_H_INCLUDED
