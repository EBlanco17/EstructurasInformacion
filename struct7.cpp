#include <iostream>

#define TA 4

using namespace std;

struct estudiante {
	char nombre[30];
	char apellido[30];
	double nota1,nota2,nota3,autoe,coe,notafinal;
} datos[TA];

void ingresar(struct estudiante *datos);
void menu(struct estudiante *datos);
int main() {
	ingresar(datos);
	menu(datos);
	return 0;
}

void ingresar(struct estudiante *datos) {
	double n1,n2,n3,n4,n5;
	for(int i=0; i<TA; i++) {
		cout<<"---------------Datos del estudiante "<<i+1<<"---------------"<<endl;
		cout<<"Ingrese nombre del estudiante: ";
		cin>>datos[i].nombre;
		cout<<"Ingrese apellido del estudiante: ";
		cin>>datos[i].apellido;
		cout<<"Ingrese nota No.1 del estudiante: ";
		cin>>n1;
		if(n1 >= 0.0 && n1 <= 5.0) {
			datos[i].nota1 = n1;
		} else {
			cout<<"La nota ingresada es mayor a 5.0"<<endl;
			cout<<"Ingrese nota No.1 del estudiante: ";
			cin>>datos[i].nota1;
		}
		cout<<"Ingrese nota No.2 del estudiante: ";
		cin>>n2;
		if(n2 >= 0.0 && n2 <= 5.0) {
			datos[i].nota2 = n2;
		} else {
			cout<<"La nota ingresada es mayor a 5.0"<<endl;
			cout<<"Ingrese nota No.2 del estudiante: ";
			cin>>datos[i].nota2;
		}

		cout<<"Ingrese nota No.3 del estudiante: ";
		cin>>n3;
		if(n3 >= 0.0 && n3 <= 5.0) {
			datos[i].nota3 = n3;
		} else {
			cout<<"La nota ingresada es mayor a 5.0"<<endl;
			cout<<"Ingrese nota No.3 del estudiante: ";
			cin>>datos[i].nota3;
		}

		cout<<"Ingrese nota de auto-evaluacion del estudiante: ";
		cin>>n4;
		if(n4 >= 0.0 && n4 <= 5.0) {
			datos[i].autoe = n4;
		} else {
			cout<<"La nota ingresada es mayor a 5.0"<<endl;
			cout<<"Ingrese nota de auto-evaluacion del estudiante: ";
			cin>>datos[i].autoe;
		}

		cout<<"Ingrese nota de co-evaluacion del estudiante: ";
		cin>>n5;
		if(n5 >= 0.0 && n5 <= 5.0) {
			datos[i].coe = n5;
		} else {
			cout<<"La nota ingresada es mayor a 5.0"<<endl;
			cout<<"Ingrese nota de co-evaluacion del estudiante: ";
			cin>>datos[i].coe;
		}
//Calculo Nota Final
		datos[i].notafinal=(datos[i].nota1 + datos[i].nota2 + datos[i].nota3 + datos[i].autoe + datos[i].coe) / 5;
	}
}

void pasan(struct estudiante *datos);
void pierden(struct estudiante *datos);
void nSuperior(struct estudiante *datos);
void nIngresadas(struct estudiante *datos);

void menu(struct estudiante *datos) {
	short opcion;
	while(opcion!=5) {
		cout<<"-----------------------Menu-----------------------"<<endl;
		cout<<"1. Mostrar estudiantes que pasan"<<endl;
		cout<<"2. Mostrar estudiantes que pierden"<<endl;
		cout<<"3. Mostrar estudiantes con nota superior ingresada"<<endl;
		cout<<"4. Mostrar estudiantes entre dos notas ingresadas"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>opcion;
		switch(opcion) {
			case 1:
				pasan(datos);
				break;
			case 2:
				pierden(datos);
				break;
			case 3:
				nSuperior(datos);
				break;
			case 4:
				nIngresadas(datos);
				break;
			case 5:
				cout<<"*********************************"<<endl;
				cout<<"Vuelva Pronto..."<<endl;
				system("exit");
				break;
			default:
				cout<<"*********************************"<<endl;
				cout<<"Opcion incorrecta"<<endl;
				cout<<"*********************************"<<endl;
				break;


		}
	}
}

void pasan(struct estudiante *datos) {
	for(int i=0; i<TA; i++) {
		if(datos[i].notafinal>3.00) {
			cout<<"--------------------------------"<<endl;
			cout<<"Nombre: "<<datos[i].nombre<<endl;
			cout<<"Apellido: "<<datos[i].apellido<<endl;
			cout<<"Nota final: "<<datos[i].notafinal<<endl;
		} else {
			cout<<"--------------------------------"<<endl;
			cout<<"El estudiante "<<i+1<<" perdio."<<endl;
		}
	}
}
void pierden(struct estudiante *datos) {
	for(int i=0; i<TA; i++) {
		if(datos[i].notafinal<3.00) {
			cout<<"--------------------------------"<<endl;
			cout<<"Nombre: "<<datos[i].nombre<<endl;
			cout<<"Apellido: "<<datos[i].apellido<<endl;
			cout<<"Nota final: "<<datos[i].notafinal<<endl;
		} else {
			cout<<"--------------------------------"<<endl;
			cout<<"El estudiante "<<i+1<<" paso."<<endl;
		}
	}
}
void nSuperior(struct estudiante *datos) {
	float nota;
	cout<<"Ingrese nota: ";
	cin>>nota;
	for(int i=0; i<TA; i++) {
		if(datos[i].notafinal>nota) {
			cout<<"--------------------------------"<<endl;
			cout<<"Nombre: "<<datos[i].nombre<<endl;
			cout<<"Apellido: "<<datos[i].apellido<<endl;
			cout<<"Nota final: "<<datos[i].notafinal<<endl;
		} else {
			cout<<"--------------------------------"<<endl;
			cout<<"El estudiante "<<i+1<<" tiene la nota inferior a la ingresada."<<endl;
		}
	}
}
void nIngresadas(struct estudiante *datos) {
	float n1,n2;
	cout<<"Ingrese nota 1: ";
	cin>>n1;
	cout<<"Ingrese nota 2: ";
	cin>>n2;
	for(int i=0; i<TA; i++) {
		if(datos[i].notafinal>=n1 && datos[i].notafinal<=n2) {
			cout<<"--------------------------------"<<endl;
			cout<<"Nombre: "<<datos[i].nombre<<endl;
			cout<<"Apellido: "<<datos[i].apellido<<endl;
			cout<<"Nota final: "<<datos[i].notafinal<<endl;
		} else {
			cout<<"--------------------------------"<<endl;
			cout<<"El estudiante "<<i+1<<" tiene una nota mayor o menor a las ingresadas."<<endl;
		}
	}
}
