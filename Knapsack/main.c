#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"
int main(){
    FILE* file = fopen ("mochila01.txt", "r"); //abre o arquivo passado como argumento
    if (file == NULL)
    {
      printf ("Falha ao tentar ler arquivo.");
      return 1;
    }
    int n, m; //número de itens e capacidade da mochila

    int i = 0;
    fscanf (file, "%d", &i);    //Lê o primeiro valor como número de itens
    n = i;
    fscanf(file, "%d", &i); // Lê segundo valor como capacidade máxima
    m = i;

    int v[n]; //array de valores
    int p[n]; //array de pesos
    int j = 0;
    for (j = 0; j<n; j++){
        fscanf(file, "%d", &i);
        p[j] = i;
        fscanf(file, "%d", &i);
        v[j] = i;
    }

    knapSack(m, p, v, n);

    return 0;
}
