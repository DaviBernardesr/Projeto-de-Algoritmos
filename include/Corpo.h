#ifndef CORPO_H
#define CORPO_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <windows.h>


using namespace std;

string algoritmo_num(int num) {
    string nome;

    switch (num) {
    case 1:
        nome = "Insertion_Sort/";
        return nome;
    case 2:
        nome = "Bubble_Sort/";
        return nome;
    case 3:
        nome = "Selection_Sort/";
        return nome;
    case 4:
        nome = "Shell_Sort/";
        return nome;
    case 5:
        nome = "Merge_Sort/";
        return nome;
    case 6:
        nome = "Quick_Sort_1/";
        return nome;
    case 7:
        nome = "Quick_Sort_2/";
        return nome;
    case 8:
        nome = "Quick_Sort_3/";
        return nome;
    case 9:
        nome = "Quick_Sort_4/";
        return nome;
    case 10:
        nome = "Heap_Sort/";
        return nome;
    default:
        cerr << endl << "ERRO, algoritmo nao reconhecido!!!" << endl;
        exit(1);
    }
}

// Func. para verificar e criar as pastas
void CriarPasta(const string& algoritmo_dir, const string& tipo, char forma) {
    string pasta = algoritmo_dir + tipo;

    // Verificar se a pasta do algoritmo existe
    if (CreateDirectoryA(pasta.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        vector<string> subpastas = { "Arquivos de Entrada", "Arquivos de Tempo", "Arquivos de Saida" };
        for (const string& subpasta : subpastas) {
            string subpasta_completa = pasta + "/" + subpasta;
            if (!CreateDirectoryA(subpasta_completa.c_str(), NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
                cerr << "Erro ao criar a pasta: " << subpasta_completa << endl;
                exit(1);
            }
        }
    }
    else {
        cerr << "Erro ao criar a pasta: " << pasta << endl;
        exit(1);
    }
}



double Loop(int algoritmo, int* vetor, int tam) {
    double temp;

    switch (algoritmo) {
    case 1:
        temp = insertion_sort(vetor, tam);
        break;
    case 2:
        temp = bubble_sort(vetor, tam);
        break;
    case 3:
        temp = selection_sort(vetor, tam);
        break;
    case 4:
        temp = shell_sort(vetor, tam);
        break;
    case 5: {
        clock_t tempI, tempF;
        tempI = clock();

        merge_sort(vetor, 0, tam - 1);

        tempF = clock();
        temp = (tempF - tempI) / static_cast<double>(CLOCKS_PER_SEC);
        break;
    }
    case 6:
        temp = quicksort_versao1(vetor, 0, tam - 1);
        break;
    case 7:
        temp = quicksort_versao2(vetor, 0, tam - 1);
        break;
    case 8:
        temp = quicksort_versao3(vetor, 0, tam - 1);
        break;
    case 9:
        temp = quicksort_versao4(vetor, 0, tam - 1);
        break;
    case 10:
        temp = heap_sort(vetor, tam);
        break;
    default:
        cerr << endl << "ERRO, algoritmo nao reconhecido!!!" << endl;
        exit(1);
    }

    return temp;
}

int conversor(int indicador) {
    switch (indicador) {
    case 1:
        return 10;
    case 2:
        return 100;
    case 3:
        return 1000;
    case 4:
        return 10000;
    case 5:
        return 100000;
    case 6:
        return 1000000;
    default:
        cerr << "ERRO, valor de indicador invalido!!!";
        exit(1);
    }
}

void GerarArquivo(const string& nome_arquivo, int* vetor, int tam) {
    ofstream arq(nome_arquivo);

    if (!arq.is_open()) {
        cerr << "ERRO ao abrir o arquivo " << nome_arquivo << endl;
        exit(1);
    }

    arq << tam << endl;

    for (int i = 0; i < tam; i++) {
        arq << vetor[i] << endl;
    }

    arq.close();
}


void Modo_Crescente(int algoritmo, int tam, char forma) {
    srand(time(NULL));

    int valor = ((rand() % 9) + 1) * 1000000;
    int* vetor = new int[tam];

    for (int i = valor, j = 0; j < tam; i++) {
        vetor[j] = i;
        j++;
    }

    double tempo = Loop(algoritmo, vetor, tam);

    string algoritmo_dir = algoritmo_num(algoritmo);

    // Verificar se a pasta do algoritmo existe
    if (CreateDirectoryA(algoritmo_dir.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        string pasta_tipo = (forma == 'r' || forma == 'R') ? "Random" : (forma == 'c' || forma == 'C') ? "Crescente" : "Decrescente";
        string pasta_completa = algoritmo_dir + pasta_tipo + "/";

        CriarPasta(algoritmo_dir, pasta_tipo, forma); // Criar as pastas corretamente.

        string nome_arquivo = pasta_completa + "Arquivos de Entrada/entradacrescente" + to_string(tam) + ".txt";
        GerarArquivo(nome_arquivo, vetor, tam);

        nome_arquivo = pasta_completa + "Arquivos de Tempo/tempocrescente" + to_string(tam) + ".txt";
        ofstream arq_tempo(nome_arquivo);
        arq_tempo << tempo;
        arq_tempo.close();

        nome_arquivo = pasta_completa + "Arquivos de Saida/saidacrescente" + to_string(tam) + ".txt";
        GerarArquivo(nome_arquivo, vetor, tam);
    }

    delete[] vetor;
}

void Modo_Decrescente(int algoritmo, int tamanho, char forma) {
    string algoritmo_dir = algoritmo_num(algoritmo);

    // Verificar se a pasta do algoritmo existe
    if (CreateDirectoryA(algoritmo_dir.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        string pasta_tipo = (forma == 'r' || forma == 'R') ? "Random" : (forma == 'c' || forma == 'C') ? "Crescente" : "Decrescente";
        string pasta_completa = algoritmo_dir + pasta_tipo + "/";

        CriarPasta(algoritmo_dir, pasta_tipo, forma); // Criar as pastas corretamente.

        string nome_arquivo = pasta_completa + "Arquivos de Entrada/entradadedecrescente" + to_string(tamanho) + ".txt";

        ofstream arq(nome_arquivo);
        arq << tamanho << endl;

        int j = 0;

        srand(time(NULL));
        int seed = ((rand() % 9) + 1) * 1000000;

        int* array = new int[tamanho];

        for (int i = seed; j < tamanho; i--) {
            array[j] = i;
            arq << array[j] << endl;
            j++;
        }

        arq.close();

        double tempo = Loop(algoritmo, array, tamanho);

        nome_arquivo = pasta_completa + "Arquivos de Tempo/tempodedecrescente" + to_string(tamanho) + ".txt";
        ofstream arq_tempo(nome_arquivo);
        arq_tempo << tempo;
        arq_tempo.close();

        nome_arquivo = pasta_completa + "Arquivos de Saida/saidadedecrescente" + to_string(tamanho) + ".txt";
        GerarArquivo(nome_arquivo, array, tamanho);

        delete[] array;
    }
}

void Modo_Random(int algoritmo, int tamanho, char forma) {
    string algoritmo_dir = algoritmo_num(algoritmo);

    // Verificar se a pasta do algoritmo existe
    if (CreateDirectoryA(algoritmo_dir.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        string pasta_tipo = (forma == 'r' || forma == 'R') ? "Random" : (forma == 'c' || forma == 'C') ? "Crescente" : "Decrescente";
        string pasta_completa = algoritmo_dir + pasta_tipo + "/";

        CriarPasta(algoritmo_dir, pasta_tipo, forma); // Criar as pastas corretamente.

        string nome_arquivo = pasta_completa + "Arquivos de Entrada/entradarandom" + to_string(tamanho) + ".txt";

        ofstream arq(nome_arquivo);
        arq << tamanho << endl;

        int* array = new int[tamanho];

        for (int i = 0; i < tamanho; i++) {
            int seed = ((rand() % 1000) * 1000) + rand() % 1000 + ((rand() % 9 + 1) * 1000000);
            array[i] = seed;
            arq << array[i] << endl;
        }

        arq.close();

        double tempo = Loop(algoritmo, array, tamanho);

        nome_arquivo = pasta_completa + "Arquivos de Tempo/temporandom" + to_string(tamanho) + ".txt";
        ofstream arq_tempo(nome_arquivo);
        arq_tempo << tempo;
        arq_tempo.close();

        nome_arquivo = pasta_completa + "Arquivos de Saida/saidarandom" + to_string(tamanho) + ".txt";
        GerarArquivo(nome_arquivo, array, tamanho);

        delete[] array;
    }
}

#endif
