# Contexto do projeto

O FalaPlaca é um protótipo de acionamento de áudios por botões. O firmware Arduino lê botões com `INPUT_PULLUP`, aplica debounce e comanda um módulo DFPlayer Mini pela `Serial1`.

## Estado atual

- O sketch principal configura dois botões nos pinos 2 e 3.
- Cada botão toca uma faixa numerada na pasta 01 do cartão do DFPlayer.
- Os sketches em `firmware/arduino/examples/` registram protótipos: o primeiro usa dois botões e o segundo usa doze botões nos pinos 22 a 33.
- A camada de software (aplicação executada fora do microcontrolador) ainda não possui implementação.

## Decisões e pontos a confirmar

- Manter firmware e aplicação de software em camadas e diretórios independentes.
- Confirmar o modelo da placa antes de definir a configuração de compilação: o firmware atual utiliza `Serial1`; o exemplo de doze botões também pressupõe pinos 22 a 33.
- Confirmar a ligação física, a alimentação e a organização dos arquivos de áudio no cartão antes de validar o conjunto em hardware.

Os sketches existentes são a fonte do comportamento implementado. Este documento registra apenas o contexto conhecido e não substitui a validação do circuito.
