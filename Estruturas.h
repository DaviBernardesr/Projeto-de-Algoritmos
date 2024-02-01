#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <iostream>
#include <string.h>
#include <stack>
#include <iomanip>
#include <stdio.h>

//Bliblioteca para medir o tempo de exc. dos Algortimos.
#include <ctime>

using namespace std;


//Func. (INSERTION_SORT).
double insertion_sort(int* vetor, int tam) {

    //Variavel para armazenar o tempo de exc no final.
    double tempo;

    clock_t tempI, tempF;
    tempI = clock();

    for (int i = 1; i < tam; i++)
    {
        //Salva o cont. do vetor em um vetor aux.
        int vetor2 = vetor[i];
        int j = i - 1;

        //Compara o elem atual com o resto do vetor ordenado, movendo os maiores pra direita.
        while (j >= 0 && vetor[j] > vetor2)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = vetor2;
    }

    tempF = clock();

    //Calc. tempo de exec. do Insertion Sort.
    tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Insertion Sort: " << tempo << endl;

    return tempo;
}

// Func. (BUBBLE_SORT).
double bubble_sort(int* vetor, int tam) {
    // Variavel para armazenar o tempo de execucao no final.
    double tempo;

    clock_t tempI, tempF;
    tempI = clock();

    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    tempF = clock();

    // Calcule o tempo de execucao do Bubble Sort.
    tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Bubble Sort: " << tempo << endl;

    return tempo;
}

// Func. (SELECTION_SORT).
double selection_sort(int* vetor, int tam) {
    // Variavel para armazenar o tempo de execucao no final.
    double tempo;

    clock_t tempI, tempF;
    tempI = clock();

    for (int i = 0; i < tam - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tam; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        swap(vetor[i], vetor[minIndex]);
    }

    tempF = clock();

    // Calc. tempo de execucao do Selection Sort.
    tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Selection Sort: " << tempo << endl;

    return tempo;
}

// Func. (SHELL_SORT).
double shell_sort(int* vetor, int tam) {
    // Variavel para armazenar o tempo de execucao no final.
    double tempo;

    clock_t tempI, tempF;
    tempI = clock();

    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int temp = vetor[i];
            int j;
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
        }
    }

    tempF = clock();

    // Calc. tempo de execucao do Shell Sort.
    tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Shell Sort: " << tempo << endl;

    return tempo;
}


void merge(int* array, int inicio, int meio, int fim) {
    int* temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = new int[tamanho];

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (array[p1] < array[p2])
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];

                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            }
            else {
                if (!fim1)
                    temp[i] = array[p1++];
                else
                    temp[i] = array[p2++];
            }
        }

        for (j = 0, k = inicio; j < tamanho; j++, k++)
            array[k] = temp[j];
    }

    delete[] temp;
}

// Func. (MERGE_SORT).
double merge_sort(int* array, int inicio, int fim) {

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    int meio;

    if (inicio < fim) {
        meio = floor((inicio + fim) / 2);
        merge_sort(array, inicio, meio);
        merge_sort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }

    EndC = clock();

    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    return tempo;

}

// Func. (QUICK SORT).
// 4 tipos em seu pivo.



// Quick 1: Pivo fixo no inicio do array.
double partition_quick_versao1(int* a, int p, int r) {
    int x = a[p];
    int i = p;
    int j;
    for (j = p + 1; j <= r; j++) {
        if (a[j] < x) {
            i++;
            // Troca os indices.
            swap(a[i], a[j]);
        }
    }

    // Troca os indices.
    swap(a[i], a[p]);

    return i;
}

