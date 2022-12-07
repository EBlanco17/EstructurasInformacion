//No elimina el primer nodo

#include <iostream>

using namespace std;

struct nodo{ //creación del nodo para crear listas
	int dato;  //varible en que se guardara el numero
	struct nodo *enlace; //enlaza los nodos
};

//declaracion de metodos 
void menu();
void imprimir_lista(struct nodo *primero);
void buscar_repetido(struct nodo *primero);
void eliminar_nodo(struct nodo *primero, int valor );

int main(){
	system("color F0");
	menu();
	system("PAUSE");
	return 0;
}

void menu(){
	struct nodo *cab, *nuevo, *ult, *p; //apuntadores de trabajo
	char desea; //variables
	
	
	cout<<"--------------------------------"<<endl;
	cout<<"          BIENVENIDO            "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"********LISTA DINAMICA*******"<<endl;
    cout<<"*** 1. FRECUENCIA DE NUMEROS***"<<endl;
    
    system("PAUSE");
	system("cls");

cab = new struct nodo();  // reserva espacio de memoria para almacenar información
	cout<< "Digite el valor: ";
	cin >> cab->dato;  // asigna un valor al espacio reservado
	ult = cab;  // asigna el apuntador ult al mismo lugar donde esta apuntando cab
	
	cout << "Desea agregar otro nodo? s/n: ";
	cin >> desea;
	
	while(desea == 's' || desea == 'S'){
		nuevo = new struct nodo(); //creando nodo nuevo
		cout<< "Digite el valor: ";
		cin >> nuevo->dato; // asigna un valor al espacio reservado
		ult->enlace = nuevo; // conecta los dos nodos creados
		ult = nuevo;  //moviendo el apuntador ult al lugar del apuntador nuevo
		
		cout << "Desea continuar? s/n: ";
		cin >> desea;
		
	}
	ult->enlace = NULL;
	
	system("cls");
	p=cab;   //ubica el apuntador p al inicio de la lista
	cout<<"------------------------------"<<endl;
	cout<<"********LISTA INGRESADA*******"<<endl;
	cout<<"------------------------------"<<endl;
	imprimir_lista(p);//Imrprime la lista normal
	
	p=cab;	
	buscar_repetido(p);//busca que nodos estan repetidos y se le manda la lista
	
	cout<<"--------------------------"<<endl;
	cout<<"********NUEVA LISTA*******"<<endl;
	cout<<"--------------------------"<<endl;
	p=cab;   //ubica el apuntador p al inicio de la lista
	imprimir_lista(p); //Imprime lista luego de eliminar nodos
	
	
}

void imprimir_lista(struct nodo *primero){
while(primero != NULL){
		cout <<"->"<< primero->dato<<endl; //muestra la informacion
		primero = primero->enlace; //pasa al siguiente nodo luego de imprimir
		
	}	
}
void buscar_repetido(struct nodo *primero){
	struct nodo *q, *r; //declaracion de apuntadores
	q = primero;
	while (q != NULL){ //recorre toda la lista
		r = q->enlace; //se situa r en el 2do nodo
		while(r != NULL){ //recorre toda la lista a partir del 2do nodo
			if(r->dato == q->dato){
				eliminar_nodo(primero, r->dato); //si encuentra un numero igual lo envia para eliminar
				q=primero; //se situa q en la posicion de primero
				r=primero; //se situa q en la posicion de primero
			}
			r=r->enlace; //se situa r una posicion adelante
		}
		q=q->enlace; //se situa q una posicion adelante
	}
}
void eliminar_nodo(struct nodo *primero, int valor ){
	struct nodo *q, *r; //declaracion de apuntadores
	q = primero; //q se situa en la 1ra posicion 
	r = primero; //r se situa en la 1ra posicion 
	
	while(q != NULL){ //recorre toda la lista buscando los # repetidos
	    if(q->dato == valor) //compara el primer dato con el # que llego
        {
            if(q == primero)
            {
                primero = primero->enlace;
                delete(q); //se elimina el nodo repetido
                q = primero;
            }
            else
            {
                r->enlace = q->enlace;
                delete(q); //se elimina el nodo y se conectan 
                q = r->enlace; //q se situa una posicion adelante de r
            }
        }
        else 
        {
            r = q;
            q = q->enlace; //si no cumple la condicion pasa q al siguiente nodo y vuelve al inicio
        }
 
    }
}



