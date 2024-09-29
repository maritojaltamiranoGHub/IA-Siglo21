# IA-Siglo21 

**Búsqueda exaustiva**

verificarPosicion(): Esta función simula el sensor del robot, verificando si la posición actual está dentro de la tolerancia del objetivo.
busquedaExhaustiva(): Implementa el algoritmo de búsqueda exhaustiva. Comienza buscando en la dirección positiva y, si no encuentra el objetivo, reinicia y busca en la dirección negativa.
main(): Define las posiciones iniciales y objetivo, así como el incremento para la búsqueda. Luego llama a la función de búsqueda exhaustiva.

**Búsqueda heurística**

Estructura Nodo{}: Define la estructura básica que contiene la posición actual, el costo acumulado, la heurística y el costo total.
Función Heuristica(): Calcula la distancia entre la posición actual y el objetivo.
Función de BusquedaA(): Implementa el algoritmo, utilizando una cola de prioridad para explorar primero los nodos más prometedores.
Main(): Configura las posiciones iniciales y objetivo, así como el rango y el incremento para la búsqueda.

