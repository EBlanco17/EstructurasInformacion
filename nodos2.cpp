#include <iostream>
#include <stdlib.h>
using namespace std;

 
struct nodo{
       int DatosNumero;       
       struct nodo *siguiente;
};


typedef struct nodo *ListaSimple;
 
void menu()
{
    cout<<" --------------MENU--------------"<<endl;
    cout<<" 1. IMPRIMIR LISTA DE DATOS          "<<endl;
    cout<<" 2. INGRESAR NUEVO DATO				"<<endl;
    cout<<" 3. ELIMINAR DATOS REPETIDOS         "<<endl;
    cout<<" 4. SALIR                            "<<endl;
 
    cout<<"\n ¿QUE DESEAS HACER?: ";
}
 
void ingresarDatoInicio( ListaSimple &lista, int valorDato)
{
    ListaSimple primera;
    primera = new(struct nodo);
    
    
    primera->DatosNumero = valorDato;
    primera->siguiente = lista;
    
    lista  = primera;
}

void imprimirDatos(ListaSimple lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->DatosNumero << endl;
          
          lista = lista->siguiente;
          i++;
     }
}


void eliminar(ListaSimple &lista, int valorDato)
{
    ListaSimple primera, anterior;
    primera = lista;
    anterior = lista;
 
    while(primera!=NULL)
    {
	
        if(primera->DatosNumero==valorDato)
        {
            if(primera==lista)
            {
                lista = lista->siguiente;
                delete(primera);
                primera = lista;
            }
            else
            {
                anterior->siguiente = primera->siguiente;
                delete(primera);
                primera = anterior->siguiente;
            }
        }
        else
        {
            anterior = primera;
            primera = primera->siguiente;
        }
 
    }
    cout<<"\n\n NUMEROS REPETIDOS ELIMINADOS..!"<<endl;
}
 
int main()
{
    ListaSimple lista = NULL;
    int op;     
    int ingreso; 
    int pos;
 
 
    system("color F0");
    cout<<"********LISTA DINAMICA*******"<<endl;
    cout<<"***1. BORRAR NODOS***"<<endl;
    
    do
    {
        menu();
		
		cin>> op;
 
        switch(op)
        {
        	case 1:
 
                 cout << "\n\n IMPRIMIENDO LISTA DE DATOS\n"<<endl;
                 imprimirDatos(lista);
            	break;
 
            case 2:
 
                 cout<< "\n INGRESE EL NUEVO DATO PARA LA LISTA (numero): "; 
				 cin>> ingreso;
                 ingresarDatoInicio(lista, ingreso );
            	break;
 			case 3:
 				
              	cout<<"\n INGRESE EL DATO REPETIDO A ELIMINAR: "; 
				cin>> ingreso;
                eliminar(lista, ingreso);
 		}       
		
		
		cout<<endl<<endl;
        system("pause");  	
		system("cls");
    	}while(op!=4);
	
	system("pause");
   return 0;
   }

