
// Ordenação usando Insertion Sort

#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 10
#define MAX_STRING_LEN 100

// Classifica uma matriz de strings onde o comprimento de cada
// string deve ser menor que MAX_STRING_LEN
void InsertionSort(char list[MAX_STRINGS][MAX_STRING_LEN]) {
    for (int i = 1; i < MAX_STRINGS; i++) {
        // adiciona j como auxiliar
        int j = i;

        // executa um loop enquanto ainda
        // nao estiver ordenada corretamente
        while (j > 0 && strcmp(list[j - 1], list[j]) > 0) {
            char tmp[MAX_STRING_LEN];
            strncpy(tmp, list[j - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0'; // o '\0' faz com que termine a leitura de string

            strncpy(list[j - 1], list[j], sizeof(list[j - 1]) - 1);
            list[j - 1][sizeof(list[j - 1]) - 1] = '\0';

            strncpy(list[j], tmp, sizeof(list[j]));
            list[j][sizeof(list[j]) - 1] = '\0';

            --j;
        }
    }
}

// Código executavel
int main() {
    int i;

    char strings[][MAX_STRING_LEN] = {
	    "Friends",
		"Breaking Bad",
		"Game of Thrones",
		"Orange Is the New Black",
		"Grey’s Anatomy",
        "Sherlock",
        "Vikings",
        "The Witcher",
        "Stranger Things",
        "Dark"
	};

    printf("\nSERIES\n");
    printf("---------------------------------\n");

    for (i = 0; i < MAX_STRINGS; i++) {
        printf("%d - %s\n", i+1, strings[i]);
    }

    // executa a ordenação por insercao
    InsertionSort(strings);

    printf("\n\nSERIES ORDENADAS EM ORDEM ALFABETICA\n");
    printf("---------------------------------\n");

    for (i = 0; i < MAX_STRINGS; i++) {
        printf("%d - %s\n", i+1, strings[i]);
    }

}

