//Ejemplo de un arbol binario de busqueda
#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo *sig;
	Nodo *ant;
	Nodo *padre;
};

//Funciones
void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);
Nodo *arbol = NULL;

int main() {
	system("color f0");
	menu();
	return 0;
}

//Funcion de menu
void menu() {
	int dato, opcion, contador=0;

	do {
		cout<<".:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar arbol completo"<<endl;
		cout<<"3. Buscar un elemento"<<endl;
		cout<<"4. Recorrer arbol en PreOrden"<<endl;
		cout<<"5. Recorrer arbol en InOrden"<<endl;
		cout<<"6. Recorrer arbol en PostOrden"<<endl;
		cout<<"7. Eliminar un nodo"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>opcion;

		switch(opcion) {
			case 1:
				cout<<"Digite un numero: ";
				cin>>dato;
				insertarNodo(arbol, dato, NULL); //Insertar nuevo nodo
				cout<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Mostrando arbol completo: \n\n";
				mostrarArbol(arbol, contador);
				cout<<endl;
				system("pause");
				break;
			case 3:
				cout<<"Digite el elemnto a buscar: ";
				cin>>dato;
				if(busqueda(arbol, dato) == true) {
					cout<<"\n"<<dato<<" Ha sido encontrado en el arbol"<<endl;
				} else {
					cout<<"\n"<<dato<<" No se ha encontrado el dato en el arbol"<<endl;
				}
				cout<<endl;
				system("pause");
				break;
			case 4:
				cout<<"Recorrido en PreOrden: "<<endl;
				preOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 5:
				cout<<"Recorrido en InOrden: "<<endl;
				inOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 6:
				cout<<"Recorrido en PostOrden: "<<endl;
				postOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 7:
				cout<<"Eliminar nodo: "<<endl;
				cout<<"Digite el numero a eliminar: ";
				cin>>dato;
				eliminar(arbol, dato);
				cout<<"\n\n";
				system("pause");
		}
		system("cls");
	} while(opcion != 8);
}

//Funcion para crear nodos
Nodo *crearNodo(int n, Nodo *padre) {
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->sig = NULL;
	nuevo_nodo->ant = NULL;
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre) {
	if(arbol == NULL) { //si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	} else { //condiciones para agregar el elemento
		int valorRaiz = arbol->dato;
		if(n < valorRaiz) {
			insertarNodo(arbol->ant, n, arbol);
		} else {
			insertarNodo(arbol->sig, n, arbol);
		}
	}
}

//Funcion mostrar arbol
void mostrarArbol(Nodo *arbol, int contador) {
	if(arbol == NULL) {
		return;
	} else {
		mostrarArbol(arbol->sig, contador+1);
		for(int i=0; i < contador; i++) {
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->ant, contador+1);
	}

}

//Funcion buscar elemento en arbol
bool busqueda(Nodo *arbol, int n) {
	if(arbol == NULL) {
		return false;
	} else if(arbol->dato == n) {
		return true;
	} else if(n < arbol->dato) {
		return busqueda(arbol->ant, n);
	} else {
		return busqueda(arbol->sig, n);
	}

}

//Funcion recorrido en profundidad - preOrden
void preOrden(Nodo *arbol) {
	if(arbol == NULL) {
		return;
	} else {
		cout<<arbol->dato<<" - ";
		preOrden(arbol->ant);
		preOrden(arbol->sig);
	}
}

//Funcion recorrido en profundidad InOrden
void inOrden(Nodo *arbol) {
	if(arbol == NULL) {
		return;
	} else {
		inOrden(arbol->ant);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->sig);
	}

}

//Funcion recorrido en profundidad PostOrden
void postOrden(Nodo *arbol) {
	if(arbol == NULL) {
		return;
	} else {
		postOrden(arbol->ant);
		postOrden(arbol->sig);
		cout<<arbol->dato<<" - ";
	}
}
//Funcion eliminar nodo
void eliminar(Nodo *arbol, int n) {
	if(arbol == NULL) {
		return;
	} else if(n < arbol->dato) {
		eliminar(arbol->ant, n);
	} else if(n > arbol->dato) {
		eliminar(arbol->sig, n);
	} else {
		eliminarNodo(arbol);
	}
}
//Funcion para determinar el nodo mas izquierdo
Nodo *minimo(Nodo *arbol) {
	if(arbol == NULL) {
		return NULL;
	}
	if(arbol->ant) {
		return minimo(arbol->ant);
	} else { //si no tiene nodo izq
		return arbol; //retornar el mismo nodo
	}
}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
	if(arbol->padre) {
		//arbol->padre asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->ant->dato) {
			arbol->padre->ant = nuevoNodo;
		} else if(arbol->dato == arbol->padre->sig->dato) {
			arbol->padre->sig = nuevoNodo;
		}
	}
	if(nuevoNodo) {
		//hijo asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

//Funcion para destruir un nodo
void destruirNodo(Nodo *nodo) {
	nodo->ant = NULL;
	nodo->sig = NULL;

	delete nodo;
}


//Funcion eliminar nodo encontrado
void eliminarNodo(Nodo *nodoEliminar) {
	if(nodoEliminar->ant && nodoEliminar->sig) {
		Nodo *menor = minimo(nodoEliminar->sig);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	} else if(nodoEliminar->ant) {
		reemplazar(nodoEliminar, nodoEliminar->ant);
		destruirNodo(nodoEliminar);
	} else if(nodoEliminar->sig) {
		reemplazar(nodoEliminar, nodoEliminar->sig);
		destruirNodo(nodoEliminar);
	} else { //Nodo Hoja
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}

