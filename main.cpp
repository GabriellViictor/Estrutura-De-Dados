#include <iostream>
#include "listaDeListas.h"

int main() {
    int op;
    char resp;
    string nome,disciplina;

    ListaDeListas<string> listaDeListas;
    criaListaDeListas(listaDeListas);

    Lista<string> listaAluno;
    criaLista(listaAluno);



    Lista<string> listaDisciplinas;
    criaLista(listaDisciplinas);






    do{
        system("cls");
        cout<<("Reorganizaco da malha aerea do pais")<<endl;
        cout<<endl;
        cout<<"1. - Insercao de aluno:"<<endl;
        cout<<"2. - Inserção de disciplina de um aluno:"<<endl;
        cout<<"3. - retirar um aluno:"<<endl;
        cout<<"4. - retirar disciplina de um aluno:"<<endl;
        cout<<"5. - mostrar todos os alunos e suas disciplinas:"<<endl;
        cout<<"6. - mostrar um aluno e suas disciplinas:"<<endl;
        cout<<"-1. - Sair"<<endl;
        cout<<"Opcao: ";
        cin>>op;
        cout<<endl;
        system("cls");

    switch(op){
        case 1:
            cin.ignore();
            cout<<"====Insercao de aluno===="<<endl;
            cout<<"Insira o nome do aluno: "<<endl;
            getline(cin,nome);

            insereElem(listaAluno,{nome});
            insereLista(listaAluno ,listaDeListas);

            break;
        case 2:
            cin.ignore();
            cout<<"====Matricula em disciplinas===="<<endl;
            cout<<"Aluno a ser matriculado: "<<endl;
            getline(cin,nome);
            cout<<"Nome da disciplina: "<<endl;
            getline(cin,disciplina);

            associaAlunoDisciplina(listaDeListas,{nome},{disciplina});


            break;
        case 3:
            cin.ignore();
            cout<<"====Retirar em Aluno===="<<endl;
            cout<<"Aluno a ser retirado: "<<endl;
            getline(cin,nome);

            retiraAluno(listaDeListas, {nome});
        break;
        case 4:
            cin.ignore();
            cout<<"====Desmatricula Aluno de Disciplinas===="<<endl;
            cout<<"Aluno a ser desmatriculado: "<<endl;
            getline(cin,nome);
            cout<<"Nome da disciplina a ser retirada: "<<endl;
            getline(cin,disciplina);
            retiraDisciplinaAluno(listaDeListas,{nome},{disciplina});
        break;
        case 5:
            cin.ignore();
            cout<<"====Mostra TODOS os alunos e suas Disciplinas===="<<endl;
            alunosEDisciplina(listaDeListas);
        break;

        case 6:
            cin.ignore();
            cout<<"===Mostra Aluno e suas Disciplinas"<<endl;
            cout<<"Insira o nome do aluno: "<<endl;
            getline(cin,nome);

            imprimirDisciplinasDeAluno(listaDeListas, {nome});


        break;

        case -1:
            exit(1);
        break;
    }


    resp = outraOp();
    }while(resp == 'S');







return 0;
}
