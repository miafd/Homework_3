#include "ejercicio3.hpp"

const vector<double>& GeneradorDatos:: getDoubles() const { return vec_doubles; }
const vector<string>& GeneradorDatos::  getPalabras() const  { return palabras; }
const vector<vector<int>>& GeneradorDatos:: getListas() const { return listas; }

// Constructor de Clase 2
ConstructorJSON::ConstructorJSON(const GeneradorDatos& datos) : datos(datos) {}

// Método para generar el JSON
void ConstructorJSON::generarJSON() const {
    cout << "{" << endl;
    cout << "  \"vec_doubles\": " << datos.convertirAJSON(datos.getDoubles()) << "," << endl;
    cout << "  \"palabras\": " << datos.convertirAJSON(datos.getPalabras()) << "," << endl;
    cout << "  \"listas\": " << datos.convertirAJSON(datos.getListas()) << endl;
    cout << "}" << endl;
}
