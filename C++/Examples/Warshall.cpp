// Algoritmo de Warshall para obtener la matriz de caminos a partir de la
// matriz de adyacencia de un Grafo

#include <iostream.h>
#include <conio.h>

#define N 4


int A[N][N]={ 1, 0, 1, 0,
	      0, 0, 1, 1,
	      0, 0, 1, 1,
	      0, 0, 1, 1 };

void main(void)
{
  int i,j,k;
  clrscr();

  for(k=0;k<N;k++)
    for(i=0;i<N;i++)
      for(j=0;j<N;j++)
	A[i][j]=A[i][j] | (A[i][k] & A[k][j]) ;

  cout << "\n\nMATRIZ DE CAMINOS \n\n";
  for(i=0;i<N;i++)
  {
    cout << "\n";
    for(j=0;j<N;j++)
      cout << "\t"<<A[i][j];
  }

  cout << "\n\n\n<<< Oprima cualquier tecla para continuar >>>";
  getch();
  return;
}
