//2 matrices de 4x4 llenarlas (del 1 AL 16) impresion de la matriz, con recorrido
//imprimir en diagonal

#include <iostream>
#include <stdio.h>
using namespace std;
void ordendes();
void diagonal();
int main() {
	system ("color 70");
	cout<<"Impresion orden"<<endl;
	cout<<endl;
	ordendes();
	cout<<endl;
	cout<<endl;
	cout<<"Impresion diagonal"<<endl;
	cout<<endl;
	diagonal();
	return 0;
}
void ordendes() {
	int m[4][4]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	for(int j=0; j<1; j++) {

		for(int i=0; i<4; i++) {
			cout<<m[i][j]<<" ";
		}
	}
	cout<<endl;
	for(int j=1; j<2; j++) {

		for(int i=3; i>-1; i--) {
			cout<<m[i][j]<<" ";
		}
	}
	cout<<endl;
	for(int j=2; j<3; j++) {

		for(int i=0; i<4; i++) {
			cout<<m[i][j]<<" ";
		}
	}
	cout<<endl;
	for(int j=3; j<4; j++) {

		for(int i=3; i>-1; i--) {
			cout<<m[i][j]<<" ";
		}
	}

}
void diagonal() {
	int m[4][4]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	for(int j=0; j<1; j++) {

		for(int i=3; i<4; i++) {
			cout<<m[i][j]<<" ";
		}
	}
	cout<<endl;
	for(int j=0; j<1; j++) {

		for(int i=2; i<3; i++) {
			cout<<m[i][j]<<" ";
			cout<<m[i+1][j+1]<<" ";
		}
	}
	cout<<endl;
	for(int j=0; j<1; j++) {

		for(int i=1; i<2; i++) {
			cout<<m[i][j]<<" ";
			cout<<m[i+1][j+1]<< " ";
			cout<<m[i+2][j+2];
		}
	}
	cout<<endl;
	for(int j=0; j<1; j++) {

		for(int i=0; i<1; i++) {
			cout<<m[i][j]<<" ";
			cout<<m[i+1][j+1]<<" ";
			cout<<m[i+2][j+2]<<" ";
			cout<<m[i+3][j+3]<<" ";

		}
	}
	cout<<endl;
	for(int j=1; j<2; j++) {

		for(int i=0; i<1; i++) {
			cout<<m[i][j]<<" ";
			cout<<m[i+1][j+1]<<" ";
			cout<<m[i+2][j+2]<<" ";
		}
	}
	cout<<endl;
	for(int j=2; j<3; j++) {

		for(int i=0; i<1; i++) {
			cout<<m[i][j]<<" ";
			cout<<m[i+1][j+1]<<" ";
		}
	}
	cout<<endl;
	for(int j=3; j<4; j++) {

		for(int i=0; i<1; i++) {
			cout<<m[i][j]<<" ";
		}
	}


}
