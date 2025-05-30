#ifndef EJERCICIO3_HPP
#define EJERCICIO3_HPP

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

    // Template para convertir a JSON 
    template <typename T>
    string convertirAJSON(const vector<T>& vec) const {
        ostringstream oss;
        
        if constexpr (is_same_v<T, double>) {
            oss << "[";
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << vec[i];
                if (i < vec.size() - 1) oss << ", ";
            }
            oss << "]";
        } else if constexpr (is_same_v<T, string>) {
            oss << "[";
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << "\"" << vec[i] << "\"";
                if (i < vec.size() - 1) oss << ", ";
            }
            oss << "]";
        } else if constexpr (is_same_v<T, vector<int>>) {
            oss << "[" << endl;
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << "      [";
                for (size_t j = 0; j < vec[i].size(); ++j) {
                    oss << vec[i][j];
                    if (j < vec[i].size() - 1) oss << ", ";
                }
                oss << "]";
                if (i < vec.size() - 1) oss << ",";
                oss << endl;
            }
            oss << "      ]";
        } else {
            static_assert(sizeof(T) == 0, "Tipo no soportado para conversión a JSON.");
        }

        return oss.str();
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

public:
    ConstructorJSON(const GeneradorDatos& datos);
    void generarJSON() const;
};

#endif // EJERCICIO3_HPP
