/* Alias para tipos de dados e função para embaralhar cartas */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carta {
  char *face;
  char *naipe;
};

typedef struct carta Carta;  // Alias/apelido

void completeDeck(Carta *, char *[], char *[]);
void shuffle(Carta *);  // embaralha
void distribute(Carta *);  // distribui

int main() {
  Carta deck[52];
  char *face[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete",
                   "Dama", "Rei"};
  char *naipe[] = {"Copas", "Ouros", "Paus", "Espadas"};

  srand(time(NULL));  // Inicializa "semente" de numeros aletorios com base no horário

  completeDeck(deck, face, naipe);
  shuffle(deck);
  distribute(deck);

  return 0;
}

void completeDeck(Carta *deck, char *face[], char *naipe[]) {
  for (int i = 0; i < 52; i++) {
    deck[i].face = face[i % 13];  // Garante que 13 faces se repita a cada 13 cartas
    deck[i].naipe = naipe[i / 13]; // Muda de naipe a cada 13 cartas
  }
}

void shuffle(Carta *deck) {
  Carta temp;
  int j;

  for (int i = 0; i < 52; i++) {
    j = rand() % 52;
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void distribute(Carta *deck) {
  for (int i = 0; i < 52; i++) {
    printf("%6s de %-7s%c", deck[i].face, deck[i].naipe, (i + 1) % 2 ? '.' : '\n');
  }
}