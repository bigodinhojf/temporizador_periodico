// Inclusão das bibliotecas utilizadas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // Biblioteca de temporizadores

// Definição dos pinos GPIO
const int led_pin_green = 11; // LED Verde GPIO 11
const int led_pin_yellow = 12; // LED Amarelo/azul GPIO 12
const int led_pin_red = 13; // LED vermelho GPIO 13

// Definição de variáveis globais
int tempo_decorrido = 0; // Tempo decorrido do início do programa em (s)
int marcador = 3; // Auxilia na decisão de qual LED deve acender

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Tomada de decisão para verificar qual LED deve acender
    if(marcador % 3 == 0){
        // LED Vermelho acende
        gpio_put(led_pin_red, 1);
        gpio_put(led_pin_yellow, 0);
        gpio_put(led_pin_green, 0);
    }else if(marcador % 3 == 1){
        // LED Amarelo/Azul acende
        gpio_put(led_pin_red, 0);
        gpio_put(led_pin_yellow, 1);
        gpio_put(led_pin_green, 0);
    }else if(marcador % 3 == 2){
        // LED Verde acende
        gpio_put(led_pin_red, 0);
        gpio_put(led_pin_yellow, 0);
        gpio_put(led_pin_green, 1);
    }
    marcador++;
    // Retorna true para manter o temporizador repetindo.
    return true;
}

// Função principal
int main()
{
    // Inicialização da comunicação serial
    stdio_init_all();

    // Inicialização dos pinos GPIO

    // Inicializa o LED Verde GPIO 11 e o define como saída
    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);

    // Inicializa o LED Amarelo/Azul GPIO 12 e o define como saída
    gpio_init(led_pin_yellow);
    gpio_set_dir(led_pin_yellow, GPIO_OUT);

    // Inicializa o LED Vermelho GPIO 13 e o define como saída
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    // Declaração de uma estrutura de temporizador de repetição.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    printf(" -- PROGRAMA INICIADO - TEMPO: %ds --\n", tempo_decorrido);

    while (true) {
        // Marcação de tempo a cada 1s
        sleep_ms(1000);
        tempo_decorrido++;
        printf("Marcador temporal de 1s -> total: %ds\n", tempo_decorrido);
    }
}
