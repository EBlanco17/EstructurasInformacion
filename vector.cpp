#include <stdio.h>
#include <iostream>
#define NS 30

using namespace std;
int main(){
	system ("color 04");
	
	int array[NS];
	int contador[NS] = {};
	int rep[NS] = {};
	int total[NS] = {};
	int i,j,aux,k=0;
	
	//Inicializar el array
	for (i = 1; i <= NS; i++) {
        array[i]=0;
    }
	
	//Ingreso de numeros
	cout<<"--------------Bienvenido----------"<<endl;
	
	for (i = 1; i <= NS; i++) {
        cout<< "Ingrese numero "<< i << " : ";
        cin>> array[i];
    }
    //ordena los numeros
    for (i = 1; i <= NS - 1; i++) {
        for (j = 1; j <= NS - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
	//Cuenta el numero de veces que se repite el numero
	for(i=1;i<=NS;i++){
		for(j=1;j<=NS;j++){
		if (array[i]==array[j]){
		contador[i]++;	
		}
	}
	}
	
	for(i=1;i<=NS;i++){
		if(array[i] != array[i-1]){
		rep[k] = array[i];
		total[k] = contador[i];
		k++;
		}
	}
	
	//Imprime la frecuencia
	cout<<endl;
	cout<<"Frecuencia"<<endl;
	for(i=0;i<k;i++){
	cout<<"el numero "<<rep[i]<<" se repite: ";
	for(int c=0;c<total[i];c++){
	cout<<"*";	
	}
	cout<<endl;
	}
	
	cout<<endl;
	
	system("PAUSE");
}
