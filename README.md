<div align="center">
    <img src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" alt="Logo Embarcatech" height="100">
</div>

<br>

# Temporizador periódico

## Sumário

- [Descrição](#descrição)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Ferramentas utilizadas](#ferramentas-utilizadas)
- [Objetivos](#objetivos)
- [Instruções de uso](#instruções-de-uso)
- [Vídeo de apresentação](#vídeo-de-apresentação)
- [Aluno e desenvolvedor do projeto](#aluno-e-desenvolvedor-do-projeto)
- [Licensa](#licença)

## Descrição

Este projeto implementa um sistema utilizando a placa de desenvolvimento BitDogLab e o microcontrolador Raspberry Pi Pico W. Ele também foi desenvolvido e testado no simulador de eletrônica Wokwi, integrando 3 LEDs, um vermelho, um amarelo/azul e um verde para explorar o uso de temporizadores a partir da função ***add_repeating_timer_ms()***. O objetivo principal é projetar um semáforo com temporização de 3 segundos para cada alteração de sinal.

## Funcionalidades Implementadas

1. Acionamento de LEDs a partir de um temporizador:

   - Um temporiador ajustado para um atraso de 3 segundos (3.000 ms) altera o estado dos LEDs, acionando a cor vermelha, seguindo para amarela/azul e finalizando com a verde.
   - Para a simulação no Wokwi foi utilizado o LED amarelo para se parecer com um semáforo tradicional.
   - Na placa de desenvolvimento BitDogLab foi utilizado o LED azul no lugar do amarelo, pois o LED da placa é RGB.
   - A mudança de estado dos LEDs foi implementada na função de *callback* do temporizador.

2. Impressão de tempo pela porta serial:

   - No loop principal foi implementado uma mensagem para se repetir a cada 1s no monitor serial, para marcar o tempo.

## Ferramentas utilizadas

- **Simulador de eletrônica wokwi**: Ambiente utilizado para simular o hardware e validar o funcionamento do sistema.
- **Ferramenta educacional BitDogLab (versão 6.3)**: Placa de desenvolvimento utilizada para programar o microcontrolador.
- **Microcontrolador Raspberry Pi Pico W**: Responsável pelo controle dos LEDs.
- **LED RGB**: Dispositivo utilizado para alternar a cor do semáforo.
- **Visual Studio Code (VS Code)**: IDE utilizada para o desenvolvimento do código com integração ao Pico SDK.
- **Pico SDK**: Kit de desenvolvimento de software utilizado para programar o Raspberry Pi Pico W em linguagem C.
- **Monitor serial do VS Code**: Ferramenta utilizada para monitorar o marcador temporal.

## Objetivos

1. Compreender o funcionamento e a aplicação de temporizadores em microcontroladores.
2. Fazer a utilização da função ***add_repeating_timer_ms()***.
3. Desenvolver um projeto funcional que combine hardware e software.

## Instruções de uso

1. **Clonar o Repositório**:

```bash
git clone https://github.com/bigodinhojf/temporizador_periodico.git
```

2. **Compilar e Carregar o Código**:
   No VS Code, configure o ambiente e compile o projeto com os comandos:

```bash	
cmake -G Ninja ..
ninja
```

3. **Interação com o Sistema**:
   - Conecte a placa ao computador.
   - Clique em run usando a extensão do raspberry pi pico.
   - Abra o monitor serial para acompanhar o marcador de temporal.

## Vídeo de apresentação

O vídeo apresentando o projeto pode ser assistido [clicando aqui](https://youtu.be/hTaVnmKLStk).

## Aluno e desenvolvedor do projeto

<a href="https://github.com/bigodinhojf">
        <img src="https://github.com/bigodinhojf.png" width="150px;" alt="João Felipe"/><br>
        <sub>
          <b>João Felipe</b>
        </sub>
</a>

## Licença

Este projeto está licenciado sob a licença MIT.
