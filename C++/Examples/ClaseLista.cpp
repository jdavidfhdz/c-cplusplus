// Programa de Listas Encadenadas con apuntadores de Objetos


#include <iostream.h>
#include <conio.h>

class ClaseLista
{
   public:
     void Inicializa();  // Declara NULO al apuntador inicial de la lista
     void Insertar(char d); // Metodo para insertar un dato
     void Eliminar(char d); // Metodo para eliminar un dato
     void Recorrido(); // Metodo para mostrar los datos de la lista
   private:
     class Nodo  // Declaracion de la clase del Nodo (sub-clase de la Clase)
     {
	public:
	  char dato;  // Dato del nodo (caracter)
	  Nodo *sn;   // Apuntador al siguiente nodo
     };

     Nodo *inicial;  // Declaracion del nodo inicial de la lista
};

void ClaseLista::Eliminar(char d)
{
  Nodo *i=inicial, *anterior;
  if(i==NULL)
  {
    cout<<"\n\nLista vacia !!!";
    getch();
    return;
  }
  while(i!=NULL)
  {
    if(d==i->dato)
    {
       if(i==inicial) // Baja al principio?
       {
	  inicial=inicial->sn;
	  cout<<"\nBaja al principio...";
	  getch();
	  return;
       }
       anterior->sn=i->sn;
       delete i;
       cout<<"\nBaja intermedia o al final ...";
       getch();
       return;
    }
    anterior=i;
    i=i->sn;   // Cambiar al siguiente nodo
  }
  cout<<"\n\nNo existe ese dato !!!";
  getch();
  return;
}

void ClaseLista::Inicializa()
{
  inicial=NULL;   // Declara NULO el nodo inicial de la lista
  cout << "\nLista inicializada !!!"<<endl;
  getch();
}

void ClaseLista::Recorrido()
{
  Nodo *i=inicial;
  clrscr();
  cout<<"\n<<< RECORRIDO DE LA LISTA ENCADENADA >>>\n\n"<<endl;
  if(i==NULL)  // Lista vacia?
  {
     cout << "\nLista vacia ...";
     getch();
     return;
  }
  while(i!=NULL)
  {
     cout << i->dato <<"->";
     i=i->sn;
  }
  cout<<"NULL";
  cout<<"\n\n\n<<< Oprima cualquier tecla para continuar >>>";
  getch();
  return;
}

void ClaseLista::Insertar(char d)
{
  Nodo *i=inicial, *auxiliar, *anterior;
  if(i==NULL) // Alta a lista vacia
  {
     auxiliar=new Nodo;
     auxiliar->dato=d;
     auxiliar->sn=NULL;
     inicial=auxiliar;
     cout<<"\nAlta a lista vacia ...";
     getch();
     return;
  }
  do {
       if(i->dato == d)
       {
	  cout<<"\n\nDuplicado !!!";
	  getch();
	  return;
       }
       if(d < i->dato)
       {
	 if(i==inicial)  // Alta al principio
	 {
	    auxiliar=new Nodo;
	    auxiliar->dato=d;
	    auxiliar->sn=inicial;
	    inicial=auxiliar;
	    cout<<"\nAlta al principio ...";
	    getch();
	    return;
	 }
	 auxiliar=new Nodo;   // Alta intermedia
	 auxiliar->dato=d;
	 auxiliar->sn=anterior->sn;
	 anterior->sn=auxiliar;
	 cout<<"\nAlta intermedia ...";
	 getch();
	 return;
       }
       anterior=i;
       i=i->sn;
  }while(i!=NULL);
  auxiliar=new Nodo;  // Alta al final
  auxiliar->dato=d;
  auxiliar->sn=anterior->sn;
  anterior->sn=auxiliar;
  cout<<"\nAlta al final ...";
  getch();
  return;
}

void Altas(); // Declaracion de la rutina para insertar datos
void Bajas(); // Declaracion de la rutina para eliminar datos

ClaseLista *Lista; // Declaracion global de la lista encadenada

main()
{
  int op;
  Lista->Inicializa();
  do {
     clrscr();
     cout<<"\n<<< LISTAS ENCADENADAS CON APUNTADORES DE OBJETOS >>>"<<endl;
     cout<<"\n1.- Altas";
     cout<<"\n2.- Bajas";
     cout<<"\n3.- Recorrido";
     cout<<"\n0.- Salir";
     cout<<"\n\nOpcion? ---> ";
     cin>>op;

     switch(op)
     {
	case 1 : Altas();            break;
	case 2 : Bajas();            break;
	case 3 : Lista->Recorrido(); break;
     }
  }while(op!=0);
  clrscr();
  return(0);
}

void Altas()
{
   char dato;
   clrscr();
   cout<<"\n<<< ALTAS EN LISTAS ENCADENADAS CON APUNTADORES DE OBJETOS >>>"<<endl;
   cout<<"\n\nDato a insertar ---> ";
   cin>>dato;
   Lista->Insertar(dato);
}

void Bajas()
{
   char dato;
   clrscr();
   cout<<"\n<<< BAJAS EN LISTAS ENCADENADAS CON APUNTADORES DE OBJETOS >>>"<<endl;
   cout<<"\n\nDato a eliminar ---> ";
   cin>>dato;
   Lista->Eliminar(dato);
}
