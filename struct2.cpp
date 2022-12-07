#include<iostream>
#include <stdio.h>
#include<cstdlib>
#include<string.h>
#define p 10
using namespace std;

struct people {
	char name[20],lastName[20];
	short int age;
	float height, weight, imc;
} person[p];

void readData();
void sortName();
void sortLastName();
void quicksortAge( int start, int end );
void quicksortHeight( int start, int end );
void quicksortWeight( int start, int end );
int divideAge( int start, int end );
int divideHeight( int start, int end );
int divideWeight( int start, int end );
void print();

int main() {
	system("color f0");
	cout<<"Bienvenido"<<endl;
	readData();
	return 0;
}

void readData() {
	float mAge=0,rMAge=0,mHeight=0,rMHeight=0,mWeight=0,rMWeight;
	short int opc, opcO, opcM;
	char opM;

	for(int i=0; i<p; i++) {
		cout<<"---------------Datos de la persona "<<i+1<<"---------------"<<endl;
		cout<<"Ingrese nombre de la persona: ";
		cin>>person[i].name;
		cout<<"Ingrese apellido de la persona: ";
		cin>>person[i].lastName;
		cout<<"Ingrese edad de la persona: ";
		cin>>person[i].age;
		cout<<"Ingrese estatura de la persona (metros): ";
		cin>>person[i].height;
		cout<<"Ingrese peso de la persona (kilogramos): ";
		cin>>person[i].weight;

//calculos
		mAge+=person[i].age;
		mHeight+=person[i].height;
		mWeight+=person[i].weight;
		person[i].imc=person[i].weight / (person[i].height*person[i].height);
	}
//calculos media
	rMAge=mAge/p;
	rMHeight=mHeight/p;
	rMWeight=mWeight/p;

	cout<<endl;
	do {
		cout<<"-----Menu----"<<endl;
		cout<<"1. Ordenar"<<endl;
		cout<<"2. Calcular Media"<<endl;
		cout<<"3. Calcular IMC"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>opc;
		switch(opc) {
			case 1:
				cout<<endl;
				cout<<"Menu Ordenar"<<endl;
				cout<<"1. Ordenar por nombre"<<endl;
				cout<<"2. Ordenar por apellido"<<endl;
				cout<<"3. Ordenar por edad"<<endl;
				cout<<"4. Ordenar por estatura"<<endl;
				cout<<"5. Ordenar por peso"<<endl;
				cout<<"Ingrese opcion: ";
				cin>>opcO;
				switch(opcO) {
					case 1:
						cout<<endl;
						cout<<"Ordenar por nombre"<<endl;
						sortName();
						print();
						break;
					case 2:
						cout<<endl;
						cout<<"Ordenar por apellido"<<endl;
						sortLastName();
						print();
						break;

					case 3:
						cout<<endl;
						cout<<"Ordenar por edad"<<endl;
						quicksortAge( 0, p - 1 );
						print();
						break;
					case 4:
						cout<<endl;
						cout<<"Ordenar por estatura"<<endl;
						quicksortHeight( 0, p - 1 );
						print();
						break;
					case 5:
						cout<<endl;
						cout<<"Ordenar por peso"<<endl;
						quicksortWeight( 0, p - 1 );
						print();
						break;
					default:
						cout<<"Error"<<endl;
						break;
				}
				break;
			case 2:
				cout<<endl;
				cout<<"Menu Calcular"<<endl;
				cout<<"1. Calcular media de edades"<<endl;
				cout<<"2. Calcular media de estaturas"<<endl;
				cout<<"3. Calcular media de pesos"<<endl;
				cout<<"Ingrese opcion: ";
				cin>>opcM;
				switch(opcM) {
					case 1:
						cout<<endl;
						cout<<"Calcular Media de Edades"<<endl;
						cout<<rMAge<<" anios."<<endl;
						cout<<"--------------------------------"<<endl;
						break;
					case 2:
						cout<<endl;
						cout<<"Calcular Media de Estaturas"<<endl;
						cout<<rMHeight<<" metros."<<endl;
						cout<<"--------------------------------"<<endl;
						break;
					case 3:
						cout<<endl;
						cout<<"Calcular Media de Peso"<<endl;
						cout<<rMWeight<<" kilogramos."<<endl;
						cout<<"--------------------------------"<<endl;
						break;
					default:
						cout<<endl;
						cout<<"Error"<<endl;
						break;
				}
				break;
			case 3:
				cout<<endl;
				cout<<"Calcular IMC"<<endl;
				for(int i=0; i<p; i++) {
					cout<<person[i].name<<" "<<person[i].lastName<<endl;
					if(person[i].imc<18.5) {
						cout<<person[i].imc<<" Se encuentra en Bajo de peso"<<endl;
					} else if(person[i].imc >= 18.5 && person[i].imc <= 24.9) {
						cout<<person[i].imc<<" Se encuentra normal"<<endl;
					} else if(person[i].imc >= 25.0 && person[i].imc <= 29.9) {
						cout<<person[i].imc<<" Se encuentra en sobrepeso"<<endl;
					} else if(person[i].imc>=30.0) {
						cout<<person[i].imc<<" Se encuentra en obesidad"<<endl;
					}
					cout<<"--------------------------------"<<endl;
				}
				break;
			case 4:
				cout<<"Saliendo...Vuelva Pronto!"<<endl;
				system("exit");
				break;
			default:
				system("exit");
				break;
		}
		cout<<"Desea redirigirse al menu s/n: ";
		cin>>opM;
	} while(opM == 's');
}

