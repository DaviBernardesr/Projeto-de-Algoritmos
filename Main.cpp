#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <windows.h>
#include "Estruturas.h"
#include "Corpo.h"
#include <stdio.h>

using namespace std;


int main() {
    int opcao, tam = 0;
    char forma;

    int* num = nullptr;

    do {
        cout << endl;
        cout << "         MENU:        " << endl << endl;
        cout << "Escolha seu numero: " << endl << endl;
        cout << "1- Insertion Sort" << endl;
        cout << "2- Bubble Sort" << endl;
        cout << "3- Selection Sort" << endl;
        cout << "4- Shell Sort" << endl;
        cout << "5- Merge Sort" << endl;
        cout << "6- Quick Sort (1)" << endl;
        cout << "7- Quick Sort (2)" << endl;
        cout << "8- Quick Sort (3)" << endl;
        cout << "9- Quick Sort (4)" << endl;
        cout << "10- Heap Sort" << endl;
        cout << "11- HEAP_MINIMUM" << endl;
        cout << "12- HEAP_EXTRACT_MIN" << endl;
        cout << "13- HEAP_INCREASE_KEY" << endl;
        cout << "14- MAX_HEAP_INSERT" << endl;
        cout << "15- Sair" << endl << endl;

        cout << "Digite: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }


            delete[] vetor;

            break;
        }
        case 2: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }


            delete[] vetor;

            break;
        }
        case 3: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }


            delete[] vetor;

            break;
        }
        case 4: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }


            delete[] vetor;

            break;
        }
        case 5: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }


            delete[] vetor;

            break;

        }
        case 6: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }

            delete[] vetor;

            break;
        }
        case 7: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }

            delete[] vetor;

            break;
        }
        case 8: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }

            delete[] vetor;

            break;
        }
        case 9: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }

            delete[] vetor;

            break;
        }
        case 10: {
            cout << endl;
            cout << "'r' para numeros randomicos." << endl;
            cout << "'c' para numeros crescentes." << endl;
            cout << "'d' para numeros decrescentes." << endl << endl;

            cout << "Digite: ";
            cin >> forma;

            cout << endl;
            cout << "Escolha uma quantidade de numeros: " << endl;
            cout << "1 - 10" << endl;
            cout << "2 - 100" << endl;
            cout << "3 - 1000" << endl;
            cout << "4 - 10000" << endl;
            cout << "5 - 100000" << endl;
            cout << "6 - 1000000" << endl << endl;

            cout << "Digite: ";
            cin >> tam;

            tam = conversor(tam);

            int* vetor = new int[tam];

            switch (forma) {
            case 'c':
            case 'C':
                Modo_Crescente(opcao, tam, forma);
                break;
            case 'd':
            case 'D':
                Modo_Decrescente(opcao, tam, forma);
                break;
            case 'r':
            case 'R':
                Modo_Random(opcao, tam, forma);
                break;
            }

            delete[] vetor;

            break;
        }
        case 11: {
            tam = 11;
            num = new int[tam];
            for (int i = 0; i < tam; ++i) {
                num[i] = rand() % 1000;
            }
            heap_minimum(num, tam);
            break;
        }
        case 12: {
            tam = 11;
            num = new int[tam];
            for (int i = 0; i < tam; ++i) {
                num[i] = rand() % 1000;
            }
            heap_extract_min(num, tam);
            break;
        }
        case 13: {
            tam = 11;
            num = new int[tam];
            for (int i = 0; i < tam; ++i) {
                num[i] = rand() % 1000;
            }
            heap_increase_key(num, tam, 1000);
            break;
        }
        case 14: {
            tam = 11;
            num = new int[tam];
            for (int i = 0; i < tam; ++i) {
                num[i] = rand() % 1000;
            }
            max_heap_insert(num, tam, 1000);
            break;
        }
        case 15: {
            cout << endl << "Saindo do programa. Obrigado!" << endl;
            break;
        }
        default:
            cout << "ERRO. Tente novamente." << endl;
        }

    } while (opcao != 15);

    return 0;
}