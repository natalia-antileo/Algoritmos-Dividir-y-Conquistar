#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
        ifstream inputFile("Datasets/orden_inverso_mitades_" + to_string(tamanio) + ".txt");
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

        // Ejecución del algoritmo std::sort() Este revisará que algoritmo le viene mejor al arreglo: Insertion Sort, QuickSort o HeapSort
        sort(arr.begin(), arr.end());

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
