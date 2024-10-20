#include <iostream>
#include <vector>

using namespace std;

// Función para calcular la matriz de pesos utilizando la regla de aprendizaje de Hebb
vector<vector<int>> calcularMatrizPesos(const vector<vector<int>>& patrones) {
    int n = patrones[0].size();  // El tamaño de cada patrón (número de píxeles)
    vector<vector<int>> matrizPesos(n, vector<int>(n, 0));  // Inicializamos la matriz de pesos con ceros

    // Recorro cada patrón de entrenamiento
    for (const auto& patron : patrones) {
        // Calculo la contribución de cada patrón a la matriz de pesos
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {  
                    matrizPesos[i][j] += patron[i] * patron[j];
                }
            }
        }
    }
    return matrizPesos;
}

// Función para actualizar el estado de un píxel basado en la matriz de pesos y el patrón actual
int actualizarPixel(const vector<vector<int>>& matrizPesos, const vector<int>& patron, int i) {
    int n = patron.size();
    int suma = 0;

    // Calculo la suma ponderada de las conexiones sinápticas
    for (int j = 0; j < n; ++j) {
        suma += matrizPesos[i][j] * patron[j];
    }
    
    // Aplico la función de activación (umbral): si la suma es >= 0, el píxel es 1, sino -1
    return (suma >= 0) ? 1 : -1;
}

// Función para recuperar un patrón a partir de una imagen de entrada con ruido
vector<int> recuperarPatron(const vector<vector<int>>& matrizPesos, vector<int> patron) {
    int n = patron.size();
    bool cambio = true;  // Variable para controlar si hay cambios en los píxeles durante las iteraciones

    // Actualizo los píxeles hasta que el patrón se estabilice (no haya cambios)
    while (cambio) {
        cambio = false;
        for (int i = 0; i < n; ++i) {
            int nuevoPixel = actualizarPixel(matrizPesos, patron, i);
            if (nuevoPixel != patron[i]) {
                patron[i] = nuevoPixel;  // Actualizo el píxel si hay un cambio
                cambio = true;  // Si hubo un cambio, seguimos iterando
            }
        }
    }
    return patron;
}

int main() {
    // Defino dos patrones (imágenes) de entrenamiento: 
    // Cada valor en el vector representa un píxel (1 = activo, -1 = inactivo)
    vector<vector<int>> patrones = {
        {1, 1, 1, 1, -1, -1, -1, -1, -1, -1},  // Patrón 1
        {-1, -1, -1, -1, 1, 1, 1, 1, -1, -1}   // Patrón 2
    };

    // Calculo la matriz de pesos basada en los patrones de entrenamiento
    vector<vector<int>> matrizPesos = calcularMatrizPesos(patrones);

    // Defino un patrón de entrada con ruido (algunos píxeles han cambiado)
    vector<int> patronEntrada = {1, -1, 1, 1, -1, 1, -1, -1, -1, -1};

    // Recupero el patrón original a partir de la imagen de entrada con ruido
    vector<int> patronRecuperado = recuperarPatron(matrizPesos, patronEntrada);

    // Muestro el patrón recuperado en la consola
    cout << "Patrón recuperado: ";
    for (int pixel : patronRecuperado) {
        cout << pixel << " ";  // se imprime cada valor de píxel (1 o -1)
    }
    cout << endl;

    return 0;
}
