//Trabalho de Programação II - Vitor Ferraz M. Brunoro

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct rotulo
{
	float distanciap;
	float classes;
};

//Função para leitura dos paths
int lerPath (FILE *arquivo, char **path)
{
	int tam = 0;
	*path = (char*) malloc (sizeof (char));
	fscanf(arquivo, "%c", &(*path[0]));
	for (tam = 1; (*path)[tam - 1] != '\n'; tam++)
	{
		*path = realloc (*path, (tam + 1) * sizeof (char));
		fscanf (arquivo, "%c", &(*path)[tam]);
	};
	(*path)[tam - 1] = '\0';
	return tam;
} 

//Alocar matriz de modo dinâmico
float **alocMat(int *lin, int *col)
{
	float **mat;
	int i;
	
	mat = (float **) malloc (*lin * sizeof(float *));
	for (i = 0; i < *lin; i++)
	{
		mat[i] = (float *) malloc (*col * sizeof(float));
	}
	return mat;
}

//Liberar (free) a matriz alocada de modo dinâmico
float liberarMat(float **mat, int *linhas)
{
	int i;
	for (i = 0; i < *linhas; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

//Cálculo da distância Euclidiana
void distanciaEuclidiana (int *m, int *n, int *tam, float **p, float **q, float ***s)
{
	float distancia = 0, aux = 0;
	for (int i = 0; i < *m; i++)
	{
		for (int j = 0; j < *tam; j++)
		{
			for (int k = 0; k < (*n) - 1; k++)
			{
				aux = p[i][k] - q[j][k];
				distancia = distancia + pow (aux, 2);
			}
			s[i][j][0] = sqrt(distancia);
			s[i][j][1] = q[j][(*n) - 1];
		}
	}
}
//Cálculo da distância de Minkowsky
void distanciaMinkowsky (int *m, int *n, int *tam, float raio, float **p, float **q, float ***s)
{
	float distancia = 0, aux = 0;
	for (int i = 0; i < *m; i++)
	{
		for (int j = 0; j < *tam; j++)
		{
			for (int k = 0; k < (*n) - 1; k++)
			{
				if (p[i][k] < q[j][k]) 
                {
                    aux = q[i][k] - p[j][k];
                }
                else
                {
                    aux = p[j][k] - q[i][k];
                }
            distancia = distancia + pow (aux, raio);
            }
        s[i][j][0] = pow(distancia, (1/raio));
		s[i][j][1] = q[j][(*n) - 1];    
	    }
}
//Cálculo da distância de Chebyshev
void distanciaChebyshev (int *m, int *n, int *tam, float **p, float **q, float ***s)
{
	float distancia = 0, aux = 0;
	for (int i = 0; i < *m; i++)
	{
		for (int j = 0; j < *tam; j++)
		{
			for (int k = 0; k < (*n) - 1; k++)
			{
                if (p[i][k] < q[j][k]) 
                {
                    aux = (q[i][k] - p[j][k]);
                }
                else
                {
                    aux = p[j][k] - q[i][k];
                }
                if (aux > distancia)
                {
                    distancia = aux;
                }
        	}
		s[i][j][0] = distancia;
		s[i][j][1] = q[j][(*n) - 1];
		}
	}
}

float matrizconfusao (//matriz confusao)

/* float acuracia (//ver tipo matriz confusao, numrotulos)
{
    int certos = 0, total = 0;
    float acuracia
    for (int i = 0; i < numrotulos; i++)
    {
       certos = certos + //matrizconfusao
    }
    acuracia = (certos / total) * 100;
{

*/


int main()
{
	FILE *config;

//Abrir config.txt e verificar se há erro na abertura.
	config = fopen ("config.txt", "r");
	if (config == NULL)
	{
		printf("Erro. Não foi possível abrir o arquivo");
		exit(1);
	}	
//Ler .csv de teste e de treino
	path = lerPath (arquivo, &pathTreino);
	path = lerPath (arquivo, &pathTeste);

}