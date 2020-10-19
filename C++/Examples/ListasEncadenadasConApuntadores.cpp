// Programa de Listas Encadenadas con apuntadores
// Autor: Ing. Bruno Lopez Takeyas

#include <iostream.h>
#include <conio.h>

struct nodo  //Declaracion del tipo de nodo
{
   char dato; // Dato del nodo (caracter)
   struct nodo *sn;  //Apuntador al siguiente nodo
};

struct nodo *inicial; //Declaracion global del nodo inicial de la lista

void Altas(); // Declaracion de la rutina de Altas (Insercion de datos)
void Bajas(); // Declaracion de la rutina para eliminar datos
void Recorrido(); //Declaracion de la rutina para desplegar los datos

main()
{
  int op=0;

  do
  {
     clrscr();
     cout<<"\n<<< LISTAS ENCADENADAS CON APUNTADORES >>>"<<endl;
     cout<<"\n1.- Altas";
     cout<<"\n2.- Bajas";
     cout<<"\n3.- Recorrido";
     cout<<"\n0.- Salir";
     cout<<"\n\n\nOpcion? ---> ";
     cin>>op;

     switch(op)
     {
	case 1 : Altas();     break;
	case 2 : Bajas();     break;
	case 3 : Recorrido(); break;
     }
  }while(op!=0);
  return(0);
}

void Altas()
{
  struct nodo *anterior, *i=inicial, *auxiliar;
  //Declaracion local del nodo anterior y un nodo auxiliar
  char dato;
  clrscr();
  cout<<"\n<<< ALTAS EN UNA LISTA ENCADENADA >>>"<<endl;
  cout<<"\nDato a insertar ---> ";
  cin>>dato;

  if(inicial==NULL)  // Esta vacia la lista encadenada ?
  {
     inicial=new nodo;
     inicial->dato=dato;
     inicial->sn=NULL;
     cout << "\n\nDato insertado en Lista vacia !!!";
     getch();
     return;
  }
  do
  {
     if(dato==i->dato)
     {
	cout << "\nDuplicado !!!";
	getch();
	return;
     }
     if(dato < i->dato)
     {
	if(i==inicial) // Alta al principio
	{
	   auxiliar=new nodo;
	   auxiliar->dato=dato;
	   auxiliar->sn=inicial;
	   inicial=auxiliar;
	   cout<<"\nDato insertado al principio de la lista !!!";
	   getch();
	   return;
	}
	auxiliar=new nodo;    // Alta intermedia
	auxiliar->dato=dato;
	auxiliar->sn=anterior->sn;
	anterior->sn=auxiliar;
	cout<<"\nDato insertado mediante alta intermedia !!!";
	getch();
	return;
     }
     anterior=i;
     i=i->sn;
  }while(i!=NULL);
  auxiliar=new nodo; // Creacion de un nodo auxiliar
  auxiliar->dato=dato;  // Alta al final
  auxiliar->sn=NULL;
  anterior->sn=auxiliar;
  cout<<"\nDato insertado al final de la Lista !!!";
  getch();
  return;
}

void Recorrido()
{
  struct nodo *i=inicial;
  clrscr();
  cout<<"\n<<< RECORRIDO DE LOS DATOS EN LA LISTA ENCADENADA >>>\n\n"<<endl;
  if(i==NULL)
  {
    cout<<"\n\nLista encadenada vacia !!!";
    getch();
    return;
  }

  while(i!=NULL)
  {
     cout<<i->dato<<" -> ";
     i=i->sn;
  }
  cout<<"NULL"<<endl;
  cout<<"\n\n<<< Oprima cualquier tecla para continuar >>>";
  getch();
}

void Bajas()
{
  struct nodo *anterior, *i=inicial; //Declaracion local del nodo anterior y un nodo auxiliar
  char dato;
  clrscr();
  cout<<"\n<<< BAJAS EN UNA LISTA ENCADENADA >>>"<<endl;
  if(i==NULL)
  {
    cout<<"\n\nLista encadenada vacia !!!";
    getch();
    return;
  }

  cout<<"\nDato a eliminar ---> ";
  cin>>dato;
  do
  {
    if(dato==i->dato)
    {
       if(i==inicial)  // Baja al principio?
       {
	  inicial=inicial->sn;
	  cout << "\n\nDato eliminado al principio de la lista !!!";
	  getch();
	  return;
       }
       anterior->sn=i->sn; // El nodo anterior apunta al que apuntaba el nodo a eliminar
       delete i; // Eliminar el nodo
       cout<<"\n\nBaja de un dato intermedio o al final !!!";
       getch();
       return;
    }
    if(dato < i->dato)
    {
       cout<<"\n\nNo existe ese dato !!!";
       getch();
       return;
    }
    anterior=i;
    i=i->sn;
  }while(i!=NULL);
  cout<<"\n\nNo existe ese dato !!!";
  getch();
  return;
}
