#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	system ("color f0");
const char CaracteresIndeseados[] = {' ','!','"','#','$','%','&','/','(',')',
'*','+',',','-','/',':',';','<','=','>','?','[','\ ',']','^','`','{','|','}' };
    
char email[35], *dominio[5] = {".net", ".com", ".es",".org",".co"};
    unsigned int i;
    int contador = 0, contador2 =0, contador3=0;
    char caracter='@';
    char punto='.';
    char raya='_';
    int verificador=0;
    
    
    cout<<"Ingrese la direccion de correo: "<<endl;
    cin>>email;
    
    
    //Buscamos en la cadena si hay presencia de @ o no
    //strchr se busca en el char el caracter seleccionado
     if(strchr(email, '@') != NULL){
         cout<<"Si hay arroba."<<endl;
     }
      else{
         
    cout<<"Correo invalido-No se encontro \'@'."<<endl;
    verificador=2;
	}
	
	
	//Buscamos en la cadena si hay presencia de los dominios o no
    //strchr se busca en el char el caracter seleccionado
    if(strstr(email,".com")){
	
   cout<<"Dominio CORRECTO: "<<dominio[1];
   cout<<""<<endl;

  	}else{
  		
	 if(strstr(email,".es")){
	
   cout<<"Dominio CORRECTO: "<<dominio[2];
   cout<<""<<endl;
 
	}else{
		
	 if(strstr(email,".net")){
	
   cout<<"Dominio CORRECTO: "<<dominio[0];
   cout<<""<<endl;
 
	}else{
		
	 if(strstr(email,".org")){
	
   cout<<"Dominio CORRECTO: "<<dominio[3];
   cout<<""<<endl;
 
	}else{
		
	 if(strstr(email,".co")){
	
   cout<<"Dominio CORRECTO: "<<dominio[4];
   cout<<""<<endl;
 
	}else{
	cout<<"No posee ningun dominio.\n";
	verificador=2;
}}}}}
    //Buscamos en la cadena si hay presencia de caracteres especiales o no
    //strlen da el tamaño de todo el correo
    for(int i = 0; i < strlen(email); i++){
    	 for (int j = 0; j < strlen(CaracteresIndeseados); j++){
    	 	 if (email[i] == CaracteresIndeseados[j]){
			 
			 cout<<"ingreso un caracter especial: "<<"' "<<CaracteresIndeseados[j]<<" '"<<" Error en el caracter: "<<i+1<<endl;
			 verificador=2;
		 }
	}}

	
    //Buscamos en la cadena si hay presencia de mas de un @ o no
    //agregamos contador para verificar la cantidad de @ dentro del email

	for(int i=0; i<email[i]; i++){
		if(email[i] == caracter){
			contador++;
				if (contador >=2){
				cout<<"El correo es incorrecto posee mas de un @ "<<"Error en el caracter: "<<i+1<<endl;
				verificador=2;
			}
			
		}
	} 
	
    //Buscamos en la cadena si hay presencia de mas de un . o no
    //agregamos contador para verificar la cantidad de . dentro del email
 	for(int i=0; i<email[i]; i++){
		if(email[i] == punto){
			contador2++;
				if (contador2 >=2){
				cout<<"El correo es incorrecto posee mas de un '.' "<<"Error en el caracter: "<<i+1<<endl;
				verificador=2;
			}
			
		}
	}	 
		for(int i=0; i<email[i]; i++){
		if(email[i] == raya){
			contador3++;
				if (contador3 >=2){
				cout<<"El correo es incorrecto posee mas de un '_' "<<"Error en el caracter: "<<i+1<<endl;
				verificador=2;
			}
			
		}
	}	 
   	//ya terminada toda la revision se da a conocer con el verificador si el correo escrito es correcto o no 
	if(verificador==2){
		cout<<"\n******CORREO INCORRECTO******\n";
	}
	if(verificador==0){
		cout<<"\n******CORREO CORRECTO******\n";
	}
	
	
	system("PAUSE");
	return 0;
}

