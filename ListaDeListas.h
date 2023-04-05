
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

    while (nodoAuxiliar != nullptr) {
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

    cout << "Aluno não encontrado!" << endl;
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

    cout << "Aluno não encontrado!" << endl;
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
                cout << "Disciplina não encontrado!" << endl;
                return;
            }

           nodoAuxiliar = nodoAuxiliar->proximoNodo;
        }
        cout << "Aluno não encontrado!" << endl;


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



char outraOp(){
    char c;
    do{
        cout<< "\nMais alguma acao? S/N" << endl;
        c = toupper(cin.get());
    }while(c != 'S' && c != 'N');
    return c;
}



/*
template<typename T>
void inserirDisciplina(ListaDeListas<T>& lista, T aluno, T disciplina) {
    Nodo<Lista<T>>* nodoAtual = lista.proximoNodo;
    while (nodoAtual != nullptr) {
        if (nodoAtual->dado == aluno) {
            // encontrou o aluno, adiciona disciplina na lista interna
            Lista<T>* listaAluno = nodoAtual->inicioNodo;
            if (listaAluno == nullptr) {
                // aluno não tem lista interna ainda, cria uma
                listaAluno = new Lista<T>{aluno, nullptr, nullptr};
                nodoAtual->inicioNodo = new Nodo<Lista<T>>{listaAluno, nullptr};
            }
            Lista<T>* disciplinasAluno = listaAluno->proximoLista;
            if (disciplinasAluno == nullptr) {
                // aluno não tem disciplinas ainda, cria uma lista para as disciplinas
                listaAluno->proximoLista = new Lista<T>{disciplina, nullptr, nullptr};
            } else {
                // percorre a lista de disciplinas do aluno até o final e adiciona a nova disciplina
                while (disciplinasAluno->proximoLista != nullptr) {
                    disciplinasAluno = disciplinasAluno->proximoLista;
                }
                disciplinasAluno->proximoLista = new Lista<T>{disciplina, nullptr, nullptr};
            }
            return;
        }
        nodoAtual = nodoAtual->proximoNodo;
    }
    // se chegou aqui, não encontrou o aluno na lista, não faz nada
}
*/