//Nombres
void sortName() {
	struct people aux;
	int change=0;
	int temp;
	for(int i=1; i<p; i++) {
		for(int j=p-1; j>=i; j--) {
			temp=strcmp(person[j-1].name,person[j].name);
			if(temp>0) {
				aux=person[j];
				person[j]=person[j-1];
				person[j-1]=aux;
				change=1; //si hubo cambio cambiamos
			}
		}
		if (change==0)
			break; //si no hubo cambios entonces
	}
}

//apellidos
void sortLastName() {
	struct people aux;
	int change=0;
	int temp;
	for(int i=1; i<p; i++) {
		for(int j=p-1; j>=i; j--) {
			temp=strcmp(person[j-1].lastName,person[j].lastName);
			if(temp>0) {
				aux=person[j];
				person[j]=person[j-1];
				person[j-1]=aux;
				change=1; //si hubo cambio cambiamos
			}
		}
		if (change==0)
			break; //si no hubo cambios entonces
	}
}

//Edades
void quicksortAge( int start, int end ) {
	int pivot;

	if (start < end) {
		pivot = divideAge( start, end );
		quicksortAge( start, pivot - 1 );
		quicksortAge( pivot + 1, end);
	}
}
int divideAge( int start, int end ) {
	int left;
	int right;
	int pivot;
	people temp;

	pivot = person[start].age;
	left = start;
	right = end;

	while (left < right) {
		while (person[right].age > pivot) {
			right--;
		}
		while ((left < right) && (person[left].age <= pivot)) {
			left++;
		}
		if (left < right) {
			temp = person[left];
			person[left] = person[right];
			person[right] = temp;
		}
	}
	temp = person[right];
	person[right] = person[start];
	person[start] = temp;
	return right;
}
//Estatura
void quicksortHeight( int start, int end ) {
	int pivot;

	if (start < end) {
		pivot = divideHeight( start, end );
		quicksortHeight( start, pivot - 1 );
		quicksortHeight( pivot + 1, end);
	}
}
int divideHeight( int start, int end ) {
	int left;
	int right;
	float pivot;
	people temp;

	pivot = person[start].height;
	left = start;
	right = end;

	while (left < right) {
		while (person[right].height > pivot) {
			right--;
		}
		while ((left < right) && (person[left].height <= pivot)) {
			left++;
		}
		if (left < right) {
			temp = person[left];
			person[left] = person[right];
			person[right] = temp;
		}
	}
	temp = person[right];
	person[right] = person[start];
	person[start] = temp;
	return right;
}
//Peso
void quicksortWeight( int start, int end ) {
	int pivot;

	if (start < end) {
		pivot = divideWeight( start, end );
		quicksortWeight( start, pivot - 1 );
		quicksortWeight( pivot + 1, end);
	}
}
int divideWeight( int start, int end ) {
	int left;
	int right;
	float pivot;
	people temp;

	pivot = person[start].weight;
	left = start;
	right = end;

	while (left < right) {
		while (person[right].weight > pivot) {
			right--;
		}
		while ((left < right) && (person[left].weight <= pivot)) {
			left++;
		}
		if (left < right) {
			temp = person[left];
			person[left] = person[right];
			person[right] = temp;
		}
	}
	temp = person[right];
	person[right] = person[start];
	person[start] = temp;
	return right;
}
void print() {
	for( int i = 0; i < p; i++ ) {
		cout<<"---------------------------------"<<endl;
		cout<<person[i].name<<" "<<person[i].lastName<<endl;
		cout<< person[i].age << " anios."<<endl;
		cout<<"Estatura: "<<person[i].height << " metros."<<endl;
		cout<< "Peso: "<<person[i].weight << " kg." << endl;
	}
	cout<<"---------------------------------"<<endl;
}

