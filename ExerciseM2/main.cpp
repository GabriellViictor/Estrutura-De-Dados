#include <iostream>
#include <time.h>
#include "filas.h"

using namespace std;

int main()
{
/*
    FilaEstaticaGenerica<int,10> filaPassageiros, filaTaxis;
    int tempoChegada  , tempoEspera=0, taxisUtilizados = 0 , passageirosAtendido = 0 ;

    srand(time(NULL));

    cria(filaPassageiros);
    cria(filaTaxis);

    for(int i = 1; i<= 10 * 60;i++){

        if(i % 3 == 0)
            for(int j = 1;j<rand()%3;j++)
                insere(filaPassageiros,i);
        if(i % 5 == 0)
            for(int j=1;j<rand()%4;j++)
                insere(filaTaxis,1);
        if((ehVazia(filaPassageiros) == false) && (ehVazia(filaTaxis)== false)){
            retira(filaTaxis);
            taxisUtilizados++;
            tempoChegada = primeiro(filaPassageiros);
            retira(filaPassageiros);
            passageirosAtendido++;
            tempoEspera += i - tempoChegada;
        }
    }

    cout<<"TEMPO MEDIO DE ESPERA: " << ((float) tempoEspera/(float)passageirosAtendido)<<endl;

    cout<<"taxis usados : "<<taxisUtilizados;

*/

/*
    FilaEstaticaGenerica<int,100>filaCinema;
    int numeroDePessoas = 0, pessoasQueVieramAssistirOFilme = 0;

    srand(time(NULL));

    for(int i = 1;i <= 12;i++)
        insere(filaCinema,1);
    numeroDePessoas = 12;

    for(int i = 1;i <= 45 * 60;i++){
        if(i % 60 == 0){
            numeroDePessoas = rand()%3 + 2;
            pessoasQueVieramAssistirOFilme += numeroDePessoas;

            for(int j = 1;j<=numeroDePessoas;j++)
                insere(filaCinema,1);
        }

        if(i % 30 == 0)
            if(!ehVazia(filaCinema))
                retira(filaCinema);

    }

    cout << "pessoas que vieram assistir o filme = " << pessoasQueVieramAssistirOFilme << "\nquantidade de pessoas na fila quando o filme comecou = " << numeroDeElementos(filaCinema);
 return 0;


*/

    FilaEstaticaGenerica<int,100> fila[3];
    int processosExecutados[3],numero;
    bool particao[3];
    int j=0;

    srand(time(NULL));

    for(int i = 0; i<3;i++){
        cria(fila[i]);
        particao[i]=false;
        processosExecutados[i] = 0;
    }

    for(int i=1;i<=100;i++){
        numero = rand()%101;
        if(numero<=25)
            insere(fila[0],1);
        else if(numero<=39)
            insere(fila[1],1);
        else if(numero<=49)
            insere(fila[2],1);
        else if(numero<=75){
            particao[0] = false;
            if(!ehVazia(fila[0])){
                retira(fila[0]);
                processosExecutados[0] = true;
                particao[0]++;
            }
        }
        else if(numero<=89){
            particao[1] = false;
            if(!ehVazia(fila[1])){
                retira(fila[1]);
                processosExecutados[1] = true;
                particao[1]++;
            }
        }
        else if(numero<=100){
            particao[2] = false;
            if(!ehVazia(fila[2])){
                retira(fila[2]);
                processosExecutados[2] = true;
                particao[2]++;
            }
        }

        if(i % 5 == 0){
            for(j=0;j<=3;j++)
                cout<<"fila" << j+1 << " = "<< numeroDeElementos(fila[j])<<endl;
            for(j=0;j<3;j++){
                cout<<"particao";
                switch(j){

                    case 0:
                        cout<<"A";
                    break;
                    case 1:
                        cout<<"B";
                    break;
                    case 2:
                        cout<<"C";
                    break;

                }
                particao[j] == false? cout <<"livre":cout<<"ocupada";
                cout<<endl;
            }
            for(j=0;j<3;j++){
                cout<<"processos executados ";
                switch(j){

                    case 0:
                        cout<<"A";
                    break;
                    case 1:
                        cout<<"B";
                    break;
                    case 2:
                        cout<<"C";
                    break;

                }
                cout<< processosExecutados[j] <<endl;
        }


        cout << endl;



    }

    }





    return 0;
}
