#include <iostream>
#include <string>
#include <cstdlib> // atoi, atof
#include <cctype>  // isdigit
#include "PilhaDinamica.h"
#include <functional>

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

string comandoEmCaps(string comando)
{
    string c = "";
    for (int i=0 ; i< comando.length() ; i++)
    {
        c += toupper(comando[i]);
    }
    return c;
}


float pegaValor(string comando)
{
    int posIni = 0, posFim = 0;
    string numStr = "";
    bool validada;
    unsigned int i, ponto;


    posIni = comando.find("(");
    posFim = comando.find(")");
    numStr = comando.substr(posIni+1, posFim-posIni-1);
    validada = true;
    ponto = 0;
    if (numStr == "")
        validada = false;
    else if (!isdigit(numStr.at(0)) && numStr.at(0) == '-')
        validada = false;
    else
        for (i = 1; i < numStr.length(); i++)
            if (!isdigit(numStr.at(i)))
            {
                if (isdigit(numStr.at(i - 1)) && numStr.at(i) == '.' && ponto == 0)
                    ponto++;
                else
                    validada = false;
            }
    if (!validada)
        return -1;
    return stoi(numStr);
}



int main()
{
    PilhaDinamicaGen<float> pilha;
    string comando = "";
    float valor,valor_aux = 0.0;
    cria(pilha);
    bool inicializa = false;
    char resp;



        cout << "Editor de expressao aritmetica" << endl;\

        cout << "\nINICIO:              |Inicializa o programa" << endl;
        cout << "ZERA:                |Reinicia a expressao" << endl;
        cout << "SOMA(valor):         |SOMA com o valor da expressao" << endl;
        cout << "SUBTRAI(valor):      |SUBTRAI com o valor da expressao" << endl;
        cout << "MULTIPLICA(valor):   |MULTIPLICA com o valor da expressao" << endl;
        cout << "DIVIDE(valor):       |DIVIDE com o valor da expressao" << endl;
        cout << "PARCELAS:            |Exibe os valores de cada parcela da expressao aritmetica" <<endl;
        cout << "IGUAL:               |Exibe o resultado da avaliacao da expressao aritmetica "<<endl;
        cout << "FIM:                 |Finaliza a execucao"<<endl;
        cout<<"\nCOMANDO(x) OU COMANDO DIRETO PARA RESULTADOS" <<endl;
    do
    {
        cout<<endl<<"->";
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

        }
        else if (comando == "ZERA")
        {
            if(!ehVazia(pilha))
            {
                destroi(pilha);
                insere(pilha,0.0f);
                cout<<"Expressao zerada";
            }
            else
                cout<<"ERRO! PILHA JA ESTA VAZIA ";
        }
        else if(comando.find("SOMA") != string::npos)
        {

            if(inicializa)
            {
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos )
                {
                    valor = pegaValor(comando);
                    if(valor != -1 && pilha.cardinalidade != 0)
                        insere(pilha, valor+topo(pilha));
                }

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
                    if(valor != -1)
                        insere(pilha, topo(pilha)- valor);
                }
            }
            else
                cout << "Programa nao iniciado"<<endl;

        }
        else if (comando.find("MULTIPLICA") != string::npos)
        {

            if(inicializa)
            {
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos )
                {
                    valor = pegaValor(comando);
                    if(valor != -1)
                        insere(pilha, topo(pilha) * valor);
                }
                else
                    cout << "Programa nao iniciado"<<endl;

            }

        }
        else if (comando.find("DIVIDE") != string::npos)
        {

            if(inicializa)
            {
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos )
                {
                    valor = pegaValor(comando);
                    if(valor != -1)
                        insere(pilha, topo(pilha) / valor);
                }
                else
                    cout << "Programa nao iniciado"<<endl;

            }
        }
        else if (comando == "PARCELAS")
        {
            mostra(pilha);
        }
        else if (comando == "IGUAL")
        {
            cout<<"RESULTADO: "<<topo(pilha);
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


