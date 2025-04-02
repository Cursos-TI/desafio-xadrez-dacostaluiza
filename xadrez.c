#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código simula a movimentação de peças de xadrez utilizando estruturas de repetição e funções recursivas.
// O objetivo é testar os limites de movimentação dentro do jogo, atendendo aos níveis Novato, Aventureiro e Mestre.

// Função recursiva para movimentar a Torre (Nível Mestre)
void moverTorre(int casas, int atual) {
    if (atual >= casas) { // Condição de parada da recursividade
        return;
    }
    printf("Direita\n"); // Torre move-se para a direita
    moverTorre(casas, atual + 1); // Chamada recursiva
}

// Função recursiva para movimentar o Bispo (Nível Mestre)
void moverBispo(int casas, int atual) {
    if (atual >= casas) { // Condição de parada da recursividade
        return;
    }
    printf("Cima, Direita\n"); // Bispo move-se na diagonal (cima e direita)
    moverBispo(casas, atual + 1); // Chamada recursiva
}

// Função recursiva para movimentar a Rainha (Nível Mestre)
void moverRainha(int casas, int atual) {
    if (atual >= casas) { // Condição de parada da recursividade
        return;
    }
    printf("Esquerda\n"); // Rainha move-se para a esquerda
    moverRainha(casas, atual + 1); // Chamada recursiva
}

int main(void) {
    // Mensagem inicial do desafio
    printf("Desafio Jogo de Xadrez\n\n");

    // Constantes para o número de casas a serem movidas (Nível Novato)
    const int CASAS_TORRE = 5;   // Torre: 5 casas para a direita
    const int CASAS_BISPO = 5;   // Bispo: 5 casas na diagonal cima e direita
    const int CASAS_RAINHA = 8;  // Rainha: 8 casas para a esquerda

    // Nível Novato - Movimentação das Peças (versão inicial comentada)
    /*
    printf("Movimento da Torre (for):\n");
    for (int i = 0; i < CASAS_TORRE; i++) {
        printf("Direita\n");
    }
    printf("\n");

    printf("Movimento do Bispo (while):\n");
    int j = 0;
    while (j < CASAS_BISPO) {
        printf("Cima, Direita\n");
        j++;
    }
    printf("\n");

    printf("Movimento da Rainha (do-while):\n");
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while (k < CASAS_RAINHA);
    printf("\n");
    */

    // Nível Mestre - Movimentação com Recursividade
    printf("Movimento da Torre:\n");
    moverTorre(CASAS_TORRE, 0);
    printf("\n");

    // Nível Mestre - Bispo com Loops Aninhados e Recursividade
    printf("Movimento do Bispo:\n");
    for (int i = 0; i < CASAS_BISPO; i++) { // Loop externo para o movimento vertical
        for (int j = 0; j < 1; j++) {       // Loop interno para uma única chamada
            moverBispo(1, 0);               // Recursividade para uma casa
        }
    }
    printf("\n");

    printf("Movimento da Rainha:\n");
    moverRainha(CASAS_RAINHA, 0);
    printf("\n");

    // Nível Aventureiro e Mestre - Movimentação do Cavalo
    printf("Movimento do Cavalo:\n");

    // Nível Aventureiro: Cavalo em "L" (2 baixo, 1 esquerda)
    int baixo = 2;    // Duas casas para baixo
    int esquerda = 1; // Uma casa para a esquerda
    for (int k = 0; k < baixo + esquerda; k++) {
        if (k < baixo) {
            printf("Baixo\n");
        } else {
            printf("Esquerda\n");
            break; // Para após completar o "L"
        }
    }
    printf("\n");

    // Nível Mestre: Cavalo em "L" (2 cima, 1 direita) com loops complexos
    int cima = 2;     // Duas casas para cima
    int direita = 1;  // Uma casa para a direita
    int m = 0;
    while (m < cima + direita) {
        if (m < cima) {
            printf("Cima\n");
        } else {
            printf("Direita\n");
            break; // Para após completar o "L"
        }
        m++;
        if (m == 1) continue; // Exemplo de uso de continue (opcional)
    }

    return 0;
}
