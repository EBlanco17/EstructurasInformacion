#include<iostream>
#include <stdio.h>
#include<cstdlib>
#include <conio.h>
#include <string.h>
#define n 30
using namespace std;
void print();
void enfrent();
void printVS();
void principal();
struct competidores {
	char nombre[20], categoria[60];
} versus[n];

int main() {
	system("color f0");
	cout<<"Bienvenido"<<endl;
	principal();
	return 0;
}
void principal() {
	short int opc;
	char op;
	for(int i=0; i<n; i++) {
		cout<<"---------------Datos de la persona "<<i+1<<"---------------"<<endl;
		cout<<"Ingrese el nombre del competidor: ";
		cin>>versus[i].nombre;
		cout<<"Ingrese la disciplina y la categoria de "<<versus[i].nombre<<": "<<endl;
		cout<<"Ejemplo: futbol-amateur: ";
		cin>>versus[i].categoria;
	}
	cout<<endl;
	do {
		cout<<"--------------Menu-------------"<<endl;
		cout<<"1. Mostrar los competidores disponibles \n Disciplina-Categoria Alfabeticamente"<<endl;
		cout<<"2. Mostrar los versus disponibles"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>opc;
		switch(opc) {
			case 1:
				enfrent();
				print();
				break;
			case 2:
				printVS();
				break;
			case 3:
				system("exit");
				break;
		}
		cout<<"Volver al menu s/n: ";
		cin>>op;
	} while(op != 'n');
}
void enfrent() {
	struct competidores aux;
	int change=0;
	int temp;
	for(int i=1; i<n; i++) {
		for(int j=n-1; j>=i; j--) {
			temp=strcmp(versus[j-1].categoria, versus[j].categoria);
			if(temp>0) {
				aux=versus[j];
				versus[j]=versus[j-1];
				versus[j-1]=aux;
				change=1;
			}
		}
		if (change==0) break;
	}
}
void print() {
	for( int i = 0; i < n; i++ ) {
		cout<<"---------------------------------"<<endl;
		cout<<"Nombre: "<<versus[i].nombre<<endl;
		cout<<"Disciplina-Categoria: "<<versus[i].categoria<<endl;
	}
	cout<<"---------------------------------"<<endl;
}
void printVS() {
	for(int i=0; i<n; i++) {
		for(int j=n; j>=0; j--) {
			if(strcmp(versus[j].categoria,versus[i].categoria)==0) {
				if(strcmp(versus[j].nombre,versus[i].nombre)<0) {
					cout<<"Disciplina-Categoria: "<<versus[i].categoria<<endl;
					cout<<versus[j].nombre<<" VS "<<versus[i].nombre<<endl;
					cout<<"---------------------------------------"<<endl;
				}
			}
		}
	}
}

