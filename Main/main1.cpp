#include "ejercicio1.hpp"

int main() {

    // Valores de prueba indicados en el enunciado del ejercicio
    Posicion posicion_a_guardar(-34.6f, -58.4f, 950.0f, 5.3);
    Presion  presion_a_guardar(101.3f, 5.8f, 6.1f);   

    // Almacena en archivo el nombre del archivo para guardar los valores
    const string archivo_logger = "REGISTRO_DE_VUELO.BIN";

    // Crea un objeto SaveFlightData y lo serializa
    SaveFlightData info_a_guardar(posicion_a_guardar, presion_a_guardar);
    info_a_guardar.serializar(archivo_logger);
    info_a_guardar.imprimir();    

    // Crea un objeto SaveFlightData con valores por defecto para cargar los datos y los deserializa
    Posicion posicion_leida(0.0f, 0.0f, 0.0f, 0); 
    Presion presion_leida(0.0f, 0.0f, 0);
    SaveFlightData info_a_mostrar(posicion_leida, presion_leida);
    info_a_mostrar.deserializar(archivo_logger);
    info_a_mostrar.imprimir();       // Lo impreime de clase SaveFlightData
 

    return 0;
}
