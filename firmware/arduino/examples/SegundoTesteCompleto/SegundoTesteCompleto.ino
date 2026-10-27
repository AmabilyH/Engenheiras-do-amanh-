#include <DFRobotDFPlayerMini.h>

#define moduloMP3 Serial1
DFRobotDFPlayerMini mp3;

const int botao1 = 22;
const int botao2 = 23;
const int botao3 = 24;
const int botao4 = 25;
const int botao5 = 26;
const int botao6 = 27;
const int botao7 = 28;
const int botao8 = 29;
const int botao9 = 30;
const int botao10 = 31;
const int botao11 = 32;
const int botao12 = 33;

// estado estável confirmado (depois do debounce)
int estadoBotao1 = HIGH;
int estadoBotao2 = HIGH;
int estadoBotao3 = HIGH;
int estadoBotao4 = HIGH;
int estadoBotao5 = HIGH;
int estadoBotao6 = HIGH;
int estadoBotao7 = HIGH;
int estadoBotao8 = HIGH;
int estadoBotao9 = HIGH;
int estadoBotao10 = HIGH;
int estadoBotao11 = HIGH;
int estadoBotao12 = HIGH;

// última leitura crua (pode estar "chiando")
int ultimaLeitura1 = HIGH;
int ultimaLeitura2 = HIGH;
int ultimaLeitura3 = HIGH;
int ultimaLeitura4 = HIGH;
int ultimaLeitura5 = HIGH;
int ultimaLeitura6 = HIGH;
int ultimaLeitura7 = HIGH;
int ultimaLeitura8 = HIGH;
int ultimaLeitura9 = HIGH;
int ultimaLeitura10 = HIGH;
int ultimaLeitura11 = HIGH;
int ultimaLeitura12 = HIGH;

// instante da última vez que a leitura crua mudou
unsigned long ultimaMudanca1 = 0;
unsigned long ultimaMudanca2 = 0;
unsigned long ultimaMudanca3 = 0;
unsigned long ultimaMudanca4 = 0;
unsigned long ultimaMudanca5 = 0;
unsigned long ultimaMudanca6 = 0;
unsigned long ultimaMudanca7 = 0;
unsigned long ultimaMudanca8 = 0;
unsigned long ultimaMudanca9 = 0;
unsigned long ultimaMudanca10 = 0;
unsigned long ultimaMudanca11 = 0;
unsigned long ultimaMudanca12 = 0;

const unsigned long debounce = 50; // 50ms de estabilização

