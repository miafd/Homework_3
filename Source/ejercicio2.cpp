#include "ejercicio2.hpp"

// Implementación de Punto
Punto::Punto() : x(0), y(0) {}
Punto::Punto(float x, float y) : x(x), y(y) {}
float Punto::getX() const { return x; }
float Punto::getY() const { return y; }
void Punto::setX(float x) { this->x = x; }
void Punto::setY(float y) { this->y = y; }

// Implementación de Circulo
Circulo::Circulo(Punto centro, float radio) : centro(centro), radio(radio) {}
float Circulo::getRadio() const { return radio; }
Punto Circulo::getCentro() const { return centro; }
void Circulo::setRadio(float radio) { this->radio = radio; }
void Circulo::setCentro(Punto centro) { this->centro = centro; }

// Implementación de Elipse
Elipse::Elipse(Punto centro, float radioMayor, float radioMenor) : 
    centro(centro), radioMayor(radioMayor), radioMenor(radioMenor) {}
float Elipse::getRadioMayor() const { return radioMayor; }
float Elipse::getRadioMenor() const { return radioMenor; }
Punto Elipse::getCentro() const { return centro; }
void Elipse::setRadioMayor(float radioMayor) { this->radioMayor = radioMayor; }
void Elipse::setRadioMenor(float radioMenor) { this->radioMenor = radioMenor; }
void Elipse::setCentro(Punto centro) { this->centro = centro; }

// Implementación de Rectangulo
Rectangulo::Rectangulo(Punto esquinaInferiorIzquierda, float ancho, float largo) : 
    esquinaInferiorIzquierda(esquinaInferiorIzquierda), ancho(ancho), largo(largo) {}
float Rectangulo::getAncho() const { return ancho; }
float Rectangulo::getLargo() const { return largo; }
Punto Rectangulo::getEsquinaInferiorIzquierda() const { return esquinaInferiorIzquierda; }
void Rectangulo::setAncho(float ancho) { this->ancho = ancho; }
void Rectangulo::setLargo(float largo) { this->largo = largo; }
void Rectangulo::setEsquinaInferiorIzquierda(Punto esquinaInferiorIzquierda) {
    this->esquinaInferiorIzquierda = esquinaInferiorIzquierda;
}

// Implementación de ProcesadorFigura
float ProcesadorFigura<Circulo>::calcularArea(const Circulo& c) {
    return PI * c.getRadio() * c.getRadio();
}

float ProcesadorFigura<Elipse>::calcularArea(const Elipse& e) {
    return PI * e.getRadioMayor() * e.getRadioMenor();
}

float ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& r) {
    return r.getAncho() * r.getLargo();
}