double quicksort_versao1(int* a, int p, int r) {
    clock_t tempI, tempF;
    tempI = clock();

    stack<int> pilha;
    pilha.push(p);
    pilha.push(r);

    while (!pilha.empty()) {
        r = pilha.top();
        pilha.pop();
        p = pilha.top();
        pilha.pop();

        int q = partition_quick_versao1(a, p, r);

        if (q - 1 > p) {
            pilha.push(p);
            pilha.push(q - 1);
        }

        if (q + 1 < r) {
            pilha.push(q + 1);
            pilha.push(r);
        }
    }

    tempF = clock();
    double tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Quick Sort 1: " << tempo << endl;

    return tempo;
}


// Quick 2: Pivo media do primeiro e ultimo elementos.
double partition_quick_versao2(int* a, int p, int r) {
    int x = (a[p] + a[r]) / 2;
    int i = p;
    int j;
    for (j = p + 1; j <= r; j++) {
        if (a[j] < x) {
            i++;
            // Troca os indices.
            swap(a[i], a[j]);
        }
    }

    // Troca os indices.
    swap(a[i], a[p]);

    return i;
}

double quicksort_versao2(int* a, int p, int r) {
    clock_t tempI, tempF;
    tempI = clock();

    
    stack<int> pilha;
    pilha.push(p);
    pilha.push(r);

    while (!pilha.empty()) {
        // Retira os limites do subarray da pilha
        r = pilha.top();
        pilha.pop();
        p = pilha.top();
        pilha.pop();

        // Particiona o subarray e obtem o índice do pivo
        int q = partition_quick_versao2(a, p, r);

        // Adiciona os limites do subarray esquerdo
        if (q - 1 > p) {
            pilha.push(p);
            pilha.push(q - 1);
        }

        // Adiciona os limites do subarray direito
        if (q + 1 < r) {
            pilha.push(q + 1);
            pilha.push(r);
        }
    }

    tempF = clock();
    double tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Quick Sort 2: " << tempo << endl;

    return tempo;
}


// Quick 3: Pivo elemento do meio.
double partition_quick_versao3(int* a, int p, int r) {
    int media = (p + r) / 2;
    int x = a[media];

    if ((a[p] < a[media] && a[media] < a[r]) || (a[r] < a[media] && a[media] < a[p]))
        x = a[media];
    else if ((a[media] < a[p] && a[p] < a[r]) || (a[r] < a[p] && a[p] < a[media]))
        x = a[p];

    int i = p;
    int j;
    for (j = p + 1; j <= r; j++) {
        if (a[j] < x) {
            i++;
            // Troca os indices.
            swap(a[i], a[j]);
        }
    }

    // Troca os indices.
    swap(a[i], a[p]);

    return i;
}

double quicksort_versao3(int* a, int p, int r) {
    clock_t tempI, tempF;
    tempI = clock();

    // Cria pilha.
    stack<int> pilha;
    pilha.push(p);
    pilha.push(r);

    while (!pilha.empty()) {
        // Retira os limites do subarray da pilha
        r = pilha.top();
        pilha.pop();
        p = pilha.top();
        pilha.pop();

        // Particiona o subarray para ter o ind do pivo
        int q = partition_quick_versao3(a, p, r);

        
        if (q - 1 > p) {
            pilha.push(p);
            pilha.push(q - 1);
        }

        
        if (q + 1 < r) {
            pilha.push(q + 1);
            pilha.push(r);
        }
    }

    tempF = clock();
    double tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Quick Sort 3: " << tempo << endl;

    return tempo;
}


// Quick 4: Pivo aleatorio.
double partition_quick_versao4(int* a, int p, int r) {
    int pivotIndex = rand() % (r - p + 1) + p;
    int x = a[pivotIndex];
    int i = p;

    // Troca os indices
    swap(a[pivotIndex], a[p]);

    int j;
    for (j = p + 1; j <= r; j++) {
        if (a[j] < x) {
            i++;
            // Troca os indices.
            swap(a[i], a[j]);
        }
    }

    // Troca os indices.
    swap(a[i], a[p]);

    return i;
}

