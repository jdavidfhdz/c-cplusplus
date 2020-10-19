// Programa Recursivo de Ordenamiento de un Vector con QuickSort y
// Busqueda Binaria de Datos


#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

#define GENERAR
#define MAX 255 // Semilla del generador

void QSORT(int INI, int FIN); // Algoritmo Quick Sort para ordenar un vector
int BUSCAR(int primero, int ultimo, int clave); // Busqueda Binaria
void MOSTRAR_VECTOR(int top); // Rutina para imprimir el vector

#define N 100 // Cantidad de numeros a generar
int VECTOR[N]; // Vector

void main(void)
{
  int i,clave,posicion;

  clrscr();
  randomize;
  for(i=0;i<=N;i++)
    VECTOR[i]=random(MAX);

  clrscr();
  cout << "Vector generado en forma aleatoria ...\n\n";
  MOSTRAR_VECTOR(N);
  cout << "\n\nOprima cualquier tecla para continuar...";
  getch();

  QSORT(0,N-1); // Algoritmo QuickSort para ordenar el vector

  do
  {
    clrscr();
    cout << "\nVector ordenado en forma ascendente ...\n\n";
    MOSTRAR_VECTOR(N);

    cout << "\n\n\nAnote un numero que desea buscar ---> ";
    cin >> clave;

    posicion=BUSCAR(0, N-1, clave); // Algoritmo de la Busqueda Binaria

    if(posicion!=-1)
      cout << "\n\nEl numero "<<clave<<" se encuentra en la celda "<<posicion;
    else
      cout << "\n\nEl numero "<<clave<<" NO se encuentra en el vector";
    cout << "\n\n¨Desea buscar otro numero? [S/N] ---> ";
  }while(toupper(getche())!='N');
  cout << "\n\nOprima cualquier tecla para continuar...";
  getch();

  return;
}

void QSORT(int INI, int FIN)
{
  int izq=INI,der=FIN,pos=INI,aux,flag=1;

  while(flag)
  {
    flag=0;

    while(VECTOR[pos]<=VECTOR[der] && pos!=der)
      der--;

    if(pos!=der)
    {
      aux=VECTOR[pos]; VECTOR[pos]=VECTOR[der]; VECTOR[der]=aux;
      pos=der;
      izq++;

      while(VECTOR[pos]>=VECTOR[izq] && pos!=izq)
	izq++;

      if(pos!=izq)
      {
	aux=VECTOR[pos];  VECTOR[pos]=VECTOR[izq];  VECTOR[izq]=aux;
	pos=izq;
	der--;
	flag=1;
      }
    }
  }

  if(pos-1>INI)
    QSORT(INI,pos-1);
  if(FIN>pos+1)
    QSORT(pos+1,FIN);
  return;
}

void MOSTRAR_VECTOR(int top)
{
  for(int i=0;i<top;i++)
  {
    textcolor(CYAN);
    cprintf("[%2d]->",i);
    textcolor(YELLOW);
    cprintf("%3d ",VECTOR[i]);
  }
  textattr(7);
  return;
}

int BUSCAR(int primero, int ultimo, int clave)
{
int medio,pos=0;
   if(primero>ultimo)
     return(-1);

   medio=(primero+ultimo) / 2;
   printf("\nComparando con la celda %2d ...",medio);

   if(clave<VECTOR[medio])
     pos=BUSCAR(primero, medio-1, clave);
   else
     if(clave>VECTOR[medio])
       pos=BUSCAR(medio+1, ultimo, clave);
     else
       pos=medio;
   return(pos);
}


