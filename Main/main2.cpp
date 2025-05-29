#include "ejercicio2.hpp"

int main() {
    // Puntos de referencia
    Punto centro; // Inicializado por defecto (0,0)
    Punto esquina(1.0f, 1.0f);

    // Crear figuras
    Circulo c(centro, 5.0f);               // Radio 5 → Área esperada ≈ 78.54
    Elipse e(centro, 6.0f, 3.0f);          // Semiejes 6 y 3 → Área esperada ≈ 56.55
    Rectangulo r(esquina, 4.0f, 8.0f);     // Ancho 4, Largo 8 → Área esperada = 32.0

    // Calcular áreas
    // Como calcularArea() es un método static, se llama directamente desde la clase
    // No hace falta crear una instancia de ProcesadorFigura<T> para usarlo
    float areaCirculo = ProcesadorFigura<Circulo>::calcularArea(c);
    float areaElipse = ProcesadorFigura<Elipse>::calcularArea(e);
    float areaRectangulo = ProcesadorFigura<Rectangulo>::calcularArea(r);

    // Mostrar resultados
    cout << BOLD << "Área del círculo: " << RESET << areaCirculo << endl;
    cout << BOLD << "Área del elipse: " << RESET <<  areaElipse << endl;
    cout << BOLD << "Área del rectángulo: " << RESET << areaRectangulo << endl;

    return 0;
}
