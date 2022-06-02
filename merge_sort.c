
// Ordenação usando MergeSort

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_TAM 100

void merge(float *V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if (temp != NULL) {
        for (i=0; i<tamanho; i++) {
            if (!fim1 && !fim2) {
                // Combinar ordenando
                if (V[p1] < V[p2]) {
                    temp[i] = V[p1++];
                } else {
                    temp[i] = V[p2++];
                }
                // Vetor acabou?
                if(p1 > meio) fim1 = 1;
                if(p2>fim) fim2=1;
            } else {
                // Copiar o que sobrar
                if (!fim1) {
                    temp[i] = V[p1++];
                } else {
                    temp[i] = V[p2++];
                }
            }
        }
        // Copiar do auxiliar para o original
        for (j=0, k=inicio; j<tamanho; j++, k++) {
            V[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(float *V, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = floor((inicio+fim) / 2);
        // Chama a função para as 2 metades
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        // Combina as 2 metades de forma ordenada
        merge(V, inicio, meio, fim);
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

    // executa a ordenação por merge
    mergeSort(valor, 0, i);

    for (j=0; j<=i; j++) {
        if (j == 0) {
            continue;
        }
        printf("%.1f -> ", valor[j]);
    }
    printf("\n");

    return 0;
}
