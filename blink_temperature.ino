#include <Arduino_HTS221.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!HTS.begin()) {
    Serial.println("Failed to initialize temperature sensor!");
    while (1);
  }

  // Pins for the built-in RGB LEDs on the Arduino Nano 33 BLE Sense
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // Note: The RGB LEDs are ON when the pin is LOW and off when HIGH.
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}
void loop() {
  float temperature = HTS.readTemperature();

  // Define a temperatura maxima na variação da temperatura ambiente

  const float high_temperature = 30.00; 

  // Define a temperatura mínima na variação da temperatura ambiente
  
  const float low_temperature = 28.00; 

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Se ele estiver dentro do intervalo definido como a temperatura ambiente, então ele pisca o led verde

  if((temperature >= low_temperature) && (temperature <= high_temperature)) {
    digitalWrite(LEDG, LOW); 
    delay(1000);              
    digitalWrite(LEDG, HIGH);    
    delay(1000);   
  }

  // Se a temperatura atual estiver acima da temperatura ambiente, então ele pisca o led vermelho

  if(temperature > high_temperature) {
    digitalWrite(LEDR, LOW); 
    delay(1000);              
    digitalWrite(LEDR, HIGH);    
    delay(1000); 
  }

  // Se a temperatura atual estiver abaixo da temperatura ambiente, então ele pisca o led azul

  if(temperature < low_temperature) {
    digitalWrite(LEDB, LOW); 
    delay(1000);              
    digitalWrite(LEDB, HIGH);    
    delay(1000);   
  }

  // print an empty line
  Serial.println();

}