double quicksort_versao4(int* a, int p, int r) {
    clock_t tempI, tempF;
    tempI = clock();

    stack<int> pilha;
    pilha.push(p);
    pilha.push(r);

    while (!pilha.empty()) {
        r = pilha.top();
        pilha.pop();
        p = pilha.top();
        pilha.pop();

        int q = partition_quick_versao4(a, p, r);

        if (q - 1 > p) {
            pilha.push(p);
            pilha.push(q - 1);
        }

        if (q + 1 < r) {
            pilha.push(q + 1);
            pilha.push(r);
        }
    }

    tempF = clock();
    double tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Quick Sort 4: " << tempo << endl;

    return tempo;
}




//Heaps




void imprimir_array(int* a, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void min_heapify(int* a, int n, int i) {
    int smallest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && a[left_child] < a[smallest])
        smallest = left_child;

    if (right_child < n && a[right_child] < a[smallest])
        smallest = right_child;

    if (smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        min_heapify(a, n, smallest);
    }
}

void build_min_heap(int* a, int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        min_heapify(a, n, i);
    }
}

// Func. (HEAP_SORT).
double heap_sort(int* a, int n) {
    clock_t tempI, tempF;
    tempI = clock();

    build_min_heap(a, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        min_heapify(a, i, 0);
    }

    tempF = clock();
    double tempo = (tempF - tempI) / (double)CLOCKS_PER_SEC;
    cout << endl << "Tempo Heap Sort: " << tempo << endl;

    return tempo;
}


void heap_minimum(int* a, int tamanho) {
    cout << "Vetor original:\n";
    imprimir_array(a, tamanho);
    cout << "Construindo min heap:\n";
    build_min_heap(a, tamanho);
    imprimir_array(a, tamanho);
    cout << "Elemento minimo: " << a[0] << "\n\n";
}

void heap_extract_min(int* a, int& tamanho) {
    if (tamanho < 1) {
        cout << "Heap vazio. Não e possivel extrair o minimo.\n";
        return;
    }

    cout << "Vetor original:\n";
    imprimir_array(a, tamanho);

    cout << "Removendo o minimo...\n";
    int min = a[0];
    a[0] = a[tamanho - 1];
    tamanho--;
    min_heapify(a, tamanho, 0);

    cout << "Elemento minimo removido: " << min << "\n";
    cout << "Heap apos a extracao:\n";
    imprimir_array(a, tamanho);
    cout << "\n";
}

void heap_increase_key(int* a, int tamanho, int key) {
    cout << "Vetor original:" << endl;
    imprimir_array(a, tamanho);
    std::cout << "Vetor chamado build:" << endl;
    build_min_heap(a, tamanho);
    imprimir_array(a, tamanho);

    int i;
    cout << "Digite a posicao desejada:" << endl;
    cin >> i;

    if (i < 0 || i >= tamanho) {
        cerr << "Erro: Posicao invalida" << endl;
        exit(EXIT_FAILURE);
    }

    if (key < a[i]) {
        cerr << "Erro: Nova chave eh menor que a chave atual" << endl;
        exit(EXIT_FAILURE);
    }

    a[i] = key;

    while (i > 0 && a[(i - 1) / 2] > a[i]) {
        int temp = a[i];
        a[i] = a[(i - 1) / 2];
        a[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

    cout << "Vetor apos o aumento da chave:" << endl;
    imprimir_array(a, tamanho);
}

void max_heap_insert(int* a, int& tamanho, int elemento) {
    cout << "Vetor original:" << endl;
    imprimir_array(a, tamanho);

    ++tamanho;


    a[tamanho - 1] = elemento;

    int indice = tamanho - 1;


    while (indice > 0 && a[(indice - 1) / 2] < a[indice]) {
        swap(a[indice], a[(indice - 1) / 2]);
        indice = (indice - 1) / 2;
    }

    cout << "Vetor apos o MAX:" << endl;
    imprimir_array(a, tamanho);

}

#endif