/*
template<typename T>
void insereLista(ListaDeListas<T>& listaDeListas, Lista<T>& lista) {
Lista<T>* novaLista = new Lista<T>;
novaLista->cardinalidade = 0;
novaLista->inicio = NULL;
novaLista->proximoLista = NULL;

```
if (listaDeListas.proximaLista == NULL) {
    listaDeListas.proximaLista = novaLista;
} else {
    Lista<T>* atual = listaDeListas.proximaLista;
    while (atual->proximoLista != NULL) {
        atual = atual->proximoLista;
    }
    atual->proximoLista = novaLista;
}

listaDeListas.cardinalidade++;

```

}

template <typename T>
void mostraLista(Lista<T> &lista) {
Nodo<T>* atual = lista.inicioNodo;
while (atual != NULL) {
cout << "{" << atual->dado <<"},";
atual = atual->proximoNodo;
}
}

//============================================

template <typename T>
void insereDisciplina(Lista<T> &lista, T dados) {
Nodo<T>* atual = lista.inicio;
while (atual != NULL) {
if (atual->info.dados == dados) {
// Disciplina já existe na lista, não faz nada
return;
}
atual = atual->proximo;
}

```
// Disciplina não existe na lista, insere no início
Nodo<T>* novo = new Nodo<T>;
novo->info.dados = dados;
novo->proximo = lista.inicio;
lista.inicio = novo;
lista.cardinalidade++;

```

}

bool ehListaDisciplinaVazia(ListaDisciplina lista) {
return (lista.cardinalidade == 0);
}

int numeroDeAlunos(ListaAluno lista) {
return lista.cardinalidade;
}

int numeroDeDisciplinas(ListaDisciplina lista) {
return lista.cardinalidade;
}

bool estaMatriculado(Aluno aluno, string nomeDisciplina) {
NodoDisciplina* atual = aluno.disciplinas.inicio;
while (atual != NULL) {
if (atual->disciplina.nome == nomeDisciplina) {
return true;
}
atual = atual->proximo;
}
return false;
}

void matriculaAluno(ListaAluno& listaAluno, ListaDisciplina& listaDisciplina, string nomeAluno, string nomeDisciplina) {
NodoAluno* atualAluno = listaAluno.inicio;
while (atualAluno != NULL) {
if (atualAluno->aluno.nome == nomeAluno) {
NodoDisciplina* atualDisciplina = listaDisciplina.inicio;
while (atualDisciplina != NULL) {
if (atualDisciplina->disciplina.nome == nomeDisciplina) {
if (!estaMatriculado(atualAluno->aluno, nomeDisciplina)) {
NodoDisciplina* novaDisciplina = new NodoDisciplina;
novaDisciplina->disciplina = atualDisciplina->disciplina;
novaDisciplina->proximo = atualAluno->aluno.disciplinas.inicio;
atualAluno->aluno.disciplinas.inicio = novaDisciplina;
}
return;
}
atualDisciplina = atualDisciplina->proximo;
}
}
atualAluno = atualAluno->proximo;
}
}

void removeDisciplina(ListaDisciplina& lista, string nome) {
NodoDisciplina* atual = lista.inicio;
NodoDisciplina* anterior = nullptr;
while (atual != nullptr) {
if (atual->disciplina.nome == nome) {
if (anterior == nullptr) {
lista.inicio = atual->proximo;
} else {
anterior->proximo = atual->proximo;
}
delete atual;
lista.cardinalidade--;
return;
}
anterior = atual;
atual = atual->proximo;
}

}

void removeAluno(ListaAluno& listaAluno , string nome){
NodoAluno* p = listaAluno.inicio;
NodoAluno* ant = NULL;

```
while(p != NULL){
    if(p->aluno.nome == nome){
        if(ant == NULL){
            listaAluno.inicio = p->proximo;
        }else{
            ant->proximo=p->proximo;
        }
        delete p;
        listaAluno.cardinalidade--;
        return;
    }
    ant=p;
    p= p->proximo;
}

```

}

void removeDisciplinaAluno(ListaAluno& listaAluno, string nomeAluno, string nomeDisciplina) {
NodoAluno* atual = listaAluno.inicio;
while (atual != NULL) {
if (atual->aluno.nome == nomeAluno) {
ListaDisciplina& listaDisc = atual->aluno.disciplinas;
NodoDisciplina* atualDisc = listaDisc.inicio;
NodoDisciplina* anteriorDisc = NULL;
while (atualDisc != NULL) {
if (atualDisc->disciplina.nome == nomeDisciplina) {
if (anteriorDisc == NULL) {
listaDisc.inicio = atualDisc->proximo;
} else {
anteriorDisc->proximo = atualDisc->proximo;
}
delete atualDisc;
listaDisc.cardinalidade = listaDisc.cardinalidade -1;
return;
}
anteriorDisc = atualDisc;
atualDisc = atualDisc->proximo;
}
return; // se o aluno foi encontrado, mas a disciplina não, sai da função
}
atual = atual->proximo;
}
}

void mostrarListaAlunosEDisciplinas(ListaAluno lista) {
NodoAluno* atual = lista.inicio;
while (atual != NULL) {
cout << "Aluno: " << atual->aluno.nome << endl;
NodoDisciplina* atualDisc = atual->aluno.disciplinas.inicio;
while (atualDisc != NULL) {
cout << "Disciplina: " << atualDisc->disciplina.nome << endl;
atualDisc = atualDisc->proximo;
}
atual = atual->proximo;
}
}

void mostrarListaDisciplinas(ListaDisciplina lista) {
NodoDisciplina* p = lista.inicio;
while (p != nullptr) {
cout << "Disciplina: " << p->disciplina.nome << endl;
p = p->proximo;
}
}

void listaAlunoEDisciplinas(ListaAluno listaAluno , ListaDisciplina listaDisciplina , string nome){
NodoAluno* p1 = listaAluno.inicio;
NodoDisciplina*p2 = p1->aluno.disciplinas.inicio;

```
while(p1 != NULL){
   if(p1->aluno.nome == nome){
      cout<<"Aluno : " << p1->aluno.nome <<" -";

      while(p2 != NULL){
        cout<<" Disciplinas : " << p2->disciplina.nome <<" ,"; // ver aquui para n repetir a saida de "DISCIPLINA"
        p2=p2->proximo;
      }
   }

   p1 = p1->proximo;
}

```

}

void listaDisciplinasComNumeroAlunos(ListaAluno listaAlunos, ListaDisciplina listaDisciplinas) {
NodoDisciplina* p = listaDisciplinas.inicio;
while (p != nullptr) {
int numAlunos = 0;
NodoAluno* atualAluno = listaAlunos.inicio;
while (atualAluno != nullptr) {
if (estaMatriculado(atualAluno->aluno, p->disciplina.nome)) {
numAlunos++;
}
atualAluno = atualAluno->proximo;
}

```
    ListaDisciplina listaAuxiliar;
    insereDisciplina(listaAuxiliar, p->disciplina);
    cout << p->disciplina.nome << ": " << numAlunos << " alunos\\n";

    p = p->proximo;
}

```

}
*/
#endif // LISTADELISTAS_H_INCLUDED
