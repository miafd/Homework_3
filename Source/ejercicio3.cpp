#include "ejercicio3.hpp"

const vector<double>& GeneradorDatos:: getDoubles() const { return vec_doubles; }
const vector<string>& GeneradorDatos::  getPalabras() const  { return palabras; }
const vector<vector<int>>& GeneradorDatos:: getListas() const { return listas; }


// Función auxiliar para vector de doubles
string ConstructorJSON::vectorDoublesToJSON(const vector<double>& v) const {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << v[i];
        if (i < v.size() - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Función auxiliar para vector de strings
string ConstructorJSON::vectorStringsToJSON(const vector<string>& v) const {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << "\"" << v[i] << "\"";
        if (i < v.size() - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Función auxiliar para vector de vector<int>
string ConstructorJSON::vectorListasToJSON(const vector<vector<int>>& listas) const {
    ostringstream oss;
    oss << "[" << endl;
    for (size_t i = 0; i < listas.size(); ++i) {
        oss << "      [";
        for (size_t j = 0; j < listas[i].size(); ++j) {
            oss << listas[i][j];
            if (j < listas[i].size() - 1) oss << ", ";
        }
        oss << "]";
        if (i < listas.size() - 1) oss << ",";  // coma solo entre filas
        oss << endl;
    }
    oss << "      ]";
    return oss.str();
}

//Constructor Clase2
ConstructorJSON::ConstructorJSON(const GeneradorDatos& datos) : datos(datos) {}

// Método para generar el JSON
void ConstructorJSON::generarJSON() const {
    cout << "{" << endl;
    cout << "  \"vec_doubles\": " << vectorDoublesToJSON(datos.getDoubles()) << "," << endl;
    cout << "  \"palabras\": " << vectorStringsToJSON(datos.getPalabras()) << "," << endl;
    cout << "  \"listas\": " << vectorListasToJSON(datos.getListas()) << endl;
    cout << "}" << endl;
}
