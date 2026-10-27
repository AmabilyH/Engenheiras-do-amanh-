# FalaPlaca

Projeto organizado em camadas para separar o contexto, o firmware embarcado e o software executado fora do Arduino.

## Estrutura

```text
docs/
  contexto/                 Contexto, requisitos e decisões do projeto
firmware/
  arduino/
    FalaPlaca/
      FalaPlaca.ino         Sketch principal
    examples/
      PrimeiroTesteFuncional/
      SegundoTesteCompleto/
software/                   Aplicação de software (ainda não implementada)
```

## Firmware Arduino

Abra `firmware/arduino/FalaPlaca/FalaPlaca.ino` no Arduino IDE. Instale a biblioteca `DFRobotDFPlayerMini` e selecione uma placa que ofereça `Serial1`. Os exemplos em `firmware/arduino/examples/` são sketches independentes, com configurações de pinos diferentes do sketch principal.

Consulte [o contexto do projeto](docs/contexto/README.md) para detalhes conhecidos e pontos de hardware a confirmar. A camada de software tem seu próprio espaço e orientações em [software/README.md](software/README.md).
