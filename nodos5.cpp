/*
* C++ - Ordenar numeros en una lista enlazada simple
*
* Copyright 2014 Martin Cruz Otiniano
*
* Description: Ordena mediante el criterio de burbuja una lista 
*
* Site: martincruz.me
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *Tlista;

Tlista inicio, fin;

void generarLista( Tlista &inicio, Tlista &fin, int n ) 
{
     Tlista q, t;
     
     for(int i=0; i<n; i++)
     {
         q = new(struct nodo);
         q->nro = rand()%51;
         
         if(inicio==NULL)
         {
              q->sgte = inicio;
              inicio  = q;
              fin     = q;          
         }
         else
         {
              q->sgte   = fin->sgte;
              fin->sgte = q;
              fin       = q;
         }
     }
     
     cout<<"\n\n\tLista de numeros generados... "<<endl;
}


void reportarLista(Tlista inicio)
{
     
     while(inicio != NULL)
     {
          cout <<"  " << inicio->nro ;
          inicio = inicio->sgte;
     }

}

void ordenarLista(Tlista lista)
{
     Tlista actual , siguiente;
     int t;
     
     actual = lista;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;
          
          while(siguiente!=NULL)
          {
               if(actual->nro > siguiente->nro)
               {
                    t = siguiente->nro;
                    siguiente->nro = actual->nro;
                    actual->nro = t;          
               }
               siguiente = siguiente->sgte;                    
          }    
          actual = actual->sgte;
          siguiente = actual->sgte;
           
     }
     
     cout<<"\n\n\tLista ordenada..."<<endl;
}


void menu()
{
    cout<<"\n\t\tORDENAMIENTO DE UNA LISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. GENERAR NUMEROS                  "<<endl;
    cout<<" 2. MOSTRAR NUMEROS                   "<<endl;
    cout<<" 3. ORDENAR NUMEROS                   "<<endl;
    cout<<" 4. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}


/*                        Funcion Principal
------------------------------------------------------------------*/

int main()
{
    inicio = NULL;
    fin    = NULL;
    
    int op;     // opcion del menu
    int num;   // elemenento a ingresar

    system("color 0b");

    do
    {
        menu();  cin>> op;

        switch(op)
        {      
            case 1:
                 cout<< "\n Cantidad de numeros: "; cin>> num;
                 generarLista( inicio, fin, num );
            break;


            case 2:
                 cout<<"\n\n LISTA:\n\n";
                 reportarLista( inicio );
            break;
            
            
            case 3:
                 ordenarLista( inicio );
            break;            

        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=4);


   system("pause");
   
   return 0;
}

