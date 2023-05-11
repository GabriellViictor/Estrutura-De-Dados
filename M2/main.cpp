#include <iostream>
#include "PilhaDinamica.h"
#include <cstdlib>
#include <cctype>
#include <string>
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
    for (unsigned int i=0 ; i< comando.length() ; i++)
    {
        c += toupper(comando[i]);
    }
    return c;
}

float pegaFloat(string comando)
{
    int  primParent = comando.find("(") , segParent = comando.find(")");
    string strNum ;
    bool flag = true;
    unsigned int i, pnt = 0;

    strNum = comando.substr(primParent + 1, segParent - primParent - 1);

    if (strNum.empty())
    {
        flag = false;
    }
    else if (!isdigit(strNum[0]) && strNum[0] != '-')
    {
        flag = false;
    }
    else
    {
        for (i = 1; i < strNum.length(); i++)
        {
            if (!isdigit(strNum[i]))
            {
                if (isdigit(strNum[i - 1]) && strNum[i] == '.' && pnt == 0)
                {
                    pnt++;
                }
                else
                {
                    flag = false;
                }
            }
        }
    }

    if (!flag)
    {
        return -1;
    }

    return stof(strNum);
}






int main()
{
    PilhaDinamicaGen<float> pilha;
    string comando = "";
    float valor;
    char resp;
    bool inicializa = false;




    cout << "----------------------CALCULADORA DE EXPRESSOES----------------------" << endl;


    cout << "\nINICIO:              |Inicializa o programa" << endl;
    cout << "ZERA:                |Reinicia a expressao" << endl;
    cout << "SOMA(valor):         |SOMA com o valor da expressao" << endl;
    cout << "SUBTRAI(valor):      |SUBTRAI com o valor da expressao" << endl;
    cout << "MULTIPLICA(valor):   |MULTIPLICA com o valor da expressao" << endl;
    cout << "DIVIDE(valor):       |DIVIDE com o valor da expressao" << endl;
    cout << "PARCELAS:            |Exibe os valores de cada parcela da expressao aritmetica" <<endl;
    cout << "IGUAL:               |Exibe o resultado da avaliacao da expressao aritmetica "<<endl;
    cout << "FIM:                 |Finaliza a execucao"<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;

    cout<<"\nCOMANDO(x) OU COMANDO DIRETO PARA RESULTADOS" <<endl;
    do
    {
        cout<<endl<<"->";
        getline(cin,comando);
        comando = comandoEmCaps(comando);


        if(comando == "FIM" )
        {

            resp = outraOp();
            if(resp == 'S')
                comando = "FIM";
        }
        else if (comando.find("INICIO") != string::npos)
        {

            if(!inicializa)
            {
                cria(pilha);
                inicializa = true;
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
                inicializa = false;
                destroi(pilha);
                cout<<"Expressao zerada, INICIE A EXPRESSAO NOVAMENTE";
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
                    valor = pegaFloat(comando);
                    if(valor != -1 ){
                        if (!ehVazia(pilha))
                            insere(pilha, valor+topo(pilha));
                        else
                            insere(pilha, valor);
                    }else
                        cout << "ERRO! , VALOR NAO ACEITO"<< endl;

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
                    valor = pegaFloat(comando);
                    if(valor != -1 && !ehVazia(pilha) != 0)
                        insere(pilha, topo(pilha)- valor);
                    else if(valor != -1)
                        insere(pilha, valor*-1);
                }else
                    cout << "ERRO! , VALOR NAO ACEITO"<< endl;
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
                    valor = pegaFloat(comando);
                    if(valor != -1 ){
                        if (!ehVazia(pilha))
                            insere(pilha, valor * topo(pilha));
                        else
                            insere(pilha, valor);
                    }else
                        cout << "ERRO! , VALOR NAO ACEITO"<< endl;
                }

            }
            else
                cout << "Programa nao iniciado"<<endl;

        }
        else if (comando.find("DIVIDE") != string::npos)
        {

            if(inicializa)
            {
                if (comando.find("(") != string::npos && comando.find(")")!= string::npos )
                {
                   valor = pegaFloat(comando);
                    if(valor != -1 ){
                        if (!ehVazia(pilha))
                            insere(pilha, topo(pilha) / valor );
                        else
                            insere(pilha, valor);
                    }else
                        cout << "ERRO! , VALOR NAO ACEITO"<< endl;
                }else{}

            }
             else
                cout << "Programa nao iniciado"<<endl;

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
            cout<<"COMANDO INVALIDO DIGITE NOVAMENTE"<<endl;

        }

    }
    while(comando != "FIM");

    return 0;
}


