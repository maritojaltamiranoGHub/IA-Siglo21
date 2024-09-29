
#include <iostream>
#include <cmath>

// Tolerancia para definir si el robot ha encontrado la posición exacta
const double TOLERANCIA = 0.01;

// Simulación del sensor del robot que verifica si está en la posición correcta
bool verificarPosicion(double posicionActual, double posicionObjetivo) {
    return std::abs(posicionActual - posicionObjetivo) <= TOLERANCIA;
}

// Función para realizar la búsqueda exhaustiva
void busquedaExhaustiva(double posicionInicial, double posicionObjetivo, double incremento) {
    double posicionActual = posicionInicial;
    
    // Búsqueda en la dirección positiva
    while (posicionActual <= posicionObjetivo + 10) {  // Rango arbitrario de búsqueda hacia la derecha
        if (verificarPosicion(posicionActual, posicionObjetivo)) {
            std::cout << "Posición encontrada en: " << posicionActual << std::endl;
            return;
        }
        posicionActual += incremento;
    }

    // Reiniciar para buscar en la dirección negativa
    posicionActual = posicionInicial;

    // Búsqueda en la dirección negativa
    while (posicionActual >= posicionObjetivo - 10) {  // Rango arbitrario de búsqueda hacia la izquierda
        if (verificarPosicion(posicionActual, posicionObjetivo)) {
            std::cout << "Posición encontrada en: " << posicionActual << std::endl;
            return;
        }
        posicionActual -= incremento;
    }

    std::cout << "Posición no encontrada en el rango dado." << std::endl;
}

int main() {
    // Posición inicial teórica del block
    double posicionInicial = 0.0;
    
    // Posición real que el robot debe encontrar
    double posicionObjetivo = 5.40;
    
    // Incremento en cada búsqueda (precisión del movimiento)
    double incremento = 0.05;

    // Ejecutar la búsqueda exhaustiva
    busquedaExhaustiva(posicionInicial, posicionObjetivo, incremento);

    return 0;
}
