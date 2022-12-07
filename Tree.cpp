//Ejemplo de un arbol binario de busqueda, ordena alfabeticamente
#include <iostream>

using namespace std;

struct Node{
string data;
Node *left;
Node *right;
Node *parent;	
};

Node *tree = NULL;

//Funciones
void main1();
void readNode(Node *&tree, string n, Node *parent);
void printTree(Node *tree, int counter);
void eliminate(Node *tree, string n);
void removeNode(Node *deletedNode);
Node *deepestNode(Node *tree);
void destroyNode(Node *node);
void replace(Node *tree, Node *newNode);
int heightTree(Node *tree);
void preOrder(Node *tree);
void inOrder(Node *tree);
void postOrder(Node *tree);
bool search(Node *tree, string n);

int main(){
	system("color f0");
	cout<<"--------------------------------"<<endl;
	cout<<"          BIENVENIDO            "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"************ARBOLES************"<<endl;
	cout<<"--------------------------------"<<endl;
    
    system("pause");
	main1();
	return 0;
}

//Funcion de menu
void main1(){
	string data;
	int option, counter=0;
	int addition=0;
	system("cls");
	cout<<"Ingrese cuantos nodos desea insertar: ";
	cin>>option;
	do{
		cout<<"Ingrese una palabra: ";
				cin>>data;
				readNode(tree, data, NULL); //Insertar nuevo nodo
				cout<<endl;
				system("pause");
		option--;
	}while(option != 0);
	system("cls");
	do{
		cout<<"--------------------------------"<<endl;
    	cout<<"              MENU              "<<endl;
	    cout<<"--------------------------------"<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar arbol completo"<<endl;
		cout<<"3. Eliminar un nodo"<<endl;
		cout<<"4. Operaciones"<<endl;
		cout<<"5. Busqueda"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"\n\t Ingrese opcion: ";
		cin>>option;
		
		switch(option){
			case 1:
				cout<<"Ingrese una palabra: ";
				cin>>data;
				readNode(tree, data, NULL); //Insertar nuevo nodo
				cout<<endl;
				system("pause");
				break;
			case 2:
				cout<<"Mostrando arbol completo: \n\n";
				if(tree == NULL){
					cout<<"\n\t\tArbol Vacio!!!"<<endl;
				}else{
				printTree(tree, counter);	
				}
				cout<<endl;
				system("pause");
				break;
			case 3:
				cout<<"Eliminar nodo: "<<endl;
				cout<<"Ingrese la palabra a eliminar: ";
				cin>>data;
				eliminate(tree, data);
				cout<<"\n\t Nodo eliminado...";
				cout<<"\n\n";
				system("pause");
				break;
			case 4:
				cout<<"--------------------------------"<<endl;
    			cout<<"          OPERACIONES          "<<endl;
	   			cout<<"--------------------------------"<<endl;
				cout<<"1. Altura del arbol"<<endl;
				cout<<"2. Impresion PreOrden"<<endl;
				cout<<"3. Impresion InOrden"<<endl;
				cout<<"4. Impresion PostOrden"<<endl;
				cout<<"\n\t Ingrese opcion: ";
				
				cin>>option;
				switch(option){
					
					case 1:
						cout<<"Altura del arbol"<<endl;
						cout<<"La altura es: "<<heightTree(tree)+1;
						cout<<"\n\n";
						system("pause");
						break;
					case 2:
						cout<<"Impresion PreOrden"<<endl;
						preOrder(tree);
						cout<<"\n\n";
						system("pause");
						break;
					case 3:
						cout<<"Impresion InOrden"<<endl;
						inOrder(tree);
						cout<<"\n\n";
						system("pause");
						break;
					case 4:
						cout<<"Impresion PostOrden"<<endl;
						postOrder(tree);
						cout<<"\n\n";
						system("pause");
						break;
			
				}
				
				break;
				case 5:
						cout<<"Busqueda"<<endl;
						cout<<"Ingrese palabra a buscar: ";
						cin>>data;
						if(search(tree, data) == true){
						cout<<"\n\t"<<data<<" Ha sido encontrada en el arbol :)"<<endl;
						}else{
						cout<<"\n\t"<<" No se ha encontrado "<<data<< " en el arbol..."<<endl;
						}
						cout<<"\n\n";
						system("pause");
						break;
		}
		system("cls");
	}while(option != 6);
}


