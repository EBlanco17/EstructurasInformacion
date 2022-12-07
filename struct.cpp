#include <iostream>
using namespace std;
struct datos {
	long id;
	string nombre;
	string apellido;
	short int edad;
	char genero;
} p1,p2,p3;
int main() {
	cout<<"Ingrese nombre primera persona: ";
	cin>>p1.nombre;
	cout<<"Ingrese apellido primera persona: ";
	cin>>p1.apellido;
	cout<<"Ingrese edad primera persona: ";
	cin>>p1.edad;
	cout<<"Ingrese genero primera persona: ";
	cin>>p1.genero;
	cout<<"Ingrese ID primera persona: ";
	cin>>p1.id;
	cout<<endl;
	cout<<"Ingrese nombre segunda persona: ";
	cin>>p2.nombre;
	cout<<"Ingrese apellido segunda persona: ";
	cin>>p2.apellido;
	cout<<"Ingrese edad segunda persona: ";
	cin>>p2.edad;
	cout<<"Ingrese genero segunda persona: ";
	cin>>p2.genero;
	cout<<"Ingrese ID segunda persona: ";
	cin>>p2.id;
	cout<<endl;
	cout<<"Ingrese nombre tercera persona: ";
	cin>>p3.nombre;
	cout<<"Ingrese apellido tercera persona: ";
	cin>>p3.apellido;
	cout<<"Ingrese edad tercera persona: ";
	cin>>p3.edad;
	cout<<"Ingrese genero tercera persona: ";
	cin>>p3.genero;
	cout<<"Ingrese ID tercera persona: ";
	cin>>p3.id;
	cout<<endl;

	if(p1.edad< p2.edad && p1.edad<p3.edad && p2.edad<p3.edad ) {
		cout<<p1.nombre<<" "<<p1.apellido<<" "<<p1.edad<<" "<<p1.genero<<" "<<p1.id<<endl;
		cout<<p2.nombre<<" "<<p2.apellido<<" "<<p2.edad<<" "<<p2.genero<<" "<<p2.id<<endl;
		cout<<p3.nombre<<" "<<p3.apellido<<" "<<p3.edad<<" "<<p3.genero<<" "<<p3.id<<endl;
	} else {
		if(p1.edad< p2.edad && p1.edad<p3.edad && p3.edad<p2.edad ) {
			cout<<p1.nombre<<" "<<p1.apellido<<" "<<p1.edad<<" "<<p1.genero<<" "<<p1.id<<endl;
			cout<<p3.nombre<<" "<<p3.apellido<<" "<<p3.edad<<" "<<p3.genero<<" "<<p3.id<<endl;
			cout<<p2.nombre<<" "<<p2.apellido<<" "<<p2.edad<<" "<<p2.genero<<" "<<p2.id<<endl;

		} else {
			if(p2.edad< p1.edad && p2.edad<p3.edad && p1.edad<p3.edad ) {
				cout<<p2.nombre<<" "<<p2.apellido<<" "<<p2.edad<<" "<<p2.genero<<" "<<p2.id<<endl;
				cout<<p1.nombre<<" "<<p1.apellido<<" "<<p1.edad<<" "<<p1.genero<<" "<<p1.id<<endl;
				cout<<p3.nombre<<" "<<p3.apellido<<" "<<p3.edad<<" "<<p3.genero<<" "<<p3.id<<endl;
			} else {
				if(p2.edad< p1.edad && p2.edad<p3.edad && p3.edad<p1.edad ) {
					cout<<p2.nombre<<" "<<p2.apellido<<" "<<p2.edad<<" "<<p2.genero<<" "<<p2.id<<endl;
					cout<<p3.nombre<<" "<<p3.apellido<<" "<<p3.edad<<" "<<p3.genero<<" "<<p3.id<<endl;
					cout<<p1.nombre<<" "<<p1.apellido<<" "<<p1.edad<<" "<<p1.genero<<" "<<p1.id<<endl;
				} else {
					if(p3.edad< p1.edad && p3.edad<p2.edad && p2.edad<p1.edad ) {
						cout<<p3.nombre<<" "<<p3.apellido<<" "<<p3.edad<<" "<<p3.genero<<" "<<p3.id<<endl;
						cout<<p2.nombre<<" "<<p2.apellido<<" "<<p2.edad<<" "<<p2.genero<<" "<<p2.id<<endl;
						cout<<p1.nombre<<" "<<p1.apellido<<" "<<p1.edad<<" "<<p1.genero<<" "<<p1.id<<endl;
					} else {
						if(p3.edad< p1.edad && p3.edad<p2.edad && p1.edad<p2.edad ) {
							cout<<p3.nombre<<" "<<p3.apellido<<" "<<p3.edad<<" "<<p3.genero<<" "<<p3.id<<endl;
							cout<<p1.nombre<<" "<<p1.apellido<<" "<<p1.edad<<" "<<p1.genero<<" "<<p1.id<<endl;
							cout<<p2.nombre<<" "<<p2.apellido<<" "<<p2.edad<<" "<<p2.genero<<" "<<p2.id<<endl;

						}
					}
				}
			}
		}
	}

}
