#include <iostream>
#include "listaDeListas.h"

int main() {
    ListaDeListas<string> listaDeListas;
    criaListaDeListas(listaDeListas);

    Lista<string> listaAluno;
    criaLista(listaAluno);
   // listaAluno.dado = "Alunos";


    Lista<string> listaDisciplinas;
    criaLista(listaDisciplinas);
    //listaDisciplinas.dado = "Disciplinas";




    insereElem(listaAluno,{"JOAO"});
    insereElem(listaAluno,{"Maria"});

    insereLista(listaAluno ,listaDeListas);

    insereElem(listaDisciplinas, {"Matematica"});
    insereElem(listaDisciplinas, {"Fisica"});
    insereElem(listaDisciplinas, {"Quimica"});
    insereElem(listaDisciplinas, {"Historia"});

    //insereLista(listaDisciplinas, listaDeListas);



    cout<<"mostrar lista disciplinas"<<endl;

    mostraLista(listaDisciplinas);
    cout<<endl;

    cout<<"mostrar lista aluno "<<endl;
    mostraLista(listaAluno);
    cout<<endl;

    associaAlunoDisciplina(listaDeListas,{"JOAO"},{"Matematica"});
    associaAlunoDisciplina(listaDeListas,{"JOAO"},{"Matematica"});

    associaAlunoDisciplina(listaDeListas,{"Maria"},{"Fisica"});
    associaAlunoDisciplina(listaDeListas,{"Maria"},{"Historia"});

    cout<<endl;

    cout<<"mostrar aluno e suas disciplinas"<<endl;

    imprimirDisciplinasDeAluno(listaDeListas, {"JOAO"});

    cout<<"mostrar aluno e suas disciplinas"<<endl;

    imprimirDisciplinasDeAluno(listaDeListas, {"Maria"});



    cout<<endl;

    cout<<"mostrar todos os alunos e suas disciplinas"<<endl;
    alunosEDisciplina(listaDeListas);

    cout<<endl;



    cout<<"mostrar tudo dentro da lista principal"<<endl;

    imprimir(listaDeListas);






/*
// inserir alguns alunos
Aluno aluno1 = {"Joao"};
Aluno aluno2 = {"Maria"};
insereAluno(listaAluno, aluno1);
insereAluno(listaAluno, aluno2);

// inserir algumas disciplinas
Disciplina disciplina1 = { "Calculo I"};
Disciplina disciplina2 = { "Calculo II" };
Disciplina disciplina3 = { "Calculo III" };
insereDisciplina(listaDisciplina, disciplina1);
insereDisciplina(listaDisciplina, disciplina2);
insereDisciplina(listaDisciplina, disciplina3);

// matricular aluno1 em disciplina1 e disciplina2
matriculaAluno(listaAluno, listaDisciplina, "Maria", "Calculo I");
matriculaAluno(listaAluno, listaDisciplina, "Maria", "Calculo III");

matriculaAluno(listaAluno, listaDisciplina, "Joao", "Calculo I");
matriculaAluno(listaAluno, listaDisciplina, "Joao", "Calculo II");

// mostrar lista de alunos
cout<<"\\nLISTA ALUNOS\\n";

mostrarListaAlunos(listaAluno);

 cout<<"\\nLISTA ALUNO e SUA DISCIPLINA\\n";

listaAlunoEDisciplinas(listaAluno,listaDisciplina,"Maria");

cout<<"\\nREMOVE ALUNOS\\n";

//removeAluno(listaAluno,"Maria");
mostrarListaAlunos(listaAluno);

cout<<"\\nLISTA DISCIPLINAS\\n";
// mostrar lista de disciplinas
mostrarListaDisciplinas(listaDisciplina);

cout<<"\\nNUMERO DE ALUNOS MATRICULADOS\\n";
listaDisciplinasComNumeroAlunos(listaAluno,listaDisciplina);

// remover disciplina2
removeDisciplina(listaDisciplina,"Calculo I");

cout<<"\\nLISTA APOS REMOCAO\\n";

mostrarListaDisciplinas(listaDisciplina);

// mostrar lista de disciplinas novamente
//mostrarListaDisciplinas(listaDisciplina);

cout<<"\\nLISTA DE ALUNOS E DISCIPLINAS\\n";
mostrarListaAlunosEDisciplinas(listaAluno);

removeDisciplinaAluno(listaAluno, "Joao", "Calculo I");

cout<<"\\nLISTA DE ALUNOS E DISCIPLINAS\\n";
mostrarListaAlunosEDisciplinas(listaAluno);



*/
return 0;
}