//Funcion para insertar elementos en el arbol
void readNode(Node *&tree, string n, Node *parent){
	string root; //valor de el nodo raiz
	if(tree == NULL){ //si el arbol esta vacio
	
	Node *new_node = new Node();
	new_node->data = n;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	tree = new_node;
	}
	else{ //condiciones para agregar el elemento 
		 root = tree->data;
		if(n < root){
			readNode(tree->left, n, tree);
		}else{
		    readNode(tree->right, n, tree);
		}
	}
}

//Muestra el arbol
void printTree(Node *tree, int counter){
	if(tree == NULL){
		return;
	}else{
		printTree(tree->right, counter+1);
		for(int i=0; i < counter; i++){
			cout<<"   :.  ";
		}
		cout<<tree->data<<endl;
		printTree(tree->left, counter+1);
	}
}

//Funcion eliminar nodo
void eliminate(Node *tree, string n){
	if(tree == NULL){
		return;
	}else if(n < tree->data){
		eliminate(tree->left, n);
	}
	else if(n > tree->data){
		eliminate(tree->right, n);
	}
	else{
		removeNode(tree);
	}
}

//Determina el nodo mas izquierdo
Node *deepestNode(Node *tree){
	if(tree == NULL){
		return NULL;
	}
	if(tree->left){
		return deepestNode(tree->left);
	}
	else{ //si no tiene nodo izq
		return tree; //retornar el mismo nodo
	}
}

//Reemplaza dos nodos
void replace(Node *tree, Node *newNode){
	if(tree->parent){
		//tree->parent asignarle su nuevo hijo
		if(tree->data == tree->parent->left->data){
			tree->parent->left = newNode;
		}
		else if(tree->data == tree->parent->right->data){
			tree->parent->right = newNode;
		}
	}
	if(newNode){
	//hijo asignarle su nuevo padre	
	newNode->parent = tree->parent;
	}
}

//Destruye un nodo
void destroyNode(Node *node){
	node->left = NULL;
	node->right = NULL;
	
	delete node;
}


//Elimina el nodo encontrado
void removeNode(Node *deletedNode){
	if(deletedNode->left && deletedNode->right){
		Node *deepest = deepestNode(deletedNode->right);
		deletedNode->data = deepest->data;
		removeNode(deepest);
	
	}
	else if(deletedNode->left){
		replace(deletedNode, deletedNode->left);
		destroyNode(deletedNode);
	}
	else if(deletedNode->right){
		replace(deletedNode, deletedNode->right);
		destroyNode(deletedNode);
	}
	else{//Nodo Hoja
		replace(deletedNode, NULL);
		destroyNode(deletedNode);
	}
}

int heightTree(Node *tree){
	int AltIzq, AltDer;

    if(tree == NULL){
    	return -1;	
	}
    else{
        AltIzq = heightTree(tree->left);
        AltDer = heightTree(tree->right);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

//Funcion recorrido en profundidad - preOrden
void preOrder(Node *tree){
	if(tree == NULL){
		return;
	}else{
		cout<<tree->data<<" -> ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

//Funcion recorrido en profundidad InOrden
void inOrder(Node *tree){
	if(tree == NULL){
		return;
	}else{
		inOrder(tree->left);
		cout<<tree->data<<" -> ";
		inOrder(tree->right);
	}
	
}

//Funcion recorrido en profundidad PostOrden
void postOrder(Node *tree){
	if(tree == NULL){
		return;
	}else{
		postOrder(tree->left);
		postOrder(tree->right);
		cout<<tree->data<<" -> ";
	}
}

//Funcion buscar elemento en arbol
bool search(Node *tree, string n){
if(tree == NULL){
	return false;
}else if(tree->data == n){
	return true;
}	
else if(n < tree->data){
	return search(tree->left, n);
}
else{
	return search(tree->right, n);
}
	
}

