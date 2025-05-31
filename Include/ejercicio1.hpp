#ifndef MEDICIONES_HPP
#define MEDICIONES_HPP

#include <iostream> // Para cout, fixed, scientific
#include <fstream>  // Para ofstream, ifstream
#include <string>   // Para string
#include <memory>   // Para unique_ptr
#include <iomanip>  // Para setprecision

#define BOLD "\033[1m"
#define RESET "\033[0m"

using namespace std;


// 1. Interfaz IMediciones 
class IMediciones {
public:
    // Métodos virtuales puros para serialización y deserialización
    virtual void serializar(ofstream& out) const = 0;
    virtual void deserializar(ifstream& in) = 0;

    // Destructor virtual para asegurar la correcta liberación de memoria
    virtual void imprimir() const = 0;
    virtual ~IMediciones() = default;
};

// 2. Clase Abstracta MedicionBase
class MedicionBase : public IMediciones {
protected:
    unique_ptr<double> tiempoMedicion;

public:
    // Constructor de MedicionBase
    explicit MedicionBase(double t); 
    
    // Destructor virtual
    virtual ~MedicionBase() = default;

    double getTiempo() const;

    // Método virtual puro para imprimir
    virtual void imprimir() const = 0;
};

// 3. Clase Presion
class Presion : public MedicionBase {
public:
    float presionEstatica, presionDinamica;

    // Constructor de Presion. Ahora toma time_t para el tiempo.
    Presion(float p_estatica, float p_dinamica, double t);

    // Constructor de copia para cumplir el requisito 'c'
    Presion(const Presion& copia);

    // Sobreescribe el método imprimir() para mostrar la fecha y hora
    void imprimir() const override;

    // Implementación de serializar para Presion
    void serializar(ofstream& archivo) const override;

    // Implementación de deserializar para Presion
    void deserializar(ifstream& archivo) override;
};

// 4. Clase Posicion
class Posicion : public MedicionBase {
public:
    float latitud, longitud, altitud;

    // Constructor de Posicion. Ahora toma time_t para el tiempo.
    Posicion(float lat, float lon, float alt, double t);

    // Constructor de copia para cumplir el requisito 'c'
    Posicion(const Posicion& copia);

    // Sobreescribe el método imprimir() para mostrar la fecha y hora
    void imprimir() const override;

    // Implementación de serializar para Posicion
    void serializar(ofstream& archivo) const override;

    // Implementación de deserializar para Posicion
    void deserializar(ifstream& archivo) override;
};

// 5. Clase SaveFlightData
class SaveFlightData {
public:
    Posicion posicion; // Composición
    Presion presion;   // Composición

    // Constructor de SaveFlightData.
    // Recibe referencias constantes y usa los constructores de copia definidos en Posicion y Presion.
    SaveFlightData(const Posicion& p, const Presion& q);

    // Método para serializar ambas mediciones a un archivo.
    void serializar(const string& filename) const;

    // Método para deserializar ambas mediciones desde un archivo.
    void deserializar(const string& filename);

    // Método para imprimir ambas mediciones
    void imprimir() const;
};

#endif 
