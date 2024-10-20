# IA-Siglo21 

**modelo de Hopfield**

Se presenta un ejemplo básico (modelo de Hopfield.cpp) de cómo se podría implementar un prototipo en C++
para simular el modelo de Hopfield, considerando una imagen pequeña de 10x10 píxeles y
utilizando el aprendizaje de Hebb.


Main():
Se definen dos patrones simples (imágenes) para entrenamiento.
Se calcula la matriz de pesos a partir de esos patrones.
Se utiliza un patrón de entrada ruidoso y se aplica el modelo de Hopfield para recuperar el
patrón original.
Finalmente, se muestra el patrón recuperado en la consola.

Función calcularMatrizPesos():
Calcula la matriz de pesos para la red de Hopfield usando la regla
de aprendizaje de Hebb. Se omiten las conexiones entre neuronas individuales (sin autoconexión)
poniendo la diagonal de la matriz en cero.
Función actualizarPixel():
Dada la matriz de pesos y el patrón actual, esta función calcula el nuevo
valor de un píxel basado en la suma ponderada de las conexiones sinápticas y una función de
activación con umbral.
Función recuperarPatron():
A partir de una imagen de entrada (que puede tener ruido), esta
función recupera el patrón original. La recuperación se realiza actualizando los píxeles
iterativamente hasta que el patrón se estabilice.

**Búsqueda exaustiva**

verificarPosicion(): Esta función simula el sensor del robot, verificando si la posición actual está dentro de la tolerancia del objetivo.
busquedaExhaustiva(): Implementa el algoritmo de búsqueda exhaustiva. Comienza buscando en la dirección positiva y, si no encuentra el objetivo, reinicia y busca en la dirección negativa.
main(): Define las posiciones iniciales y objetivo, así como el incremento para la búsqueda. Luego llama a la función de búsqueda exhaustiva.

**Búsqueda heurística**

Estructura Nodo{}: Define la estructura básica que contiene la posición actual, el costo acumulado, la heurística y el costo total.
Función Heuristica(): Calcula la distancia entre la posición actual y el objetivo.
Función de BusquedaA(): Implementa el algoritmo, utilizando una cola de prioridad para explorar primero los nodos más prometedores.
Main(): Configura las posiciones iniciales y objetivo, así como el rango y el incremento para la búsqueda.

