#include <stdio.h>
#include <stdlib.h>

int*** aloca_matriz(int m, int n, int z)
{
  int*** matriz = (int***)malloc(m*sizeof(int**));
  for(int i = 0; i < m; i++){
    matriz[i]=(int**)malloc(n*sizeof(int*));
    for(int j = 0; j < n; j++){
      matriz[i][j]=(int*)malloc(z*sizeof(int));
    }
  }
  return matriz;
}

void preenche_matriz(int m, int n, int z, int*** mat)
{
  if(mat != NULL){
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        for(int k = 0; k < z; k++){
          printf("digite mat[%d][%d][%d]:", i, j, k);
          scanf("%d", &mat[i][j][k]);
        }
  }
  return;
}

void imprime_matriz(int m, int n, int z, int*** mat)
{
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < z; k++)
        printf("valor [%d][%d][%d] = %d\n", i, j, k, mat[i][j][k]);
  return;
}

void desaloca_matriz (int m, int n, int*** mat)
{
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      free(mat[i][j]);
    free(mat[i]);
  }
  free(mat);
  return;
}

int main(void){
  int*** matriz;
  int m, n, z;

  printf("Digite o numero de colunas:");
  scanf("%d", &m);
  printf("Digite o numero de linhas:");
  scanf("%d", &n);
  printf("Digite o numero de profundidade:");
  scanf("%d", &z);
  
  matriz = aloca_matriz(m, n, z);
  preenche_matriz(m, n, z, matriz);
  imprime_matriz(m, n, z, matriz);
  desaloca_matriz(m, n, matriz);

  exit(1);
}