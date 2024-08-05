#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

#define NUMERO_POKEMON 1025
#define NOM_POKEMON_LENGTH 12

void remove_newline(char *str) {
	size_t length = strlen(str);
	if (length > 0 && str[length - 1] == '\n') {
		str[length - 1] = '\0';
	}
}

int main(void) {
	char pokemonList[NUMERO_POKEMON][NOM_POKEMON_LENGTH]; // [nb pokemon][taille nom max]
	int count = 0;

	system("cls");

	FILE *file = fopen("pokedex.txt", "r");
	if (file == NULL) {
		printf("\033[0;91m"); // rouge clair
		perror("Impossible d'ouvrir le pokedex"); // print erreur ouverture
		return 1;
	}

	while (fgets(pokemonList[count], 50, file)) {
		remove_newline(pokemonList[count]);
		count++;
	}

	fclose(file);

	int position;
	char letter;

	printf("\033[0;93m"); // jaune clair
	printf("\nQuelle est la lettre de l'indice (pas d'accent) ? : ");
	scanf("%c", &letter);
	printf("\nA quelle position se situe-t-elle (chiffre > 0) ? : ");
	scanf("%i", &position);

	printf("\n\nPokemons avec %c a la position %i :\n", letter, position);
	printf("\033[0;32m"); // vert
	for (int i = 0; i < count; i++) {
		if (strlen(pokemonList[i]) >= position && pokemonList[i][position - 1] == letter) {
			printf("%s\n", pokemonList[i]);
		}
	}

	Sleep(3600000); // sleep 1 heure

	return 0;
}