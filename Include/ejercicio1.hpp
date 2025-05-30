#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class IMediciones {
    public:
        virtual void serializar(ofstream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;

        virtual ~IMediciones() = default;
};

class MedicionBase : public IMediciones {
    protected:
        unique_ptr<double> tiempoMedicion;
    public:
        MedicionBase(double tiempo)
            : tiempoMedicion(make_unique<double>(tiempo)) {}

        double getTiempo() const {}
        virtual void imprimir() const = 0;
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;

};


class Posicion : public MedicionBase {
    public: 
        double x, y, z;

        Posicion(double tiempo, double x, double y, double z)
            : MedicionBase(tiempo), x(x), y(y), z(z) {}
        
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
        
        ~Posicion() override = default;

};

class Presion : public MedicionBase {
    public:
    double pe, pd;

    Presion(double tiempo, double pe, double pd)
        : MedicionBase(tiempo), pe(pe), pd(pd) {}
    
    void serializar(ofstream& out) const override;
    void deserializar(ifstream& in) override;

    ~Presion() override = default;
    
};

class SaveFlightData {
    public:

    Posicion posicion;
    Presion presion;

    SaveFlightData(const Posicion& pos, const Presion& pres)
        : posicion(pos), presion(pres) {}

    void serializar(ofstream& out) const; 
    void deserializar(ifstream& in); 

    void imprimir() const {}
    
};
