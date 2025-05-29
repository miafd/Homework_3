#ifndef EJERCICIO2_HPP
#define EJERCICIO2_HPP

#include <iostream>
using namespace std;

const float PI = 3.14159265f;
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Punto {
    private:
        float x;
        float y;
    public:
        Punto(); // Constructor por defecto
        Punto(float x, float y);
        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);
};

class Circulo {
    private:
        Punto centro;
        float radio;
    public:
        Circulo(Punto centro, float radio);
        float getRadio() const;
        Punto getCentro() const;
        void setRadio(float radio);
        void setCentro(Punto centro);
};

class Elipse {
    private:
        Punto centro;
        float radioMayor;
        float radioMenor;
    public:
        Elipse(Punto centro, float radioMayor, float radioMenor);
        float getRadioMayor() const;
        float getRadioMenor() const;
        Punto getCentro() const;
        void setRadioMayor(float radioMayor);
        void setRadioMenor(float radioMenor);
        void setCentro(Punto centro);
};

class Rectangulo {
    private:
        Punto esquinaInferiorIzquierda;
        float ancho;
        float largo;
    public:
        Rectangulo(Punto esquinaInferiorIzquierda, float ancho, float largo);
        float getAncho() const;
        float getLargo() const;
        Punto getEsquinaInferiorIzquierda() const;
        void setAncho(float ancho);
        void setLargo(float largo);
        void setEsquinaInferiorIzquierda(Punto esquinaInferiorIzquierda);
};

template <typename T>
class ProcesadorFigura {
public:
    static float calcularArea(const T& figura); //static -> no necesita atributos, solo opera sobre la figura dada
};

// Declaraciones de especializaciones
template<>
class ProcesadorFigura<Circulo> {
public:
    static float calcularArea(const Circulo& c);
};

template<>
class ProcesadorFigura<Elipse> {
public:
    static float calcularArea(const Elipse& e);
};

template<>
class ProcesadorFigura<Rectangulo> {
public:
    static float calcularArea(const Rectangulo& r);
};

#endif

