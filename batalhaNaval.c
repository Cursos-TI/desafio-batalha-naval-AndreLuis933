#include <stdio.h>
#include <stdlib.h>

// Pode ser alterado qualquer uma dessas constantes (para números inteiros e
// positivos) para alterar o tamanho do tabuleiro e das habilidades especiais

#define TAMANHO_TABULEIRO 10

// Se alterar a quantidade de navios, adicione a nova posição desejada nesse
// formato {posicao x desejada, posicao y desejada} na variável 'posicoesNavios'
#define QUANTIDADE_NAVIOS 4

// Linhas e colunas para a matriz de habilidades especiais
#define LINHAS 3
#define COLUNAS 5

int main() {

  // Definição do tabuleiro iniciando todas as posições com 0
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

  // Definição das posições dos navios
  int posicoesNavios[QUANTIDADE_NAVIOS][2] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};

  printf("\nPosicionamento dos Navios:\n");

  // Colocar os navios no tabuleiro
  for (int i = 0; i < QUANTIDADE_NAVIOS; i++) {
    printf("Navio %d: (%d, %d)\n", i + 1, posicoesNavios[i][0],
           posicoesNavios[i][1]);
    tabuleiro[posicoesNavios[i][0]][posicoesNavios[i][1]] = 3;
  }

  printf("\nTabuleiro:\n");

  // Mostrar o tabuleiro
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  // Definição da matriz de habilidades
  int habilidades[LINHAS][COLUNAS] = {0};

  // Encontra o meio dos dois eixos
  int meio_x = COLUNAS / 2;
  int meio_y = LINHAS / 2;

  // Definição dos formatos
  char *formatos[] = {"Cone", "Octaedro", "Cruz"};

  printf("\nHabilidades Especiais:\n");

  // Loop para criar as habilidades, o loop externo percorre os formatos e os
  // internos as linhas e colunas para cada formato
  for (int formato = 0; formato < 3; formato++) {
    printf("\n%s:\n", formatos[formato]);
    for (int i = 0; i < LINHAS; i++) {
      for (int j = 0; j < COLUNAS; j++) {
        switch (formato) {
        case 0: // Cone
          /* Esta comparação cria um padrão de cone:
           * - 'meio_x - i <= j' define o limite esquerdo do cone, que se move
           * para a esquerda a cada linha
           * - 'j <= meio_x + i' define o limite direito do cone, que se move
           * para a direita a cada linha. Isso resulta em um triângulo que se
           * alarga de cima para baixo, formando o cone
           */
          habilidades[i][j] = (meio_x - i <= j && j <= meio_x + i) ? 1 : 0;
          break;
        case 1: // Octaedro
          /* Esta comparação cria um padrão de octaedro:
           * - 'largura = meio_y - abs(i - meio_y)' calcula a largura de cada
           * linha do octaedro. Isso cria um padrão que aumenta do topo até o
           * meio e diminui do meio até a base
           * - 'meio_x - largura <= j && j <= meio_x + largura' preenche cada
           * linha com base na largura calculada. Centralizando o preenchimento
           * em torno do meio_x
           */
          int largura = meio_y - abs(i - meio_y);
          habilidades[i][j] =
              (meio_x - largura <= j && j <= meio_x + largura) ? 1 : 0;
          break;
        case 2: // Cruz
          /* Esta comparação cria um padrão de cruz:
           * - 'j == meio_x' preenche toda a coluna central
           * - 'i == meio_y' preenche toda a linha central
           * Isso resulta em uma cruz centrada na matriz
           */
          habilidades[i][j] = (j == meio_x || i == meio_y) ? 1 : 0;
          break;
        }
        printf("%d ", habilidades[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}