//dispensador automático 
#include <Servo.h> //biblioteca do servo 
Servo servo1;      //objeto servo 
int sensor = 3;   //sensor conectado ao pino 3 
int valSensor = 0; //varável usada para leitura do sensor 

void setup() {
  Serial.begin(9600);//comunicação serial para debugar 
  pinMode(sensor, INPUT); //porta 3 conectada ao sensor é um imput
  servo1.attach(6);  //servo está conectdo ao pino 6
}

void loop() {
  valSensor = digitalRead(sensor); // valSensor recebe o valor que o sensor entrega ao pino 3
  Serial.println(valSensor); //printa o valor do sensor na serial para debugar
  delay(10); // o sensor vai ser detectado de 10 em 10 milissegundos para evitar ruido

  if(valSensor == 1)//se a leitura do sensor digital for igual a 1, ele não detectou nada e o servo não dispensa o álcool em gel
  { 
    servo1.write(150); //o servo se move 150°(ângulo inicial) o valor tem que ser calibrado para um perfeito funcionamento 
    delay(1);          //o calibramento tem que ser feito com o código de calibragem para descobrir o ângulo inicial
  }

  if(valSensor == 0){  //se o sensor for assionado o estado vai da porta 3 vai ser 0 e o servo vai
                                                                        //dispensar o produto do recipiente
     servo1.write(100);  //servo se move para dispensar o produto
     delay(500);  //delay para não ocorrer interferência e o detector ficar acionando 
  }
}
