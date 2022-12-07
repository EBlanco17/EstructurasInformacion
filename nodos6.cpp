#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct nodo{
	struct nodo *siguiente;
	int coeficiente, exponente;
};

struct ListaPolinomios{
	struct ListaPolinomios *siguiente;
	struct nodo *polinomio;
};

int inicializarPolinomio(nodo **polinomio);
int insertarEnPolinomio(nodo *polinomio, int coeficiente, int exponente);

int inicializarListaPolinomios(ListaPolinomios **lista);
int insertarPolinomio(ListaPolinomios *lista, nodo *polinomio);

void imprimirPolinomio(nodo *polinomio);
void diferenciarPolinomio(nodo *polinomio);
void imprimirLista(ListaPolinomios **lista);
void sumarPolinomios(ListaPolinomios *lista, nodo *polinomio);

void menuDiferenciacion();
void menuSuma();

int main(){
	int opcion, salir=0;
	do{
		do{
			cout<<"1) Sumar dos o mas polinomios"<<endl;
			cout<<"2) Salir"<<endl;
			cin>>opcion;
		}while(opcion<1 || opcion>2);
		switch(opcion){
			case 1:
			      menuSuma();
			break;
			case 2:
				salir=1;
			break;
		}
	}while(salir != 1);
}

int inicializarPolinomio(nodo **polinomio){
	*polinomio = (nodo*)malloc(sizeof(nodo));
	if(*polinomio!=NULL){
		(*polinomio)->siguiente=NULL;
		(*polinomio)->exponente=-1;
		return 1;
	}
	return 0;
}
int insertarEnPolinomio(nodo *polinomio, int coeficiente, int exponente){
	nodo *aux;
	aux=polinomio;
	while(aux->siguiente!=NULL){
		if(aux->siguiente->exponente==exponente){
			aux->siguiente->coeficiente+=coeficiente;
			return 1;
		}else if(aux->siguiente->exponente<exponente){
			aux=aux->siguiente;
		}else{
			nodo *aux2;
			aux2 = (nodo*)malloc(sizeof(nodo));
			if(aux2==NULL) 
				return 0;
			aux2->coeficiente = coeficiente;
			aux2->exponente = exponente;
			aux2->siguiente = aux->siguiente;
			aux->siguiente = aux2;
			return 1;
		}
	}
	nodo *aux2;
	aux2 = (nodo*)malloc(sizeof(nodo));
	if(aux2==NULL) 
		return 0;
	aux2->coeficiente = coeficiente;
	aux2->exponente = exponente;
	aux2->siguiente = NULL;
	aux->siguiente = aux2;
	return 1;
}

int inicializarListaPolinomios(ListaPolinomios **lista){
	*lista = (ListaPolinomios*)malloc(sizeof(ListaPolinomios));
	if(*lista!=NULL){
		(*lista)->siguiente=NULL;
		return 1;
	}
	return 0;
}
int insertarPolinomio(ListaPolinomios *lista, nodo *polinomio){
	ListaPolinomios *aux;
	aux=lista;
	while(aux->siguiente!=NULL){
		aux=aux->siguiente;
	}
	ListaPolinomios *aux2;
	if(inicializarListaPolinomios(&aux2)){
		aux2->polinomio=polinomio;
		imprimirPolinomio(aux2->polinomio);
		aux->siguiente=aux2;
		return 1;
	}
	else
		return 0;
}

void imprimirPolinomio(nodo *polinomio){
	int flag = 1;
	nodo *aux = polinomio->siguiente;
	while(aux!=NULL){
		if(flag){
			if(aux->coeficiente!=0){
				flag=0;
				cout<<aux->coeficiente;
				if(aux->exponente>1)
					cout<<"x^", aux->exponente;
				else if(aux->exponente==1)
					cout<<"x";
			}
		}else{
			if(aux->coeficiente>0)
				cout<<"+";
			if(aux->coeficiente!=0){
				cout<<aux->coeficiente;
				if(aux->exponente>1)
					cout<<"x^"<<aux->exponente;
				else if(aux->exponente==1)
					cout<<"x";
			}
		}
		aux=aux->siguiente;
	}
	cout<<endl;
}

void imprimirLista(ListaPolinomios **lista){
	ListaPolinomios *aux = (*lista)->siguiente;
	while(aux!=NULL){
		imprimirPolinomio(aux->polinomio);
		aux=aux->siguiente;
	}
}
void sumarPolinomios(ListaPolinomios *lista,nodo *polinomio){
	ListaPolinomios *aux = lista->siguiente;
	nodo *auxP;
	while(aux!=NULL){
		auxP = aux->polinomio->siguiente;
		while(auxP!=NULL){
			insertarEnPolinomio(polinomio,auxP->coeficiente, auxP->exponente);
			auxP=auxP->siguiente;
		}
		aux=aux->siguiente;
	}
}


void menuSuma(){
	ListaPolinomios *lista;
	inicializarListaPolinomios(&lista);
	int cantidadPolinomios=0,salir=0;
	char opcion;
	nodo *polinomio;
	int coeficiente,exponente;
	do{
		inicializarPolinomio(&polinomio);
		cout<<"Ingresar el polinomio (ingresa -1 en el exponente para finalizar):"<<endl;
		do{
			cout<<"Coeficiente: ";
			cin>>coeficiente;
			cout<<"Exponente: ";
			cin>>exponente;
			if(exponente>=0)
				insertarEnPolinomio(polinomio,coeficiente,exponente);
		}while(exponente!=-1);
		system("cls");
		insertarPolinomio(lista, polinomio);
		cantidadPolinomios++;
		cout<<"Llevas "<<cantidadPolinomios<<" polinomio(s) ingresados"<<endl;
		getch();
		if(cantidadPolinomios>=2){
			cout<<"¿Deseas ingresar otro polinomio?"<<endl;
			cout<<"1) Si"<<endl;
			cout<<"2) No"<<endl;
			cin>>opcion;
			if(opcion==2)salir=1;
		}
	}while(cantidadPolinomios<2 || salir == 1);
	system("cls"); 
	cout<<"Lista de polinomios:"<<endl;
	imprimirLista(&lista);
	cout<<"Suma:"<<endl;
	inicializarPolinomio(&polinomio);
	sumarPolinomios(lista,polinomio);
	imprimirPolinomio(polinomio);
	getch();
}

