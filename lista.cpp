#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

struct lista {
	char letra;
	struct lista *siguiente, *anterior;
};

typedef struct lista *Ppalindroma;

Ppalindroma nuevaLista(char j) {
	Ppalindroma nuevalista = new(struct lista);
	nuevalista->letra = j;
	nuevalista->anterior=NULL;
	return nuevalista;
}

char retornarPalabra(Ppalindroma &primera) {
	int u ;


	Ppalindroma ingreso;
	ingreso = primera ;
	u = ingreso->letra;
	primera = ingreso->siguiente ;
	ingreso->anterior=primera;
	delete(ingreso);
	return u;
}

void ingresarPalabra(Ppalindroma &primera, char j) {
	Ppalindroma ingreso = nuevaLista(j);
	ingreso->siguiente = primera;
	ingreso->anterior= ingreso;
	primera = ingreso;
}

void comprobarPalindromo( Ppalindroma &p, string lett) {
	Ppalindroma ingreso;


	for(int i=0; i<lett.size(); i++)

		if(lett[i]==32)
			lett.erase(i,1);

	for(int i=0; i<lett.size(); i++)

		ingresarPalabra(p, lett[i]);

	for(int i=0; i<lett.size(); i++) {
		ingreso = p;
		if(lett[i]== ingreso->letra)
			retornarPalabra( p );
		else
			break;
	}

	if(p==NULL)
		cout << "\n\t ****** USTED INGRESO UNA FRASE PALINDROMA ******" << endl;
	else
		cout << "\n\t ****** ERRONEO******\n ****** LA FRASE INGRESADA NO ES PALINDROMA ******" << endl;
}

void menu() {
	Ppalindroma lista = NULL;
	string lett;
	cout<<"--------------------------------"<<endl;
	cout<<"          BIENVENIDO            "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"********FRASE PALINDROMA********"<<endl;
	cout<<"--------------------------------"<<endl;
	
	cout << " Ingrese una frase: ";

	getline(cin, lett);
	comprobarPalindromo( lista, lett );
}
int main() {
	system("color F0");
	menu();
	system("pause");
	return 0;
}



