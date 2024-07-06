// LIBRERIAS


// CONSTANTES Y VARIABLES
const int PinIN1 = 17;
const int PinIN2 = 16;

#define TRIG 19
#define ECO 18

// PROTOTIPO DE FUNCIONES

void MedicionDistancia(long dur, long dist);

void setup() {

  // Configuracion de velocidad UART
  Serial.begin(9600);

  // Configuracion de salidas y entradas
  // Configuración de Ultrasonico
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);

  // Configuramos los pines como salida
  // Motores
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
}



void loop() {

  // variables para sensor de distancia
  long duracion;
  long distancia;

  MedicionDistancia(&duracion,&distancia);

  // Algoritmo para movilizarse

    if (distancia <= 10) {
    Serial.println("Menor a 10");
    digitalWrite(PinIN1, LOW);
    digitalWrite(PinIN2, LOW);
  }
  else {
    digitalWrite(PinIN1, HIGH);
    digitalWrite(PinIN2, LOW);
  }
}



////////////////////////////////////////////// FUNCIONES  //////////////////////////////////////////////

void MedicionDistancia(long dur, long dist) {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  dur = pulseIn(ECO, HIGH);
  dist = (dur / 2) / 29;
}

void Adelante(int velocidad){

}
void Atras(int velocidad){

}
void Izquierda(int velocidad){

}
void Derecha(int velocidad){

}
