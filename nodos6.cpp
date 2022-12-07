#include <iostream>
using namespace std;
struct nodo {
	int exp, coe;
	struct nodo *sig, *ant;
};
void sumar(struct nodo *p);
void imprimir(struct nodo *p);


int main() {
	struct nodo *cab,*a,*n,*p; //apuntadores de trabajo
	int numT1=0,numT2=0;

	system("color F0");
	cout<<"--------------------------------"<<endl;
	cout<<"          BIENVENIDO            "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"**********LISTA DOBLES**********"<<endl;
	cout<<"**********4. SUMA DE POLINOMIOS**********"<<endl;
	
	system("PAUSE");
	system("cls");
	cout<<endl;

	cout<<"\n\tIngrese cuantos terminos tiene el 1er polinomio (No Mayor a 7): ";
	cin>>numT1;
	cout<<"\n\tIngrese el primer polinomio "<<endl;
	cout<<"\n\t Coeficiente: a, Exponente: b, Variable: x \n\t\t\t ax^{b}"<<endl;
	cab= new struct nodo();
	cout<<"Ingrese el coeficiente: ";
	cin>>cab->coe;
	cout<<"Ingrese el exponente: ";
	cin>>cab->exp;
	cab->ant=NULL;
	a=cab;


	while(numT1-1 > 0) {
		n = new struct nodo;
		a->sig=n;
		n->ant=a;
		a=n;
		cout<<"Ingrese el coeficiente: ";
		cin>>n->coe;
		cout<<"Ingrese el exponente: ";
		cin>>n->exp;
		p=a;
		numT1--;
	};

	system("pause");
	system("cls");
	cout<<"Ingrese cuantos terminos tiene el 2do polinomio (No Mayor a 6): ";
	cin>>numT2;
	cout<<"\n\tIngrese el 2do polinomio: "<<endl;
	cout<<"\n\t Coeficiente: a, Exponente: b, Variable: x \n\t\t\t ax^{b}"<<endl;
	while(numT2 > 0) {
		n = new struct nodo;
		a->sig=n;
		n->ant=a;
		a=n;
		cout<<"Ingrese el coeficiente: ";
		cin>>n->coe;
		cout<<"Ingrese el exponente: ";
		cin>>n->exp;
		p=a;
		numT2--;
	};

	n->sig=NULL;

	cout<<"\n\t LOS DOS POLINOMIOS SON: ";
	p=cab;
	imprimir(p);
	cout<<"\n\t LA SUMA ENTRE LOS DOS POLINOMIOS ES: ";
	p=cab;
	sumar(p);
	system("PAUSE");
	return 0;
}
void sumar(struct nodo *p) {
	int aux=0,aux1=0,aux2=0,aux3=0,aux4=0,aux5=0,aux6=0;
	while(p != NULL) {
		switch(p->exp) {
			case 0:
				aux+=p->coe;
				break;
			case 1:
				aux1+=p->coe;
				break;
			case 2:
				aux2+=p->coe;
				break;
			case 3:
				aux3+=p->coe;
				break;
			case 4:
				aux4+=p->coe;
				break;
			case 5:
				aux5+=p->coe;
				break;
			case 6:
				aux6+=p->coe;
				break;
		}
		p=p->sig;
	}
	cout<<"("<<aux6<<"x^6"<<") + ("<<aux5<<"x^5"<<") + ("<<aux4<<"x^4"<<") + ("<<aux3<<"x^3"<<") + ("<<aux2<<"x^2"<<") + ("<<aux1<<"x"<<") + ("<<aux<<")";
	cout<<endl;
}

void imprimir(struct nodo *p) {
	while(p != NULL) {
		cout<<"+"<<p->coe<<"x^"<<p->exp;
		p=p->sig;
	}
	cout<<endl;
}

