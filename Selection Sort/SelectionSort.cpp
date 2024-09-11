#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

//Implementación de Selection Sort
void selectionSort(vector<int>& arr)
{
    int n = arr.size();  // Obtiene el tamaño del arreglo

    // Recorre el arreglo, excluyendo el último elemento en la primera pasada
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;  // Suponemos que el elemento en la posición 'i' es el mínimo

        // Encuentra el índice del mínimo elemento en el subarreglo restante
        for (int j = i + 1; j < n; j++)
        {
            // Compara el elemento actual con el mínimo encontrado hasta ahora
            if (arr[j] < arr[min_idx])
                min_idx = j;  // Actualiza el índice del mínimo elemento
        }

        // Si el mínimo encontrado no es el elemento en la posición 'i', intercambia
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}


int main()
{
    ofstream outputFile("resultados.txt"); // Archivo para guardar resultados
    if (!outputFile) {
        std::cerr << "Error abriendo archivo de resultados!" << std::endl;
        return 1;
    }

    // Lista de tamaños de archivo para probar
    vector<int> tamanios = {100, 1000, 5000, 10000, 50000, 100000, 200000, 300000};
    
    for (int tamanio : tamanios) {
        // Abre el archivo de datos
        ifstream inputFile("Datasets/semi_ordenado_inicio_" + to_string(tamanio) + ".txt");
        if (!inputFile) {
            std::cerr << "Error abriendo archivo de datos!" << std::endl;
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

        // Ejecución del algoritmo SelectionSort()
        selectionSort(arr);

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
