const int trigger = 2; 
const int echo = 3;

int distancia;
int distancia_max = 50;

int calc_dist(int trigger, int echo)  //Función para calcular la distancia en cm
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  unsigned long time_taken = pulseIn(echo, HIGH);
  int dist= time_taken*0.034/2;
  if (dist>50){
    dist = 50;
  }
  //Cabe destacar que la condición superior se debe simplemente a limitar los valores que puedan llegar a la función pero no es necesario para el correcto funcionamiento del código
  return dist;
}

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);                 //Es importante saber a que BR ponemos el serial por tal de poder sincronizarlo con nuestro ordenador y el programa de python 
}                                     //Además tambien es importante saber a que puerto está conectado el Arduino

void loop() {
  distancia = calc_dist(trigger,echo);    //Asignamos lo que nos retorna la función a una variable int para compararla con la distancia de detección asignada
  if(distancia < distancia_max) {
    Serial.println("Actuar");                 //En este condicional comparamos la distancia actual con la màxima y en caso de ser la actual inferior se ejecutará un print dentro del serial que el programa de python leerá
    delay(500);
  }
}
