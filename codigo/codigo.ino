enum ESTADO {
  PARADO,
  FRENTE,
  TRAS
};

ESTADO estadoAtual = PARADO;

//Pinos que controlam o motor driver, o primeiro e o Input 1, 
//o segundo e oo input 2
const int MotorDriver1 = 13;
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
    
    ESTADO proximoEstado = interpretarComando(comando);
    MudarDeEstado(proximoEstado);
  }

}

ESTADO interpretarComando(String comando){
  comando.toLowerCase();
  if(comando == "frente") return FRENTE;
  if(comando == "tras") return TRAS;
  return PARADO;
}

void MudarDeEstado(ESTADO estadoNovo) {
  estadoAtual = estadoNovo;

  if (estadoAtual == PARADO){
    digitalWrite(MotorDriver1, LOW);
    digitalWrite(MotorDriver2, LOW);
    Serial.println("comando parar");
  }
  else if (estadoAtual == FRENTE){
    digitalWrite(MotorDriver1, HIGH);
    digitalWrite(MotorDriver2, LOW);
    Serial.println("comando frente");
  }
  else if (estadoAtual == TRAS){
    digitalWrite(MotorDriver1, LOW);
    digitalWrite(MotorDriver2, HIGH);
    Serial.println("comando tras");
  }
}
