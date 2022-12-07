#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#define p 20
using namespace std;
struct date {
	char dateF[10];
};
struct bank {
	struct date d;
	long long int accountNumber=0;
	long int valueT=0,fBalance=0;
	short int typeT;
} account[p];

void readData();
void sortTypeT();
void sortDate();
void sortAccountN();
void printBalance();
void printTypeT();
void printDate();
int main() {
	system("color f0");
	readData();
	return 0;
}
void readData() {

	char opc;
	short int op;

	for(int i=0; i<p; i++) {
		cout<<"-----Datos de transaccion  "<<i+1<<" --------"<<endl;
		cout<<"Ingrese numero de cuenta: ";
		cin>>account[i].accountNumber;
		cout<<"Ingrese fecha de transaccion (aa/mm/dd): ";
		cin>>account[i].d.dateF;
		cout<<"Ingrese tipo de transaccion: "<<endl;
		cout<<"1. Retiro "<<endl;
		cout<<"2. Consignacion "<<endl;
		cout<<"3. Pago "<<endl;
		cout<<"4. Traspaso "<<endl;
		cout<<"Ingrese el numero de tipo: ";
		cin>>account[i].typeT;
		cout<<"Ingrese valor de transaccion: ";
		cin>>account[i].valueT;
		cout<<"---------------------------------"<<endl;

	}

	do {
		cout<<"---------Menu----------"<<endl;
		cout<<"1. Saldo final por cuenta"<<endl;
		cout<<"2. Listar por tipo de transaccion "<<endl;
		cout<<"3. Organizar por fecha"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Ingrese opcion: ";
		cin>>op;

		switch(op) {
			case 1:
				cout<<"--------------------------"<<endl;
				cout<<" Saldo final por cuenta"<<endl;
				sortAccountN();
				printBalance();
				break;
			case 2:
				cout<<"--------------------------"<<endl;
				cout<<" Listar por tipo de transaccion "<<endl;
				sortTypeT();
				printTypeT();
				break;
			case 3:
				cout<<"--------------------------"<<endl;
				cout<<" Organizar por fecha"<<endl;
				sortDate();
				printDate();
				break;
			case 4:
				cout<<"--------------------------"<<endl;
				system("exit");
				break;
			default:
				cout<<"--------------------------"<<endl;
				cout<<"Error! "<<endl;
				break;

		}
		cout<<"Regresar al menu s/n: ";
		cin>>opc;
	} while(opc != 'n');
}
//Tipo
void sortTypeT() {
	struct bank aux;
	int change;
	for(int i=1; i<p; i++) {
		change=0;
		for(int j=p-1; j>=i; j--) {
			if(account[j-1].typeT>account[j].typeT) {
				aux=account[j];
				account[j]=account[j-1];
				account[j-1]=aux;
				change=1;
			}
		}
		if (change==0) break;
	}
}
//Fecha
void sortDate() {
	struct bank aux;
	int change=0;
	int temp;
	for(int i=1; i<p; i++) {
		for(int j=p-1; j>=i; j--) {
			temp=strcmp(account[j-1].d.dateF, account[j].d.dateF);
			if(temp>0) {
				aux=account[j];
				account[j]=account[j-1];
				account[j-1]=aux;
				change=1;
			}
		}
		if (change==0) break;
	}
}

//Nros. cuenta
void sortAccountN() {
	struct bank aux;
	int change;
	for(int i=1; i<p; i++) {
		change=0;
		for(int j=p-1; j>=i; j--) {
			if(account[j-1].accountNumber>account[j].accountNumber) {
				aux=account[j];
				account[j]=account[j-1];
				account[j-1]=aux;
				change=1;
			}
		}
		if (change==0) break;
	}
}

void printBalance() {
	long long int sum=0;
	for(int i=0; i<p; i++) {
		if(sum!=account[i].accountNumber) {
			cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;
			switch(account[i].typeT) {
				case 1:
					account[i].fBalance-= account[i].valueT;
					break;
				case 2:
					account[i].fBalance+= account[i].valueT;
					break;
				case 3:
					account[i].fBalance-= account[i].valueT;
					break;
				case 4:
					account[i].fBalance-= account[i].valueT;
					break;
				default:
					account[i].fBalance= account[i].valueT;
					break;

			}
			cout<<"Saldo Final: "<<account[i].fBalance<<endl;


			for (int j = 0; j < p; j++) {
				sum=account[i].accountNumber;
				if(account[i].accountNumber==account[j].accountNumber) {
					cout<<"*";
				}

			}
			cout<<endl;
		}
	}
}
void printDate() {
	for(int i=0; i<p; i++) {
		cout<<"----------------------------------"<<endl;
		cout<<"Fecha(aa/mm/dd) "<<account[i].d.dateF<<endl;
		cout<<"Tipo de Transaccion: "<<account[i].typeT<<endl;
		cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;

	}
}
void printTypeT() {
	for(int i=0; i<p; i++) {
		cout<<"----------------------------------"<<endl;
		switch(account[i].typeT) {
			case 1:
				cout<<"Tipo de Transaccion: 1. Retiro"<<endl;
				cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;
				cout<<"Fecha(aa/mm/dd) "<<account[i].d.dateF<<endl;

				break;
			case 2:
				cout<<"Tipo de Transaccion: 2. Consignacion"<<endl;
				cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;
				cout<<"Fecha(aa/mm/dd) "<<account[i].d.dateF<<endl;

				break;
			case 3:
				cout<<"Tipo de Transaccion: 3. Pago"<<endl;
				cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;
				cout<<"Fecha(aa/mm/dd) "<<account[i].d.dateF<<endl;

				break;
			case 4:
				cout<<"Tipo de Transaccion: 4. Traspaso"<<endl;
				cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;
				cout<<"Fecha(aa/mm/dd) "<<account[i].d.dateF<<endl;

				break;
			default:
				cout<<"Tipo de Transaccion: Ninguno"<<endl;
				cout<<"Numero de Cuenta: "<<account[i].accountNumber<<endl;
				cout<<"Fecha(aa/mm/dd) "<<account[i].d.dateF<<endl;

				break;
		}
	}
}
