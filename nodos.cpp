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
    cout<<" 2. INGRESAR NUEVO DATO AL INICIO    "<<endl;
    cout<<" 3. INGRESAR NUEVO DATO AL FINAL     "<<endl;
    cout<<" 4. INGRESAR NUEVO DATO EN MEDIO     "<<endl;
    cout<<" 5. SALIR                            "<<endl;
 
    cout<<" ¿QUE DESEAS HACER?: ";
}
 
int ingresoMedios()
{
    int selPos, lado;

    cout<<"\t 1. Ingresar antes de la posicion seleccionada       "<<endl;
    cout<<"\t 2. Ingresar despues de la posicion seleccionada     "<<endl;
 
    cout<<"\n\t ¿Que deseas hacer? : "; 
	cin>> selPos;
 
    if(selPos==1){
	
        lado = -1;
		
		}
    else{
	
	lado = 0;
		}	
		
    return lado;
}

void ingresarDato(ListaSimple &lista, int valorDato, int posicion)
{
    ListaSimple primera, guarda;
    int i;
    primera = new(struct nodo);
    primera->DatosNumero = valorDato;
 
    if(posicion==1)
    {
    	
        primera->siguiente = lista;
        lista = primera;
        
    }
    else
    {
        int x = ingresoMedios();
                
        guarda = lista;
        for(i=1; guarda!=NULL; i++)
        {
            if(i==posicion+x)
            {
                primera->siguiente = guarda ->siguiente;
                guarda ->siguiente = primera;
                return;
            }
            guarda = guarda ->siguiente;
        }
    }
    cout<<"***La posicion seleccionada es erronea***"<<endl;
}
 
void ingresarDatoInicio( ListaSimple &lista, int valorDato)
{
    ListaSimple primera;
    primera = new(struct nodo);
    
    
    primera->DatosNumero = valorDato;
    primera->siguiente = lista;
    
    lista  = primera;
}
 
void ingresarDatoFinal(ListaSimple &lista, int valorDato)
{
    ListaSimple guarda, primera = new(struct nodo);
 
    primera->DatosNumero  = valorDato;
    primera->siguiente = NULL;
 
    if(lista==NULL)
    {
        lista = primera;
    }
    else
    {
        guarda = lista;
        while(guarda->siguiente!=NULL)
        {
            guarda = guarda ->siguiente;
        }
        	guarda ->siguiente = primera;
    }
 
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
 
int main()
{
    ListaSimple lista = NULL;
    int op;     
    int ingreso; 
    int pos;
 
    system("color F0");
    cout<<"********LISTA DINAMICA*******"<<endl;
    cout<<"***2. AGREGAR NUEVOS NODOS***"<<endl;
    
    do
    {   menu();
		cin>> op;
 
         switch(op)
        {
        	case 1:
                 cout << "\n\n IMPRIMIENDO LISTA DE DATOS\n"<<endl;
                 imprimirDatos(lista);
                 system("PAUSE");
            	break;
            case 2:
                 cout<< "\n INGRESE EL NUEVO DATO PARA LA LISTA (numero): "; 
				 cin>> ingreso;
                 ingresarDatoInicio(lista, ingreso);
                 
           		break;
 
             case 3:
                 cout<< "\n INGRESE EL NUEVO DATO PARA LA LISTA (numero): "; 
				 cin>> ingreso;
                 ingresarDatoFinal(lista, ingreso );
                 
            	break;
 
            case 4:
                 cout<< "\n INGRESE EL NUEVO DATO PARA LA LISTA (numero): ";
				 cin>> ingreso;
                 cout<< " Posicion en donde desea agregar el nuevo dato: ";       
				 cin>> pos;
                 ingresarDato(lista, ingreso, pos);
                 
           		break;
 		}       
		
		cout<<endl;
        system("cls");
    	}while(op!=5);
	
	system("PAUSE");
   return 0;
}

