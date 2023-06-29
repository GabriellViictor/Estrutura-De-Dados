#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include "metodosOrganizacao.h"
#include "Utils.h"

using namespace std;

// C:\Users\Gabriel\Desktop\M3-Gabriel\dados\10k.txt

int main()
{
    vector<vector<string>> dadosCSV;
    vector<int> dados;

    string nomeArq = "", tipoArmazen = "";
    int qntdDados = 0;
    int quick_trocas = 0, quick_comparacoes = 0, merge_trocas = 0, merge_comparacoes = 0, shell_trocas = 0, shell_comparacoes = 0, heap_trocas = 0, heap_comparacoes = 0;
    char resp;

    do
    {
        do
        {
            cout << "Digite o nome do arquivo de dados: ";
            cin >> nomeArq;

            cout << "Digite a quantidade de dados a serem ordenados (1 a 10000): ";
            cin >> qntdDados;

            if (nomeArq == "")
                cout << endl << "Nome do arquivo nao pode ser nulo" << endl;
            else if (qntdDados < 1 || qntdDados > 10000)
                cout << endl << "Insira um valor valido entre (1..10000)" << endl;

        }
        while (nomeArq == "" || qntdDados <= 0 || qntdDados > 10000);

        cout << endl;

        int ordemArmazenamento;
        do
        {
            cout << "Selecione a ordem de armazenamento dos dados:" << endl;
            cout << "1 - Ordem crescente" << endl;
            cout << "2 - Ordem decrescente" << endl;
            cout << "3 - Ordem aleatória" << endl;
            cout << "Digite sua escolha (1-3): ";
            cin >> ordemArmazenamento;
        }
        while (ordemArmazenamento < 1 || ordemArmazenamento > 3);

        dados = leDadosArq(nomeArq, qntdDados);

        switch (ordemArmazenamento)
        {
        case 1:
            sort(dados.begin(), dados.end());
            tipoArmazen = "Crescente";
            break;
        case 2:
            sort(dados.rbegin(), dados.rend());
            tipoArmazen = "Decrescente";
            break;
        case 3:
            random_shuffle(dados.begin(), dados.end());
            tipoArmazen = "Aleatorio";
            break;
        }

        vector<int> shell_dados = dados;
        vector<int> quick_dados = dados;
        vector<int> merge_dados = dados;
        vector<int> heap_dados = dados;

        quicksort(quick_dados, 0, qntdDados, quick_trocas, quick_comparacoes);
        mergesort(merge_dados, 0, qntdDados - 1, merge_trocas, merge_comparacoes);
        shellsort(shell_dados, shell_trocas, shell_comparacoes);
        heapsort(heap_dados, qntdDados, heap_trocas, heap_comparacoes);

        cout << endl << "Maiores Trocas/Comparacoes" << endl;
        int maiorComparacao = maior(shell_comparacoes, merge_comparacoes, quick_comparacoes, heap_comparacoes);
        int maiorTrocas = maior(shell_trocas, merge_trocas, quick_trocas, heap_trocas);

        maiorComp(maiorComparacao, shell_comparacoes, merge_comparacoes, quick_comparacoes, heap_comparacoes);
        maisTrocas(maiorTrocas, shell_trocas, merge_trocas, quick_trocas, heap_trocas);

        cout << endl;


        cout << endl << "Trocas/Comparacoes" << endl;
        cout << "----------SHELL SORT-----------" << endl << "Trocas: " << shell_trocas << endl << "Comparacoes: " << shell_comparacoes << endl;
        cout << "----------MERGE SORT-----------" << endl << "Trocas: " << merge_trocas << endl << "Comparacoes: " << merge_comparacoes << endl;
        cout << "----------QUICK SORT-----------" << endl << "Trocas: " << quick_trocas << endl << "Comparacoes: " << quick_comparacoes << endl;
        cout << "----------HEAP SORT-----------" << endl << "Trocas: " << heap_trocas << endl << "Comparacoes: " << heap_comparacoes << endl;

        cout << endl;

        cout << "----------SHELL SORT-----------" << endl;
        cout << "Trocas(Relativas): " << setprecision(4) << ResultadoRelativo(shell_trocas, maiorTrocas) << endl;
        cout << "Comparacoes(Relativas): " << setprecision(4) << ResultadoRelativo(shell_comparacoes, maiorComparacao) << endl;

        cout << "----------MERGE SORT-----------" << endl;
        cout << "Trocas(Relativas): " << setprecision(4) << ResultadoRelativo(merge_trocas, maiorTrocas) << endl;
        cout << "Comparacoes(Realativas): " << setprecision(4) << ResultadoRelativo(merge_comparacoes, maiorComparacao) << endl;

        cout << "----------QUICK SORT-----------" << endl;
        cout << "Trocas(Relativas): " << setprecision(4) << ResultadoRelativo(quick_trocas, maiorTrocas) << endl;
        cout << "Comparacoes(Relativas): " << setprecision(4) << ResultadoRelativo(quick_comparacoes, maiorComparacao) << endl;

        cout << "----------HEAP SORT-----------" << endl;
        cout << "Trocas(Relativas): " << setprecision(4) << ResultadoRelativo(heap_trocas, maiorTrocas) << endl;
        cout << "Comparacoes: " << setprecision(4) << ResultadoRelativo(heap_comparacoes, maiorComparacao) << endl;
        cout << "------------------------------" << endl;

        vector<string> linhaCSV = { splitPath(nomeArq), to_string(qntdDados), tipoArmazen,
                                 to_string(shell_trocas), to_string(shell_comparacoes),
                                 to_string(merge_trocas), to_string(merge_comparacoes),
                                 to_string(quick_trocas), to_string(quick_comparacoes),
                                 to_string(heap_trocas), to_string(heap_comparacoes),
                                 to_string(ResultadoRelativo(shell_trocas, maiorTrocas)),
                                 to_string(ResultadoRelativo(shell_comparacoes, maiorComparacao)),
                                 to_string(ResultadoRelativo(merge_trocas, maiorTrocas)),
                                 to_string(ResultadoRelativo(merge_comparacoes, maiorComparacao)),
                                 to_string(ResultadoRelativo(quick_trocas, maiorTrocas)),
                                 to_string(ResultadoRelativo(quick_comparacoes, maiorComparacao)),
                                 to_string(ResultadoRelativo(heap_trocas, maiorTrocas)),
                                 to_string(ResultadoRelativo(heap_comparacoes, maiorComparacao))
                               };

        dadosCSV.push_back(linhaCSV);

        cout << endl;

        cin.ignore();
        resp = outraOp();
        system("cls");

    }
    while (resp != 'S');

    ArquivoFinalCsv("conclusoes.csv", dadosCSV);

    return 0;
}
