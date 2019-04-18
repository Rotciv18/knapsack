#ifndef KNAPSACK_H_INCLUDED
#define KNAPSACK_H_INCLUDED

//só retorna o maior valor de dois inteiros.
int max(int a, int b) { return (a > b)? a : b; }

void knapSack(int m, int p[], int v[], int n)
{
   int i, w;
   //Array Deve ser alocado dinamicamente por ser grande demais para algumas instâncias
   int **K;
   K = (int**)malloc(sizeof(int*)*m);
    for (i = 0; i <= n; i++)
        K[i] = (int*)malloc(sizeof(int)*m);

   // Constrói tabela K
   for (i = 0; i <= n; i++)
   {
       printf("\nLinha atual: %d", i);
       for (w = 0; w <= m; w++)
       {

           if (i==0 || w==0)
               K[i][w] = 0;
           else if (p[i-1] <= w)
                 K[i][w] = max(v[i-1] + K[i-1][w-p[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   
   printf ("\nSolucao: %d", K[n][m]);
   
    int solucao[n]; //array contendo itens que estão incluídos na solução
    i = 0;
   
   //extrai quais itens entram na solução
   for (; n>0 ; n--){
    if (K[n][m] <= 0)
        break;
    if (K[n][m] > K[n-1][m]){
        solucao[i] = n;
        ++i;
        m = m - p[n-1];

    }
   }
   solucao[i] = -1;
   
   printf ("\nItens: ");
   printf("%d", solucao[0]);
   //printa os itens que estão na solução
   for (i = 1; (solucao[i] != -1); i++){
        printf(", ");
        printf("%d", solucao[i]);
   }
   printf(".");
}


#endif // KNAPSACK_H_INCLUDED
