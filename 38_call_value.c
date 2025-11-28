/* Chamada/passagem por valor/cópia */
#include <stdio.h>

int cuboPorValor(int);

int main() {
	int n = 5;
	int c;

	printf("O valor original do numero eh %d\n", n);
	c = cuboPorValor(n);

	printf("O novo valor do numero eh %d\n", n);
	printf("Quem eh C? %d", c);

	return 0;
}

int cuboPorValor(int n) {
	return n * n * n;
}