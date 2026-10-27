
#include <DFRobotDFPlayerMini.h>

#define moduloMP3 Serial1
DFRobotDFPlayerMini mp3;

const int botao1 = 2;
const int botao2 = 3;

int estadoBotao1 = HIGH;
int estadoBotao2 = HIGH;

int ultimaLeitura1 = HIGH;
int ultimaLeitura2 = HIGH;

unsigned long ultimaMudanca1 = 0;
unsigned long ultimaMudanca2 = 0;

const unsigned long debounce = 50; // ms

void setup() {
  Serial.begin(9600);
  moduloMP3.begin(9600);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  Serial.println(F("Iniciando FalaPlaca..."));

  // isACK = false: necessário para muitos módulos clone que não respondem
  // ACK corretamente, o que travava o begin() esperando uma confirmação
  // que nunca chegava.
  if (!mp3.begin(moduloMP3, /*isACK=*/false, /*doReset=*/true)) {
    Serial.println(F("Erro ao iniciar o modulo MP3."));
    while (true) {
      // trava aqui - sem áudio não há como continuar
    }
  }

  mp3.volume(22); // 0 (mudo) a 30 (máximo)
  Serial.println(F("Modulo MP3 pronto!"));
}

void loop() {
  unsigned long agora = millis();

  // ---- Botão 1 ----
  int leitura1 = digitalRead(botao1);
  if (leitura1 != ultimaLeitura1) {
    ultimaMudanca1 = agora;
    ultimaLeitura1 = leitura1;
  }
  if ((agora - ultimaMudanca1) > debounce && leitura1 != estadoBotao1) {
    estadoBotao1 = leitura1;
    if (estadoBotao1 == LOW) {
      mp3.playFolder(1, 1); // toca 01/001.mp3
      Serial.println(F("Tocando: 001"));
    }
  }

  // ---- Botão 2 ----
  int leitura2 = digitalRead(botao2);
  if (leitura2 != ultimaLeitura2) {
    ultimaMudanca2 = agora;
    ultimaLeitura2 = leitura2;
  }
  if ((agora - ultimaMudanca2) > debounce && leitura2 != estadoBotao2) {
    estadoBotao2 = leitura2;
    if (estadoBotao2 == LOW) {
      mp3.playFolder(1, 2); // toca 01/002.mp3
      Serial.println(F("Tocando: 002"));
    }
  }
}
