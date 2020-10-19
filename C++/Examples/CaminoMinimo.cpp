// Algoritmo del Camino Minimo para obtener la matriz a partir de la
// matriz de pesos de un Grafo


#include <iostream.h>
#include <conio.h>

#define N 4


// NOTA: En la matriz se sustituye el valor 32767 por infinito


int Q[N][N]={ 2    , 32767, 7, 32767,
	      32767, 32767, 4, 3,
	      32767, 32767, 1, 6,
	      32767, 32767, 5, 32767 };

int MINIMO(int a, int b)
{
  if(a<b || b<0) return(a); else return(b);
}

void main(void)
{
  int i,j,k;
  clrscr();

  for(k=0;k<2;k++)
    for(i=0;i<N;i++)
      for(j=0;j<N;j++)
	Q[i][j]=MINIMO(Q[i][j],Q[i][k] + Q[k][j]) ;

  cout << "\n\nMATRIZ DE CAMINO MINIMO\n\n";
  for(i=0;i<N;i++)
  {
    cout << "\n";
    for(j=0;j<N;j++)
      if(Q[i][j]!=32767) cout << "\t"<<Q[i][j]; else cout << "\tì";
  }

  cout << "\n\n\n<<< Oprima cualquier tecla para continuar >>>";
  getch();
  return;
}
