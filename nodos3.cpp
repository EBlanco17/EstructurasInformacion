#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;

};

void menu();
Nodo *crear(int);
void agregar(Nodo *&,int);
void mostrar(Nodo *,int);
void inverso(Nodo*,int);
Nodo *lista =NULL;

int main() {
	system("color F0");
    cout<<"********LISTA DINAMICA*******"<<endl;
    cout<<"***3.IMPRMIR LISTA AL REVES***"<<endl;
    
	menu();
	return 0;
}
void menu(){
	int dato,opc, cont=0;
	do{
	cout<<"------------Menu----------"<<endl;
	cout<<"1. Agregar nodo"<<endl;
	cout<<"2. Mostrar lista"<<endl;
	cout<<"3. Mostrar lista inversa"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Ingrese opcion: "<<endl;
	cin>>opc;
	system("cls");
switch(opc){
case 1:
	cout<<"Ingrese un numero a guardar: "; cin>>dato;
	agregar(lista,dato);
	system("pause");
	break;
case 2:
	cout<<"-----La lista es------"<<endl;
	mostrar(lista,cont);
	cout<<endl<<endl;
	system("pause");
	system("cls");
break;	
case 3:
	cout<<"-----La lista original es------"<<endl;
	mostrar(lista,cont);
	cout<<endl<<endl;
	cout<<"-----La lista invertida es------"<<endl;
	inverso(lista,cont);
	cout<<endl<<endl;
	system("pause");
	system("cls");
break;
}
}while(opc !=4);
}
//Crear nuevo nodo
Nodo *crear(int a){
	Nodo *nuevo =new Nodo();
	nuevo->dato = a;
	nuevo->sig = NULL;
	return nuevo;
	}
//Insertar nodos 
void agregar(Nodo *&lista, int a){
	//agregar el primer nodo
	if (lista == NULL){
		Nodo *nuevo =crear(a);
		lista = nuevo;
	}//si ya tiene un nodo lo organiza
	else {
		agregar(lista->sig,a);
}
}	
void mostrar(Nodo *lista,int cont){
	
	if(lista==NULL){
		return;
	}
	else{
		mostrar(lista->sig,cont+1);
	}
	cout<<lista->dato <<" -> ";	
	
}
void inverso(Nodo *lista,int cont){
	
	if(lista==NULL){
		return;
		}
	cout<<lista->dato<<" -> ";		
	inverso(lista->sig, cont+1);
}

