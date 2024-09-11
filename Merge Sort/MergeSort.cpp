#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


// Función para fusionar los arreglos
// El primer subarreglo es arr[left..mid]
// El segundo subarreglo es arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right)
{
    // Calcula el tamaño de los dos subarreglos
    int n1 = mid - left + 1;  // Tamaño del primer subarreglo
    int n2 = right - mid;     // Tamaño del segundo subarreglo

    // Crea vectores temporales para almacenar los subarreglos
    vector<int> L(n1), R(n2);

    // Copia los datos al primer subarreglo temporal L[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Copia los datos al segundo subarreglo temporal R[]
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;  // Índices para los subarreglos temporales L[] y R[]
    int k = left;      // Índice para el subarreglo original arr[]

    // Fusiona los subarreglos temporales de vuelta en arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Toma el menor de los dos elementos y lo coloca en arr[k]
            i++;            // Avanza en el subarreglo L[]
        }
        else {
            arr[k] = R[j];  // Toma el menor de los dos elementos y lo coloca en arr[k]
            j++;            // Avanza en el subarreglo R[]
        }
        k++;  // Avanza en el subarreglo original arr[]
    }

    // Copia los elementos restantes de L[], mientras los haya
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de R[], mientras los haya
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 'left' es el índice inicial y 'right' es el índice final del subarreglo de 
// arr[] que debe ser ordenado
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;  // Caso base: un solo elemento o subarreglo vacío no necesita ser ordenado

    // Encuentra el punto medio para dividir el arreglo en dos subarreglos
    int mid = left + (right - left) / 2;

    // Llama recursivamente a mergeSort para los dos subarreglos
    mergeSort(arr, left, mid);       // Ordena el subarreglo izquierdo
    mergeSort(arr, mid + 1, right);  // Ordena el subarreglo derecho

    // Fusiona los dos subarreglos ordenados
    merge(arr, left, mid, right);
}






int main()
{
    ofstream outputFile("resultados.txt", ios::app); // Archivo para guardar resultados
    if (!outputFile) {
        cerr << "Error abriendo archivo de resultados!" << endl;
        return 1;
    }

    // Lista de tamaños de archivo para probar
    vector<int> tamanios = {100, 1000, 5000, 10000, 50000, 100000,  200000, 300000};

    for (int tamanio : tamanios) {
        // Abre el archivo de datos
        ifstream inputFile("Datasets/semi_ordenado_inicio_" + to_string(tamanio) + ".txt");
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

        // Ejecución del algoritmo MergeSort
        mergeSort(arr, 0, arr.size() - 1);

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
