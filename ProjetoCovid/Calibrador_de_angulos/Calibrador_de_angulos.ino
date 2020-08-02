//Calibragem do angulo do servo mecânico com um potenciometro e a serial 
#include <Servo.h>

Servo myservo;  // Objeto servo

int potpin = 0;  // pino analôgico usado para conectar o potenciometro 
int val;    // variavel usada para armazenar o valor lido no pino analôgico do potenciometro
void setup() {
  Serial.begin(9600); //Inicializa serial para verificar os angulos de calibração
  Serial.println("Calibragem dos ângulos do servo...");
  myservo.attach(9);  // o servo é controlado pelo pino 9
}

void loop() {
  val = analogRead(potpin);            // ler o valor fornecido pelo potenciometro (value entre 0 e 1023)
  val = map(val, 0, 1023, 0, 180);     // converte a escala para graus, para que o servo possa ser controlado (value entre 0 e 180)
  Serial.print("ÂNGULO DO SERVO: ");
  Serial.println(val);     //printa o valor do angulo na serial a medida que controlamos o servo com o potenciometro, até encontrar a posição desejada
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
