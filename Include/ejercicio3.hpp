
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>

using namespace std;


// Clase 1: Generadora de datos
class GeneradorDatos {
private:
    vector<double> vec_doubles;
    vector<string> palabras;
    vector<vector<int>> listas;

public:
    // Template para agregar datos genéricos
    template <typename T>
    void agregar(const T& dato) {
        if constexpr (is_same_v<T, double>) {
            vec_doubles.push_back(dato);
        } else if constexpr (is_same_v<T, string>) {
            palabras.push_back(dato);
        } else if constexpr (is_same_v<T, vector<int>>) {
            listas.push_back(dato);
        } else {
            static_assert(sizeof(T) == 0, "Tipo no soportado");
        }
    }

    // Getters para Clase 2
    const vector<double>& getDoubles() const;
    const vector<string>& getPalabras() const;
    const vector<vector<int>>& getListas() const;

};


// Clase 2: Construcción de JSON
class ConstructorJSON {
private:
    const GeneradorDatos& datos;

    // Función auxiliar para vector de doubles
    string vectorDoublesToJSON(const vector<double>& v) const;

    // Función auxiliar para vector de strings
    string vectorStringsToJSON(const vector<string>& v) const;

    // Función auxiliar para vector de vector<int>
    string vectorListasToJSON(const vector<vector<int>>& listas) const;
    

public:
    ConstructorJSON(const GeneradorDatos& datos);

    void generarJSON() const;
};
