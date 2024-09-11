#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    // Selecciona el pivote, que es el último elemento del segmento actual
    int pivot = arr[high];
  
    // Índice del último elemento que es menor que el pivote
    int i = low - 1;

    // Recorre el segmento arr[low..high-1] y mueve todos los elementos menores
    // que el pivote hacia el inicio. Después de cada iteración, los elementos
    // desde el índice low hasta i son menores que el pivote.
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // Mueve el índice del último elemento menor
            swap(arr[i], arr[j]); // Intercambia el elemento menor con el elemento en el índice i
        }
    }
    
    // Intercambia el pivote con el elemento en la posición i + 1
    swap(arr[i + 1], arr[high]);
    // Devuelve la posición del pivote
    return i + 1;
}

// Implementación de la función QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi es el índice de partición del pivote
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); //ordena el segmento a la izquierda del pivote.
        quickSort(arr, pi + 1, high); //ordena el segmento a la derecha del pivote.
    }
}



int main()
{
    ofstream outputFile("resultados.txt", ios::app); // Archivo para guardar resultados
    if (!outputFile) {
        cerr << "Error abriendo archivo de resultados!" << endl;
        return 1;
    }

    // Lista de tamaños de archivo para probar
    vector<int> tamanios = {100, 1000, 5000, 10000, 50000, 100000, 200000, 300000};

    for (int tamanio : tamanios) {
        // Abre el archivo de datos
        ifstream inputFile("Datasets/datos_descendentes" + to_string(tamanio) + ".txt");
        if (!inputFile) {
            cerr << "Error abriendo archivo de datos!" << endl;
            return 1;
        }

        vector<int> arr;
        int number;

        // Lectura de números del archivo y almacenamiento en el vector arr
        while (inputFile >> number) {
            arr.push_back(number);
        }
        inputFile.close();

        // Medición del tiempo antes de ordenar
        auto start = high_resolution_clock::now();

        // Ejecución del algoritmo Quicksort
        quickSort(arr, 0, arr.size() - 1);

        // Medición del tiempo después de ordenar
        auto stop = high_resolution_clock::now();

        // Tiempo transcurrido durante el ordenamiento
        auto duration = duration_cast<microseconds>(stop - start);

        // Guarda el tamaño del archivo y el tiempo en el archivo de resultados
        outputFile << tamanio << " " << duration.count() << endl;
    }

    outputFile.close();
    return 0;
}