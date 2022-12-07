#include <iostream>
#include <stdlib.h>

using namespace std;

struct persona {
	int edad;
	int diaF, mesF;
	int long id;
	char nombre[20];
	char apellido[30];
	char genero;
};

struct nodo {
	struct persona datos;
	struct nodo *siguiente;
};

void menu();


int main() {
	system("color F0");
	menu();
	system("PAUSE");
	return 0;
}

void menu() {
	struct nodo *cab, *nuevo, *ult, *p; //apuntadores de trabajo
	char desea;
	int opc, anioA, mesA, diaA, anioN,mesN,diaN, edadm, edadmx;

	cout<<"--------------------------------"<<endl;
	cout<<"          BIENVENIDO            "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"********LISTA DINAMICA*******"<<endl;
	cout<<"***5. DATOS PERSONAS***"<<endl;
	cout<<"Ingrese anio actual: ";
	cin>>anioA;
	cout<<"Ingrese mes actual: ";
	cin>>mesA;
	cout<<"Ingrese dia actual: ";
	cin>>diaA;

	system("cls");
	cout<<"*************************************"<<endl;
	cout<<"------------NUEVA PERSONA------------"<<endl;
	cout<<"*************************************"<<endl;
	cab = new struct nodo();  // reserva espacio de memoria para almacenar información
	cout<< "Ingrese ID: ";
	cin >> cab->datos.id;
	cout<<"Ingrese genero de la persona H/M: ";
	cin>>cab->datos.genero;
	cout<<"Ingrese nombre de la persona: ";
	cin>>cab->datos.nombre;
	cout<<"Ingrese apellido de la persona: ";
	cin>>cab->datos.apellido;
	cout<<"Ingrese anio de nacimiento: ";
	cin>>anioN;
	cout<<"Ingrese mes de nacimiento: ";
	cin>>mesN;
	cout<<"Ingrese dia de nacimiento: ";
	cin>>diaN;


	if ( diaA < diaN  ) {
		//En caso de ser menor la fecha actual que el nacimiento
		diaA = diaA + 30; // Se le suma los 30 días (1 mes) a la fecha actual
		mesA = mesA - 1; // Se le resta un mes (30 días) al mes actual
		cab->datos.diaF =  diaA - diaN; //Se le resta fecha nacimiento al actual
	} else { //En caso de ser mayor la fecha actual que el nacimiento
		cab->datos.diaF =  diaA - diaN;
	} //Se le resta fecha nacimiento al actual

	if( mesA < mesN ) {
		//En caso de ser menor el mes actual que el nacimiento
		mesA = mesA + 12; // Se le suma los 12 meses (1 año) al mes actual
		anioA = anioA - 1 ; // Se le resta 1 año ( 12 meses) al año actual
		cab->datos.mesF = mesA - mesN; //Se le resta año nacimiento al actual
	} else { //En caso de ser mayor el mes actual que el nacimiento
		cab->datos.mesF = mesA - mesN;
	} //Se le resta año nacimiento al actual

	cab->datos.edad = anioA - anioN;



	ult = cab;  // asigna el apuntador ult al mismo lugar donde esta apuntando cab

	cout <<"¿Desea agregar otra persona? s/n: ";
	cin >> desea;
	system("cls");
	while(desea == 's' || desea == 'S') {

		anioN=0;
		mesN=0;
		diaN=0;
		cout<<"*************************************"<<endl;
		cout<<"------------NUEVA PERSONA------------"<<endl;
		cout<<"*************************************"<<endl;

		nuevo = new struct nodo(); //creando nodo nuevo
		cout<< "Ingrese ID: ";
		cin >> nuevo->datos.id;
		cout<<"Ingrese genero de la persona H/M: ";
		cin>>nuevo->datos.genero;
		cout<<"Ingrese nombre de la persona: ";
		cin>>nuevo->datos.nombre;
		cout<<"Ingrese apellido de la persona: ";
		cin>>nuevo->datos.apellido;
		cout<<"Ingrese anio de nacimiento: ";
		cin>>anioN;
		cout<<"Ingrese mes de nacimiento: ";
		cin>>mesN;
		cout<<"Ingrese dia de nacimiento: ";
		cin>>diaN;

		if ( diaA < diaN  ) {
			//En caso de ser menor la fecha actual que el nacimiento
			diaA = diaA + 30; // Se le suma los 30 días (1 mes) a la fecha actual
			mesA = mesA - 1; // Se le resta un mes (30 días) al mes actual
			nuevo->datos.diaF =  diaA - diaN; //Se le resta fecha nacimiento al actual
		} else { //En caso de ser mayor la fecha actual que el nacimiento
			nuevo->datos.diaF =  diaA - diaN;
		} //Se le resta fecha nacimiento al actual

		if( mesA < mesN ) {
			//En caso de ser menor el mes actual que el nacimiento
			mesA = mesA + 12; // Se le suma los 12 meses (1 año) al mes actual
			anioA = anioA - 1 ; // Se le resta 1 año ( 12 meses) al año actual
			nuevo->datos.mesF = mesA - mesN; //Se le resta año nacimiento al actual
		} else { //En caso de ser mayor el mes actual que el nacimiento
			nuevo->datos.mesF = mesA - mesN;
		} //Se le resta año nacimiento al actual

		nuevo->datos.edad=anioA-anioN;

		ult->siguiente = nuevo; // conecta los dos nodos creados
		ult = nuevo;  //moviendo el apuntador ult al lugar del apuntador nuevo

		cout <<"¿Desea agregar otra persona? s/n: ";
		cin >> desea;
		system("cls");
	}
	ult->siguiente = NULL;
	p=cab;

	do {
		system("cls");
		cout<<"-------------MENU------------"<<endl;
		cout<<"1. Mostrar lista"<<endl;
		cout<<"2. Filtrar por genero (H/M)"<<endl;
		cout<<"3. Filtrar por rango edad"<<endl;
		
		cout<<"4. Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>opc;

		p=cab;
		switch(opc) {
			case 1:
				cout<<"-----------La lista es-----------"<<endl;
				while(p != NULL) {
					cout <<"ID: "<< p->datos.id<<endl;
					cout<<"Nombre: "<<p->datos.nombre<<" "<<p->datos.apellido<<endl;
					cout<<"Genero: "<<p->datos.genero<<endl;
					cout<<"---------------------------"<<endl;
					p = p->siguiente;
				}
				system("pause");
				break;

			case 2:
				cout<<"*************************************"<<endl;
				cout<<"-----------Filtrar MUJERES-----------"<<endl;
				cout<<"*************************************"<<endl;
				while(p != NULL) {
					if(p->datos.genero == 'M') {
						cout <<"ID: "<< p->datos.id<<endl;
						cout<<"Nombre: "<<p->datos.nombre<<" "<<p->datos.apellido<<endl;
						cout<<"Edad: "<<p->datos.edad<<endl;
						cout<<"---------------------------"<<endl;
						p = p->siguiente;
					} else {
						p = p->siguiente;
					}
				}
				p=cab;
				cout<<"*************************************"<<endl;
				cout<<"-----------FILTRAR HOMBRES-----------"<<endl;
				cout<<"*************************************"<<endl;
				while(p != NULL) {
					if(p->datos.genero == 'H') {
						cout <<"ID: "<< p->datos.id<<endl;
						cout<<"Nombre: "<<p->datos.nombre<<" "<<p->datos.apellido<<endl;
						cout<<"Edad: "<<p->datos.edad<<endl;
						cout<<"---------------------------"<<endl;
						p = p->siguiente;
					} else {
						p = p->siguiente;
					}
				}
				system("pause");
				break;
			case 3:

				edadm=0;
				edadmx=0;
				cout<<"-----------Filtrar por edad-----------"<<endl;
				cout<<"Ingrese edad minima: ";
				cin>>edadm;
				cout<<"Ingrese edad maxima: ";
				cin>>edadmx;

				while(p != NULL) {
					if(p->datos.edad >= edadm && p->datos.edad <= edadmx) {
						cout<<"Edad: "<<p->datos.edad<<endl;
						cout<<"Meses: "<<p->datos.mesF<<". Dias: "<<p->datos.diaF<<endl;
						cout<<"Nombre: "<<p->datos.nombre<<" "<<p->datos.apellido<<endl;
						cout<<"Genero: "<<p->datos.genero<<endl;
						cout <<"ID: "<< p->datos.id<<endl;
						cout<<"---------------------------"<<endl;
						p = p->siguiente;
					} else {
						p = p->siguiente;
					}

				}
				system("pause");
				break;
	

		}

	} while(opc != 4);

}


