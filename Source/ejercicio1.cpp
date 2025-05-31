#include "ejercicio1.hpp"

// ===== MedicionBase =====
MedicionBase::MedicionBase(double t)
    : tiempoMedicion(make_unique<double>(t)) {}

double MedicionBase::getTiempo() const {
    return *tiempoMedicion;
}

// ===== Presion =====
Presion::Presion(float p_estatica, float p_dinamica, double t)
    : MedicionBase(t),
      presionEstatica(p_estatica),
      presionDinamica(p_dinamica) {}

Presion::Presion(const Presion& copia)
    : MedicionBase(*copia.tiempoMedicion), 
      presionEstatica(copia.presionEstatica), 
      presionDinamica(copia.presionDinamica) {}

void Presion::imprimir() const {
    cout << "--- Medición de Presión ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Tiempo: " << getTiempo() << endl;
    cout << "P.Estatica: " << presionEstatica << " hPa";
    cout << " - P.Dinamica: " << presionDinamica << " hPa" << endl;
    cout << "\n";
}

void Presion::serializar(ofstream& archivo) const {
    if (!archivo.is_open()) {
        cerr << "Error: Archivo no abierto para serializar Presión." << endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(double));
    archivo.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    archivo.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
}

void Presion::deserializar(ifstream& archivo) {
    if (!archivo.is_open()) {
        cerr << "Error: Archivo no abierto para deserializar Presión." << endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(double));
    archivo.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    archivo.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
}

// ===== Posicion =====
Posicion::Posicion(float lat, float lon, float alt, double t)
    : MedicionBase(t), 
      latitud(lat), 
      longitud(lon), 
      altitud(alt) {}

Posicion::Posicion(const Posicion& copia)
    : MedicionBase(*copia.tiempoMedicion), 
      latitud(copia.latitud), 
      longitud(copia.longitud), 
      altitud(copia.altitud) {}

void Posicion::imprimir() const {
    cout << "--- Medición de Posición ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Tiempo: " << getTiempo() << endl;
    cout << "Lat: " << latitud << " grados";
    cout << " - Long: " << longitud << " grados";
    cout << " - Alt: " << altitud << " m" << endl;
    cout << "\n";
}

void Posicion::serializar(ofstream& archivo) const {
    if (!archivo.is_open()) {
        cerr << "Error: Archivo no abierto para serializar Posición." << endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(double));
    archivo.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    archivo.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    archivo.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
}

void Posicion::deserializar(ifstream& archivo) {
    if (!archivo.is_open()) {
        cerr << "Error: Archivo no abierto para deserializar Posición." << endl;
        return;
    }
    archivo.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(double));
    archivo.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    archivo.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    archivo.read(reinterpret_cast<char*>(&altitud), sizeof(float));
}

// ===== SaveFlightData =====
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q)
    : posicion(p), presion(q) {}

void SaveFlightData::serializar(const string& filename) const {
    ofstream archivo(filename, ios::binary);
    if (!archivo.is_open()) {
        cerr << "**Error**, no se pudo abrir " << filename << " para grabar" << endl;
        return;
    }
    posicion.serializar(archivo);
    presion.serializar(archivo);
    archivo.close();
    cout << BOLD << "Datos guardados en '" << filename << RESET << endl;
}

void SaveFlightData::deserializar(const string& filename) {
    ifstream archivo(filename, ios::binary);
    if (!archivo.is_open()) {
        cerr << "**Error**, no se pudo abrir " << filename << " para leer" << endl;
        return;
    }
    posicion.deserializar(archivo);
    presion.deserializar(archivo);
    archivo.close();
    cout << BOLD << "Datos leidos desde '" << filename << RESET << endl;
}

void SaveFlightData::imprimir() const {
    posicion.imprimir();
    presion.imprimir();
}