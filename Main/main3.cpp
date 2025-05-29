#include "ejercicio3.hpp"

int main() {
    GeneradorDatos generador;

    // Agregar doubles
    generador.agregar(1.3);
    generador.agregar(2.1);
    generador.agregar(3.2);

    // Agregar palabras
    generador.agregar(string("Hola"));
    generador.agregar(string("Mundo"));

    // Agregar listas de enteros
    generador.agregar(vector<int>{1, 2});
    generador.agregar(vector<int>{3, 4});

    // Construir JSON
    ConstructorJSON builder(generador);
    builder.generarJSON();

    return 0;
}
