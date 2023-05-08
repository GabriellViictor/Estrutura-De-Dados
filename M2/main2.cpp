#include <iostream>
#include <string>
#include <cstdlib> // atoi, atof
#include <cctype>  // isdigit
#include "PilhaDinamica.h"

using namespace std;

char outraOp()
{
    char c;
    do
    {
        cout << "Tem certeza que deseja sair? [S/N]" << endl;
        c = toupper(cin.get());
    }
    while(c != 'S' && c != 'N');
    return c;
}

string comandoEmCaps(string comando){
    string c = "";
    for (int i=0 ; i< comando.length() ;i++) {
        c += toupper(comando[i]);
    }
    return c;
}


/*
int pegaNum(string comando)
{
    string valor = "";


    int pos_abertura = comando.find("(");
    if (pos_abertura != string::npos)
    {
        int pos_fechamento = comando.find(")", pos_abertura);
        if (pos_fechamento != string::npos)
        {
            valor = comando.substr(pos_abertura + 1, pos_fechamento - pos_abertura - 1);
            cout << "Valor dentro dos parenteses: " << valor <<endl;
        }
    }
    return stoi(valor);

}
*/

float pegaValor(string comando)
{
    int posIni = 0, posFim = 0;
    string numStr = "";
    bool validada;
    unsigned int i, ponto;
    bool erroDeSintaxe = false, inicio = false;


    posIni = comando.find("(");
    posFim = comando.find(")");
    numStr = comando.substr(posIni+1, posFim-posIni-1);
    validada = true;
    ponto = 0;
    if (numStr == "") // se for string vazia
        validada = false;
    else if (!isdigit(numStr.at(0)) && numStr.at(0) == '-') // se não for digito/sinal
        validada = false;
    else
        for (i = 1; i < numStr.length(); i++) // “varre” posicao a posicao
            if (!isdigit(numStr.at(i)))
            {
                // se não for digito
                if (isdigit(numStr.at(i - 1)) && numStr.at(i) == '.' && ponto == 0)
                    // verifica se eh ponto com um digito antes
                    ponto++; // permite um ponto apenas
                else
                    validada = false;
            }
    if (!validada)
        return -1;
    return stoi(numStr);
}



int main()
{
    Pilha<float> pilha;
    string comando = "";
    float valor;
    cria(pilha);
    //Pilha expressao;
    //expressao.cria;
    bool sintaxeErro = false, inicializa = false;
    char resp;



    cout << "Editor de expressao aritmetica" << endl;
    do
    {


        cout << "\nINICIO:             |Inicializa o programa" << endl;
        cout << "ZERA:               |Reinicia a expressao" << endl;
        cout << "SOMA(valor):        |SOMA com o valor da expressao" << endl;
        cout << "SUBTRAI(valor):     |SUBTRAI com o valor da expressao" << endl;
        cout << "MULTIPLICA(valor):  |MULTIPLICA com o valor da expressao" << endl;
        cout << "DIVIDE(valor):      |DIVIDE com o valor da expressao" << endl;
        cout << "PARCELAS:           |Exibe os valores de cada parcela da expressao aritmetica" <<endl;
        cout << "IGUAL:              |Exibe o resultado da avaliacao da expressao aritmetica "<<endl;
        cout << "FIM:                |Finaliza a execucao"<<endl;
        cout <<endl<< "# ";
        getline(cin,comando);
        comando = comandoEmCaps(comando);

        if(comando == "FIM" )
        {
            cin.ignore();

            resp = outraOp();
            if(resp == 'S')
                comando = "FIM";
        }
        else if (comando.find("INICIO") != string::npos)
        {

            if(ehVazia(pilha))
            {
                cria(pilha);
                inicializa = true;
                insere(pilha,0.0f);
                cout<<"Pilha inicializada";
            }
            else
            {
                cout<<"ERRO! PILHA JA EXISTENTE"<<endl;
            }


            //consultar se a pilha expressao esta vazia
            //se sim inicia com zero
            //se nao da erro de pilha ja existe
        }
        else if (comando == "ZERA")
        {
            if(!ehVazia(pilha)){
                destroi(pilha);
                insere(pilha,0.0f);
                cout<<"Expressao zerada";
            }
            //pergunta se tem certeza
            //se sim remove todos os elementos da pilha e reinicia com zero
        }
        else if(comando.find("SOMA") != string::npos)
        {

            if(inicializa)
            {
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos )
                {
                    valor = pegaValor(comando);
                    cout<<"VALOR: "<<valor;
                    if(valor == -1)
                        sintaxeErro = true;
                    else
                    {
                        insere(pilha, valor+topo(pilha));
                    }
                }
                else
                    sintaxeErro = true;
            }
            else
                cout << "Programa nao iniciado"<<endl;
        }
        else if (comando.find("SUBTRAI") != string::npos)
        {
            if(inicializa)
            {
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos )
                {
                    valor = pegaValor(comando);
                    if(valor == -1)
                        sintaxeErro = true;
                    else
                    {
                        insere(pilha, topo(pilha)- valor);
                    }
                }
                else
                    sintaxeErro = true;
            }
            else
                cout << "Programa nao iniciado"<<endl;

            //pega o topo da pilha, subtrai com valor e insere o resultado na pilha novamente
        }
        else if (comando.find("MULTIPLICA") != string::npos){

            valor = pegaValor(comando);
            insere(pilha,topo(pilha) * valor);

            //pega o topo da pilha, multiplica com valor e insere o resultado na pilha novamente
        }
        else if (comando.find("DIVIDE") != string::npos){

            valor = pegaValor(comando);
            insere(pilha,topo(pilha) / valor);
            //pega o topo da pilha, divide com valor e insere o resultado na pilha novamente
        }
        else if (comando.find("PARCELAS") != string::npos)
        {
            mostra(pilha);
            //exibe toda a pilha
        }
        else if (comando.find("IGUAL") != string::npos )
        {
            cout<<"RESULTADO: "<<topo(pilha);
            //exibe apenas o topo da pilha
        }
        else
        {
            system("cls");
            cout<<"COMANDO INVALIDO DIGITE NOVAMENTE"<<endl;

        }

    }
    while(comando != "FIM");

    return 0;
}
