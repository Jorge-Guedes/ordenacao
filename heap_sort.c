
// Ordenação usando Heap Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 6

void criaHeap(int *vet, int i, int f) {
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f) {
        if (j < f) {
            if (vet[j] < vet[j + 1]) {
                j += 1;
            }
        }
        // Filho maior que o Pai?
        if (aux < vet[j]) {
            // Filho se torna o pai!
            vet[i] = vet[j];
            // Repetir o processo
            i = j;
            j = 2 * i + 1;
        } else {
            j = f + 1;
        }
    }
    // Antigo pai ocupa lugar do ultimo filho analisado
    vet[i] = aux;
}

void heapSort(int *vet, int N) {
    int i, aux;
    // Criar heap a partir dos dados
    for (i = (N - 1)/2; i >= 0; i--) {
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--) {
        // Pegar o maior elemento da heap
        // e colocar na sua posição correspondente
        // no array
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        // Reconstruir heap
        criaHeap(vet, 0, i-1);
    }
}

// Código executavel
int main()
{
    int array[TAMANHO];
    int i, p;
    int count;
    int x=0;

    printf("\n=========== MEGA SENA ===========\n");

    // faz com que os numeros gerados nao se repitam
    srand(time(NULL));

    for(count=0;count<TAMANHO;count++){
        array[count]=rand()%60+1;
    }

    // verifica o numero e substitui caso ele seja repetido
    while(i<TAMANHO){
        int r=rand()%60+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(i==x){
            array[i++]=r;
        }
    }

    // executa a ordenação heap
    heapSort(array, TAMANHO);

    printf("\nGerando numeros da Mega Sena:\n");
    printf("[ ");
    for(p=0;p<TAMANHO;p++){
        printf("\033[42m \033[37m %d \033[0m | ",array[p]); // cor fundo verde
    }
    printf("] \n");

    return 0;
}
