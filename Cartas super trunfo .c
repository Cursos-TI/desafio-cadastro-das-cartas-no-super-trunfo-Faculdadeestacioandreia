#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[20];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

int main() {
    srand(time(NULL));

    // Criação de algumas cartas
    Carta baralho[4] = {
        {"Dragão", 90, 60, 70},
        {"Cavaleiro", 70, 80, 60},
        {"Mago", 50, 40, 95},
        {"Orc", 80, 50, 40}
    };

    printf("=== SUPER TRUNFO SIMPLES ===\n");

    // Sorteio de cartas para cada jogador
    int i1 = rand() % 4;
    int i2 = rand() % 4;
    while (i2 == i1) i2 = rand() % 4;

    Carta jogador1 = baralho[i1];
    Carta jogador2 = baralho[i2];

    // Mostra carta do jogador 1
    printf("\nSua carta:\n");
    printf("Nome: %s\n", jogador1.nome);
    printf("1 - Força: %d\n", jogador1.forca);
    printf("2 - Velocidade: %d\n", jogador1.velocidade);
    printf("3 - Inteligência: %d\n", jogador1.inteligencia);

    // Jogador 1 escolhe atributo
    int escolha;
    printf("\nEscolha o atributo para competir (1-Força, 2-Velocidade, 3-Inteligência): ");
    scanf("%d", &escolha);

    // Mostra carta do jogador 2
    printf("\nCarta do adversário:\n");
    printf("Nome: %s\n", jogador2.nome);
    printf("Força: %d | Velocidade: %d | Inteligência: %d\n",
           jogador2.forca, jogador2.velocidade, jogador2.inteligencia);

    int valor1, valor2;
    switch (escolha) {
        case 1: valor1 = jogador1.forca; valor2 = jogador2.forca; break;
        case 2: valor1 = jogador1.velocidade; valor2 = jogador2.velocidade; break;
        case 3: valor1 = jogador1.inteligencia; valor2 = jogador2.inteligencia; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // Resultado
    printf("\nResultado:\n");
    if (valor1 > valor2)
        printf("Você venceu!\n");
    else if (valor2 > valor1)
        printf("O adversário venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}
