#include <iostream> 
#include <string.h> 
#include <stdlib.h>
using namespace std;
void menu();
void verificar();
int main(){
	cout<<"Bienvenido: Programa que verifica si un correo electronico es correcto"<<endl;
	menu();
	system("PAUSE");
	return 0;
}
void menu(){
	verificar();
}
void verificar(){
	string correoi;
	int pal=0;
	int arroba=0;
	int tamanio=0;
	int error=0;
	int contArroba=0;
	int contPuntos=0;
	int posPuntos=0;
	
	cout<<"Ingrese correo a verificar: "<<endl;
	cin>>correoi;
	
	int cont1=0;
	while(cont1<correoi.size()){
		tamanio=tamanio+1;
		cont1++;
	}
	char correo[tamanio];
	int cont2=0;
	while(cont2<tamanio){
		correo[cont2]=correoi[cont2];
		cont2++;
	}

	int cont3=0;
	while(cont3<tamanio){
		if(pal==0 && correo[cont3]=='@'){
		cout<<"Error"<<endl;
		cout<<"No se permite arroba en la posicion: 0";
		  error=100;
		  break;
	}
	if(correo[cont3]=='@'){
	contArroba=cont3;	
	arroba=arroba+1;	
	}
	if(correo[cont3]=='.'){	
	posPuntos=cont3;
	contPuntos=contPuntos+1;
	}
	pal=pal+1;
		cont3++;
	}
	if(contPuntos>1){
	cout<<"Error"<<endl;
	cout<<"Existe mas de un punto en la posicion: "<<posPuntos<<endl;;
	
	}	
	if(arroba>1){
	cout<<"Error"<<endl;
	cout<<"Existe mas de un arroba en la posicion: "<<contArroba<<endl;
	
	}	
	else{
		int cont4=0;
		while(cont4<contArroba){
			if(correo[cont4]=='~'||correo[cont4]=='`'||correo[cont4]=='|'||correo[cont4]=='•'||correo[cont4]=='?'||correo[cont4]=='÷'||correo[cont4]=='×'||correo[cont4]=='¶'||correo[cont4]=='£'||correo[cont4]=='¢'||correo[cont4]==','||correo[cont4]==' '||correo[cont4]=='^'||correo[cont4]=='°'||correo[cont4]=='='||correo[cont4]=='{'||correo[cont4]=='}'||correo[cont4]=='%'||correo[cont4]=='©'||correo[cont4]=='®'||correo[cont4]=='™'||correo[cont4]=='<'||correo[cont4]=='>'||correo[cont4]=='#'||correo[cont4]=='$'||correo[cont4]=='&'||correo[cont4]=='+'||correo[cont4]=='/'||correo[cont4]=='*'||correo[cont4]==':'||correo[cont4]==';'||correo[cont4]=='!'){
	cout<<"Existe algun simbolo no permitido en la posicion: "<< cont4<<endl; 
	error=error+1;
		}
	cont4++;
	}
	
	int cont5=0;
	while(cont5<tamanio){
	if(error>0){
		break;
	}
	if(correo[tamanio-1]=='m'&&correo[tamanio-2]=='o'&& correo[tamanio-3]=='c'|| correo[tamanio-1]=='o'  && correo[tamanio-2]=='c' ){
		cout<<"Elcorreo ingresado "<<correoi<<" es correcto..."<<endl;
		break;
	}
	else{
	cout<<"Existe un error en el correo digite un dominio valido. Ejemplo:"<<endl;
	cout<<".com"<<endl;
	cout<<".co"<<endl;
	break;
	} 
	cont5++;	
	}
	}
	char opc;

	cout<<"Desea verificar otro correo s/n"<<endl;
	cin>>opc;
	if(opc == 's'){
		menu();
	}else{
	if(opc == 'n'){
	cout<<"Vuelva pronto..."<<endl;
	system("EXIT");}}
}
