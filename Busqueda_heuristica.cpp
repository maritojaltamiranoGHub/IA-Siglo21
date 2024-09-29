#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>

struct Nodo {
    double posicion;
    double costoAcumulado;
    double heuristica;
    double costoTotal;

    bool operator>(const Nodo& otro) const {
        return costoTotal > otro.costoTotal;
    }
};

// Heurística: distancia directa al objetivo
double heuristica(double posicionActual, double posicionObjetivo) {
    return std::abs(posicionActual - posicionObjetivo);
}

// Función para realizar la búsqueda A*
void busquedaA(double posicionInicial, double posicionObjetivo, double rango, double incremento) {
    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> colaPrioridad;
    std::unordered_map<double, double> costosConocidos;

    // Agregar la posición inicial a la cola
    Nodo nodoInicial = { posicionInicial, 0.0, heuristica(posicionInicial, posicionObjetivo), 0.0 };
    nodoInicial.costoTotal = nodoInicial.costoAcumulado + nodoInicial.heuristica;
    colaPrioridad.push(nodoInicial);

    while (!colaPrioridad.empty()) {
        Nodo nodoActual = colaPrioridad.top();
        colaPrioridad.pop();

        // Verificar si se ha alcanzado el objetivo
        if (heuristica(nodoActual.posicion, posicionObjetivo) < incremento) {
            std::cout << "Posición encontrada en: " << nodoActual.posicion << std::endl;
            return;
        }

        // Explorar posiciones adyacentes
        for (double nuevaPosicion : { nodoActual.posicion + incremento, nodoActual.posicion - incremento }) {
            if (nuevaPosicion < 0 || nuevaPosicion > posicionObjetivo + rango) continue; // Fuera de rango

            double nuevoCosto = nodoActual.costoAcumulado + incremento;
            if (costosConocidos.find(nuevaPosicion) == costosConocidos.end() || nuevoCosto < costosConocidos[nuevaPosicion]) {
                costosConocidos[nuevaPosicion] = nuevoCosto;
                Nodo nuevoNodo = { nuevaPosicion, nuevoCosto, heuristica(nuevaPosicion, posicionObjetivo), 0.0 };
                nuevoNodo.costoTotal = nuevoNodo.costoAcumulado + nuevoNodo.heuristica;
                colaPrioridad.push(nuevoNodo);
            }
        }
    }

    std::cout << "Posición no encontrada en el rango dado." << std::endl;
}

int main() {
    double posicionInicial = 0.0; // Posición inicial del block
    double posicionObjetivo = 5.35; // Posición real del block
    double rango = 10.0; // Rango de búsqueda
    double incremento = 0.05; // Incremento en cada búsqueda

    // Ejecutar la búsqueda A*
    busquedaA(posicionInicial, posicionObjetivo, rango, incremento);

    return 0;
}
