//estamos desenvolvendo um projeto de um semáforo utilizando o arduino, onde o semáforo irá acender as luzes vermelha, amarela e verde, cada uma por um tempo determinado, e depois irá repetir o ciclo.
//definindo os pinos dos LEDs
const int ledVermelho = 2;
const int ledAmarelo = 3;
const int ledVerde = 4;

//iniciando o programa com um botão para iniciar o ciclo do semáforo
const int botao = 5; //pino do botão

void setup() {
  //inicializando os pinos dos LEDs como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(botao) == LOW) {
    delay(50); // debounce simples
    if (digitalRead(botao) == LOW) {
      while (digitalRead(botao) == LOW) {
        delay(10);
      }

      //acendendo o LED verde por 5 segundos
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, HIGH);
      delay(5000); //tempo em milissegundos

      //acendendo o LED amarelo por 2 segundos
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);
      delay(2000); //tempo em milissegundos

      //acendendo o LED vermelho por 5 segundos
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, LOW);
      delay(5000); //tempo em milissegundos

    }
  }

  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
}


    