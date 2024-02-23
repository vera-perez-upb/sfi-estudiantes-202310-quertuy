#include <Arduino.h>

// Definición de estados y variable de estado
enum class ProgramStates {
    INIT,
    WAIT_1_SECOND,
    WAIT_2_SECONDS,
    WAIT_3_SECONDS
};

ProgramStates programState = ProgramStates::INIT;

// Definición de variables static (conservan su valor entre llamadas a programa)
unsigned long lastTime = 0;

// Constantes
const unsigned long INTERVAL_1_SECOND = 1000;
const unsigned long INTERVAL_2_SECONDS = 2000;
const unsigned long INTERVAL_3_SECONDS = 3000;

// Función para enviar un mensaje por el puerto serial
void enviar_mensaje(const String& mensaje) {
    Serial.println(mensaje);
}

// MÁQUINA de ESTADOS
void programa() {
    unsigned long currentTime = millis();

    switch (programState) {
        case ProgramStates::INIT:
            // Acciones:
            enviar_mensaje("Programa iniciado");
            
            // Garantiza los valores iniciales para el siguiente estado.
            lastTime = millis();
            programState = ProgramStates::WAIT_1_SECOND;
            break;
        
        case ProgramStates::WAIT_1_SECOND:
            // Evento
            if (currentTime - lastTime >= INTERVAL_1_SECOND) {
                // Acciones:
                enviar_mensaje("Ha pasado 1 segundo");
                lastTime = currentTime;
                programState = ProgramStates::WAIT_2_SECONDS;
            }
            break;
        
        case ProgramStates::WAIT_2_SECONDS:
            // Evento
            if (currentTime - lastTime >= INTERVAL_2_SECONDS) {
                // Acciones:
                enviar_mensaje("Han pasado 2 segundos");
                lastTime = currentTime;
                programState = ProgramStates::WAIT_3_SECONDS;
            }
            break;
        
        case ProgramStates::WAIT_3_SECONDS:
            // Evento
            if (currentTime - lastTime >= INTERVAL_3_SECONDS) {
                // Acciones:
                enviar_mensaje("Han pasado 3 segundos");
                lastTime = currentTime;
                programState = ProgramStates::WAIT_1_SECOND;
            }
            break;
        
        default:
            enviar_mensaje("Error");
            break;
    }
}

void setup() {
    Serial.begin(9600);
    programa(); // Llama al programa en la inicialización
}

void loop() {
    programa(); // Bucle principal para ejecutar el programa repetidamente
}
