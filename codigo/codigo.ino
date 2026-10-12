enum ESTADO {
  PARADO,
  FRENTE,
  TRAS
};

//Pinos que controlam o motor driver, o primeiro e o Input 1, 
//o segundo e oo input 2
const int MotorDriver1 = 12;
const int MotorDriver2 = 14;

void setup() {

  pinMode(MotorDriver1, OUTPUT);
  pinMode(MotorDriver2, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  Serial.println("Set up pronto");
}

void loop() {
  if (Serial.available() > 0) {

    String comando = Serial.readStringUntil('\n');
    comando.trim();

    Serial.print("comando ");
    Serial.println(comando);
    MudarDeEstado(comando);
  }

}

void MudarDeEstado(String comando) {
  if (comando == "parar"){
    digitalWrite(MotorDriver1, LOW);
    digitalWrite(MotorDriver2, LOW);
    Serial.println("comando parar");
  }
  else if (comando == "frente"){
    digitalWrite(MotorDriver1, HIGH);
    digitalWrite(MotorDriver2, LOW);
    Serial.println("comando frente");
  }
  else if (comando == "tras"){
    digitalWrite(MotorDriver1, LOW);
    digitalWrite(MotorDriver2, HIGH);
  }
}
