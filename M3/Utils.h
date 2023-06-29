#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>



vector<int> leDadosArq(const string& nomeArquivo, int quantidadeDados) {
    vector<int> dados;
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        int numero;
        int contador = 0;  // Variável para controlar a quantidade de dados lidos

        while (arquivo >> numero && contador < quantidadeDados) {
            dados.push_back(numero);
            contador++;
        }
        arquivo.close();
    }
    else {
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    return dados;
}

void mostrarVetor(const vector<int>& vetor) {
    for (int elemento : vetor) {
        cout << elemento << " ";
    }
    cout <<endl;
}

float ResultadoRelativo(int i, int max){
     return ((float) i/ (float) max)*100;
}

int maior(int a, int b, int c, int d){
    int maior = a;

    if (b > maior) {
        maior = b;
    }

    if (c > maior) {
        maior = c;
    }

    if (d > maior) {
        maior = d;
    }

    return maior;

}

void maiorComp(int maiorComparacao,int shell_comparacoes, int merge_comparacoes,int quick_comparacoes ,int heap_comparacoes){

    if(maiorComparacao == shell_comparacoes)
        cout << "Maior quantidade de comparacoes ("<<maiorComparacao<<"): SHELL SORT"<<endl;
    else if (maiorComparacao == merge_comparacoes)
        cout << "Maior quantidade de comparacoes ("<<maiorComparacao<<"): MERGE SORT"<<endl;
    else if (maiorComparacao == quick_comparacoes)
        cout << "Maior quantidade de comparacoes ("<<maiorComparacao<<"): QUICK SORT"<<endl;
    else
        cout << "Maior quantidade de comparacoes ("<<maiorComparacao<<"): HEAP SORT"<<endl;
}

void maisTrocas(int maiorTrocas,int shell_trocas, int merge_trocas,int quick_trocas ,int heap_trocas){

    if(maiorTrocas == shell_trocas)
        cout << "Maior quantidade de trocas ("<<maiorTrocas<<"): SHELL SORT!"<<endl;
    else if (maiorTrocas == merge_trocas)
        cout << "Maior quantidade de trocas ("<<maiorTrocas<<"): MERGE SORT!"<<endl;
    else if (maiorTrocas == quick_trocas)
        cout << "Maior quantidade de trocas ("<<maiorTrocas<<"): QUICK SORT!"<<endl;
    else
        cout << "Maior quantidade de trocas ("<<maiorTrocas<<"): HEAP SORT"<<endl;
}

char outraOp(){
    char c;
    do
    {
        cout << "Deseja finalizar ? [S/N]" << endl;
        c = toupper(cin.get());
    }
    while(c != 'S' && c != 'N');
    return c;
}

void ArquivoFinalCsv(const string& nomeArquivo, const vector<vector<string>>& dados) {
    ofstream arquivo(nomeArquivo);
    vector<string> titulos = { "Nome Arquivo", "Quantidade Dados", "Ordem Armazenamento", "Shell Sort (Trocas)", "Shell Sort (Comparacoes)", "Merge Sort (Trocas)", "Merge Sort (Comparacoes)", "Quick Sort (Trocas)", "Quick Sort (Comparacoes)", "Heap Sort (Trocas)", "Heap Sort (Comparacoes)", "Shell Sort (Trocas Relativas)", "Shell Sort (Comparacoes Relativas)", "Merge Sort (Trocas Relativas)", "Merge Sort (Comparacoes Relativas)", "Quick Sort (Trocas Relativas)", "Quick Sort (Comparacoes Relativas)", "Heap Sort (Trocas Relativas)", "Heap Sort (Comparacoes Relativas)" };


    if (arquivo.is_open()) {
        for (size_t i = 0; i < titulos.size(); i++) {
            arquivo << titulos[i];
            if (i != titulos.size() - 1) {
                arquivo << ",";
            }
        }
        arquivo << endl;

        for (const auto& linha : dados) {
            for (size_t i = 0; i < linha.size(); i++) {
                arquivo << linha[i];
                if (i != linha.size() - 1) {
                    arquivo << ",";
                }
            }
            arquivo << endl;
        }

        arquivo.close();
        cout << "Documento CSV gerado com sucesso!" << endl;
    }
    else {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
    }
}

string splitPath(const string& filePath) {
    size_t lastSeparator = filePath.find_last_of("\\/");
    if (lastSeparator != string::npos) {
        return filePath.substr(lastSeparator + 1);
    }
    return filePath;
}
#endif // UTILS_H_INCLUDED
