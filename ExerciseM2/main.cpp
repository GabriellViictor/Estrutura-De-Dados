
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





    return 0;
}
