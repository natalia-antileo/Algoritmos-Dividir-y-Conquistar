#include <bits/stdc++.h>
using namespace std;

// Genera datos ordenados ascendentemente
void generarDatosOrdenados(const string& nombreArchivo, size_t tamanio) {
    ofstream archivo(nombreArchivo);
    for (size_t i = 0; i < tamanio; ++i) {
        archivo << i << "\n";
    }
}

// Genera datos ordenados descendentemente
void generarDatosDescendentes(const string& nombreArchivo, size_t tamanio) {
    ofstream archivo(nombreArchivo);
    for (size_t i = tamanio; i > 0; --i) {
        archivo << i << "\n";
    }
}

// Genera datos desordenados aleatoriamente
void generarDatosAleatorios(const string& nombreArchivo, size_t tamanio) {
    ofstream archivo(nombreArchivo);
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> distribucion(0, 10000);

    for (size_t i = 0; i < tamanio; ++i) {
        archivo << distribucion(rng) << "\n";
    }
}

// Genera datos ordenados ascendentemente al comienzo y desordenados al final
void generarSemiOrdenadoInicio(const string& nombreArchivo, size_t tamanio) {
    ofstream archivo(nombreArchivo);
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> distribucion(0, 10000);

    // Primera mitad ordenada
    for (size_t i = 0; i < tamanio / 2; ++i) {
        archivo << i + 1 << "\n";
    }

    // Segunda mitad desordenada
    for (size_t i = tamanio / 2; i < tamanio; ++i) {
        archivo << distribucion(rng) << "\n";
    }
}

// Genera datos ordenados por mitades pero puestos al revés
void generarOrdenInversoMitades(const string& nombreArchivo, size_t tamanio) {
    ofstream archivo(nombreArchivo);

    // Primera mitad ordenada ascendente
    for (size_t i = tamanio / 2 + 1; i <= tamanio; ++i) {
        archivo << i << "\n";
    }

    // Segunda mitad ordenada descendente
    for (size_t i = tamanio / 2; i > 0; --i) {
        archivo << i << "\n";
    }
}


int main() {
    // Tamaños de datasets a generar
    size_t tamanios[] = {100, 1000, 5000, 10000, 50000, 100000, 200000, 300000};

    for (size_t tamanio : tamanios) {
        generarDatosOrdenados("datos_ordenados_" + to_string(tamanio) + ".txt", tamanio);
        generarDatosDescendentes("datos_descendentes_" + to_string(tamanio) + ".txt", tamanio);
        generarDatosAleatorios("datos_aleatorios_" + to_string(tamanio) + ".txt", tamanio);
        generarSemiOrdenadoInicio("semi_ordenado_inicio_" + to_string(tamanio) + ".txt", tamanio);
        generarOrdenInversoMitades("orden_inverso_mitades_" + to_string(tamanio) + ".txt", tamanio);
    }

    return 0;
}
