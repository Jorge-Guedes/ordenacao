
// Ordenação usando SelectionSort

#include <stdio.h>
#define MAX_TAM 100

void selectionSort(float *V, int N) { // *V eh o vetor e N eh tamanho do vetor
    int i, j, menor, troca;
    // Procura o menor elemento em relação a "i"
    for (i = 0; i < N-1; i++) {
        menor = i;
        for (j = i+1; j < N; j++) {
            if (V[j] > V[menor]) {
                menor = j;
            }
        }
        // Troca os valores da posição atual com a "menor"
        if (i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

// Código executavel
int main() {

    float valor[MAX_TAM];
    int i, j;

    while (1) { // 1 = true
        printf("Digite um valor [0 para sair]: ");
        scanf("%f", &valor[i]);
        if (valor[i] == 0) {
            break;
        }
        ++i;
    }

    printf("\n\n============ VALORES ============\n");

    for (j=0; j<i; j++) {
        printf("%.1f -> ", valor[j]);
    }

    printf("\n\n============ VALORES EM ORDEM DECRESCENTE ============\n");

    // executa a ordenação por selecao
    selectionSort(valor, i);

    for (j=0; j<i; j++) {
        printf("%.1f -> ", valor[j]);
    }
    printf("\n");

    return 0;
}