void setup() {
  Serial.begin(9600);
  moduloMP3.begin(9600);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);
  pinMode(botao5, INPUT_PULLUP);
  pinMode(botao6, INPUT_PULLUP);
  pinMode(botao7, INPUT_PULLUP);
  pinMode(botao8, INPUT_PULLUP);
  pinMode(botao9, INPUT_PULLUP);
  pinMode(botao10, INPUT_PULLUP);
  pinMode(botao11, INPUT_PULLUP);
  pinMode(botao12, INPUT_PULLUP);

  // isACK = false: necessário para módulos clone que não respondem ACK
  // corretamente, o que travava o begin() esperando confirmação que nunca chegava.
  if (!mp3.begin(moduloMP3, /*isACK=*/false, /*doReset=*/true)) {
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
    ultimaMudanca1 = agora;
    ultimaLeitura1 = leitura1;
  }
  if ((agora - ultimaMudanca1) > debounce && leitura1 != estadoBotao1) {
    estadoBotao1 = leitura1;
    if (estadoBotao1 == LOW) {
      mp3.playFolder(1, 1);
      Serial.println("Tocando: oi");
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
      mp3.playFolder(1, 2);
      Serial.println("Tocando: tchau");
    }
  }

  // ---- Botão 3 ----
  int leitura3 = digitalRead(botao3);
  if (leitura3 != ultimaLeitura3) {
    ultimaMudanca3 = agora;
    ultimaLeitura3 = leitura3;
  }
  if ((agora - ultimaMudanca3) > debounce && leitura3 != estadoBotao3) {
    estadoBotao3 = leitura3;
    if (estadoBotao3 == LOW) {
      mp3.playFolder(1, 3);
      Serial.println("Tocando: pista 3");
    }
  }

  // ---- Botão 4 ----
  int leitura4 = digitalRead(botao4);
  if (leitura4 != ultimaLeitura4) {
    ultimaMudanca4 = agora;
    ultimaLeitura4 = leitura4;
  }
  if ((agora - ultimaMudanca4) > debounce && leitura4 != estadoBotao4) {
    estadoBotao4 = leitura4;
    if (estadoBotao4 == LOW) {
      mp3.playFolder(1, 4);
      Serial.println("Tocando: pista 4");
    }
  }

  // ---- Botão 5 ----
  int leitura5 = digitalRead(botao5);
  if (leitura5 != ultimaLeitura5) {
    ultimaMudanca5 = agora;
    ultimaLeitura5 = leitura5;
  }
  if ((agora - ultimaMudanca5) > debounce && leitura5 != estadoBotao5) {
    estadoBotao5 = leitura5;
    if (estadoBotao5 == LOW) {
      mp3.playFolder(1, 5);
      Serial.println("Tocando: pista 5");
    }
  }

  // ---- Botão 6 ----
  int leitura6 = digitalRead(botao6);
  if (leitura6 != ultimaLeitura6) {
    ultimaMudanca6 = agora;
    ultimaLeitura6 = leitura6;
  }
  if ((agora - ultimaMudanca6) > debounce && leitura6 != estadoBotao6) {
    estadoBotao6 = leitura6;
    if (estadoBotao6 == LOW) {
      mp3.playFolder(1, 6);
      Serial.println("Tocando: pista 6");
    }
  }

  // ---- Botão 7 ----
  int leitura7 = digitalRead(botao7);
  if (leitura7 != ultimaLeitura7) {
    ultimaMudanca7 = agora;
    ultimaLeitura7 = leitura7;
  }
  if ((agora - ultimaMudanca7) > debounce && leitura7 != estadoBotao7) {
    estadoBotao7 = leitura7;
    if (estadoBotao7 == LOW) {
      mp3.playFolder(1, 7);
      Serial.println("Tocando: pista 7");
    }
  }

  // ---- Botão 8 ----
  int leitura8 = digitalRead(botao8);
  if (leitura8 != ultimaLeitura8) {
    ultimaMudanca8 = agora;
    ultimaLeitura8 = leitura8;
  }
  if ((agora - ultimaMudanca8) > debounce && leitura8 != estadoBotao8) {
    estadoBotao8 = leitura8;
    if (estadoBotao8 == LOW) {
      mp3.playFolder(1, 8);
      Serial.println("Tocando: pista 8");
    }
  }

  // ---- Botão 9 ----
  int leitura9 = digitalRead(botao9);
  if (leitura9 != ultimaLeitura9) {
    ultimaMudanca9 = agora;
    ultimaLeitura9 = leitura9;
  }
  if ((agora - ultimaMudanca9) > debounce && leitura9 != estadoBotao9) {
    estadoBotao9 = leitura9;
    if (estadoBotao9 == LOW) {
      mp3.playFolder(1, 9);
      Serial.println("Tocando: pista 9");
    }
  }

  // ---- Botão 10 ----
  int leitura10 = digitalRead(botao10);
  if (leitura10 != ultimaLeitura10) {
    ultimaMudanca10 = agora;
    ultimaLeitura10 = leitura10;
  }
  if ((agora - ultimaMudanca10) > debounce && leitura10 != estadoBotao10) {
    estadoBotao10 = leitura10;
    if (estadoBotao10 == LOW) {
      mp3.playFolder(1, 10);
      Serial.println("Tocando: pista 10");
    }
  }

  // ---- Botão 11 ----
  int leitura11 = digitalRead(botao11);
  if (leitura11 != ultimaLeitura11) {
    ultimaMudanca11 = agora;
    ultimaLeitura11 = leitura11;
  }
  if ((agora - ultimaMudanca11) > debounce && leitura11 != estadoBotao11) {
    estadoBotao11 = leitura11;
    if (estadoBotao11 == LOW) {
      mp3.playFolder(1, 11);
      Serial.println("Tocando: pista 11");
    }
  }

  // ---- Botão 12 ----
  int leitura12 = digitalRead(botao12);
  if (leitura12 != ultimaLeitura12) {
    ultimaMudanca12 = agora;
    ultimaLeitura12 = leitura12;
  }
  if ((agora - ultimaMudanca12) > debounce && leitura12 != estadoBotao12) {
    estadoBotao12 = leitura12;
    if (estadoBotao12 == LOW) {
      mp3.playFolder(1, 12);
      Serial.println("Tocando: pista 12");
    }
  }
}
