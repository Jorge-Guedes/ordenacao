
// Ordenação usando BubbleSort

#include <stdio.h>
#include <string.h>

void bubbleSort(char (*vet)[50], int length) {
    int i, j;
    char aux[50];

    // loop para acessar cada elemento do array
    for(i=0; i<length; i++) {
        // loop para comparar elementos do array
        for(j=0; j<length - 1 - i; j++) {
            // comparar dois elementos adjacentes
            if(strcmp(vet[j], vet[j+1]) > 0) {
                // a troca ocorre se os elementos não estiverem na ordem pretendida
                strcpy(aux, vet[j]);
                strcpy(vet[j], vet[j+1]);
                strcpy(vet[j+1], aux);
            }
        }
    }
}

// Código executavel
int main() {
    int tam=0, i=0;
    printf("\nQuantas pessoas deseja cadastrar? ");
    scanf("%i", &tam);
    char name[tam][50];

    for(i=0; i<tam; i++) {
        printf("\n------------------- %d PESSOA -------------------", i+1);
        printf("\nSeu nome: ");
        setbuf(stdin, 0);
        fgets(name[i], 256, stdin);
    }

    // executa a ordenação por bolha
    bubbleSort(name, tam);

    printf("\n############### ORDENAÇÃO ALFABETICA ###############\n");
    for(i=0; i<tam; i++) {
        printf("%d: %s", i+1, name[i]);
    }
}
