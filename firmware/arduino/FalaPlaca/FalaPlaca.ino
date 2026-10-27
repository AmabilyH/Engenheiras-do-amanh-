#include <DFRobotDFPlayerMini.h>

#define moduloMP3 Serial1
DFRobotDFPlayerMini mp3;

const int botao1 = 2;
const int botao2 = 3;

// estado estável confirmado (depois do debounce)
int estadoBotao1 = HIGH;
int estadoBotao2 = HIGH;

// última leitura crua (pode estar "chiando")
int ultimaLeitura1 = HIGH;
int ultimaLeitura2 = HIGH;

// instante da última vez que a leitura crua mudou
unsigned long ultimaMudanca1 = 0;
unsigned long ultimaMudanca2 = 0;

const unsigned long debounce = 50; // 50ms de estabilização

void setup() {
  Serial.begin(9600);
  moduloMP3.begin(9600);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  if (!mp3.begin(moduloMP3)) {
    Serial.println("Erro ao iniciar o modulo MP3.");
    while (true);
  }

  mp3.volume(20);
  Serial.println("Modulo MP3 pronto!");
}

void loop() {
  unsigned long agora = millis();

  // ---- Botão 1 ----
  int leitura1 = digitalRead(botao1);
  if (leitura1 != ultimaLeitura1) {
    ultimaMudanca1 = agora;      // leitura mudou: reinicia o timer de estabilização
    ultimaLeitura1 = leitura1;
  }
  // só aceita a leitura depois que ela ficou estável por 'debounce' ms
  if ((agora - ultimaMudanca1) > debounce && leitura1 != estadoBotao1) {
    estadoBotao1 = leitura1;     // estado mudou DE VERDADE
    mp3.playFolder(1, 1);        // dispara nos dois sentidos (travar E destravar)
    Serial.println("Tocando: oi");
  }

  // ---- Botão 2 ----
  int leitura2 = digitalRead(botao2);
  if (leitura2 != ultimaLeitura2) {
    ultimaMudanca2 = agora;
    ultimaLeitura2 = leitura2;
  }
  if ((agora - ultimaMudanca2) > debounce && leitura2 != estadoBotao2) {
    estadoBotao2 = leitura2;
    mp3.playFolder(1, 2);
    Serial.println("Tocando: tchau");
  }
}
