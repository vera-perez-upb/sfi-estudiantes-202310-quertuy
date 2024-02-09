void setup() {
  // Configura el pin del LED incorporado como salida
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Variables estáticas para almacenar el tiempo anterior y el estado del LED
  static uint32_t previousTime = 0;
  static bool ledState = true;

  // Lee el tiempo actual en milisegundos
  uint32_t currentTime = millis();

  // Comprueba si ha pasado un intervalo de 100 ms
  if( (currentTime - previousTime) > 300){
    // Actualiza el tiempo anterior con el tiempo actual
    previousTime = currentTime;
    // Invierte el estado del LED
    ledState = !ledState;
    // Escribe el estado del LED en el pin LED_BUILTIN
    digitalWrite(LED_BUILTIN, ledState);
  }
}