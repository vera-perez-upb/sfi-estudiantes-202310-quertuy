// Incluimos la biblioteca Arduino para poder utilizar las funciones de la placa
#include <Arduino.h>

// Definimos los estados de la tarea 1
enum class Task1States {
    INIT,
    WAIT_FOR_TIMEOUT
};

// Definimos los estados de la tarea 2
enum class Task2States {
    INIT,
    WAIT_FOR_TIMEOUT
};

// Definimos los estados de la tarea 3
enum class Task3States {
    INIT,
    WAIT_FOR_TIMEOUT
};

// Variables globales para las tareas
unsigned long lastTime1; // Almacena el tiempo del último evento de la tarea 1
unsigned long lastTime2; // Almacena el tiempo del último evento de la tarea 2
unsigned long lastTime3; // Almacena el tiempo del último evento de la tarea 3
const uint32_t INTERVAL1 = 1000; // Intervalo de tiempo para la tarea 1 (1 Hz)
const uint32_t INTERVAL2 = 2000; // Intervalo de tiempo para la tarea 2 (0.5 Hz)
const uint32_t INTERVAL3 = 4000; // Intervalo de tiempo para la tarea 3 (0.25 Hz)

// Función para enviar un mensaje por el puerto serie
void enviarMensaje(const String& mensaje) {
    Serial.println(mensaje);
}

// Tarea 1: enviar un mensaje cada segundo (1 Hz)
void task1() {
    // Máquina de estados para la tarea 1
    static Task1States task1State = Task1States::INIT;

    switch(task1State) {
        case Task1States::INIT: {
            // Inicializamos la comunicación serie
            Serial.begin(115200);
            // Obtenemos el tiempo actual
            lastTime1 = millis();
            // Pasamos al estado de espera por el evento
            task1State = Task1States::WAIT_FOR_TIMEOUT;
            break;
        }

        case Task1States::WAIT_FOR_TIMEOUT: {
            // Obtenemos el tiempo actual
            unsigned long currentTime = millis();
            // Verificamos si ha transcurrido el intervalo de tiempo
            if ((currentTime - lastTime1) >= INTERVAL1) {
                // Guardamos el tiempo del último evento
                lastTime1 = currentTime;
                // Enviamos el mensaje por el puerto serie
                enviarMensaje("Mensaje a 1 Hz");
            }
            break;
        }

        default: {
         
