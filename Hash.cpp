#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

ofstream h;
int op;

class nodo{

public:

	int dato[1];
	nodo*siguiente;
	
		nodo(){
			
		}
		
		nodo(int d){
			dato[1]={d};
			siguiente=NULL;
		}	
		
	friend class tHash;
};

nodo arreglo[50];
int clave;

class tHash{
	
	public:
		
	int conversion(int clave, int tamano){
		
		clave*=clave;
		
		string digitos = to_string(clave);
		
		if(digitos.size() > 2)
			digitos = digitos.substr(1, digitos.size()-2);
			
			return stoi(digitos.c_str())%tamano;
		
	}
	
	void insertar(){

		int posicion;
		int tam=50;
		
		cout<<"\n\n\t\t\tIngrese una clave: ";
		cin>>clave;
			
			nodo*nuevo = new nodo();
			nuevo->dato[1]={clave};
			nuevo->siguiente = NULL;

			
			posicion=conversion(clave, tam);		
//			posicion= (pow(nuevo->dato[1],2))/2;
		
		//si esta vacio
		if(arreglo[posicion].siguiente==NULL)
			
			arreglo[posicion].siguiente = nuevo;
		
		else{
			
			nodo*aux = arreglo[posicion].siguiente;
				
				while(aux->siguiente != NULL)
					
					aux = aux -> siguiente;
				
				aux->siguiente = nuevo;
		}
		
		cout<<"\n\n\t\tLa clave fue alamcenada en la posicion: "<<posicion<<endl<<endl;
	}
	// fin de metodo de insercion
	
	void funcion(){
		
		int i = 0;
		int a;
		
		for(i; i<50; i++){
			
			nodo*aux = arreglo[i].siguiente;
			
			while(aux!=NULL){
				
				a=conversion(aux->dato[1],50);
				//a= (pow(aux->dato[1],2))/2;
				
				cout<<"\nEl resultado de elevar "<<aux->dato[1]<<" al cuadrado es:"<<pow(aux->dato[1],2)<<endl
					<<"y su(s) digito(s) central(es) es: "<<a<<endl;
					
				aux = aux->siguiente;
			}
		}
	}
	
	void ver(){
		
		int i=0;
		
		for(i; i<50; i++){
			
			cout<<"\t\tPosicion ["<<i<<"]: ";
			
			nodo*aux = arreglo[i].siguiente;
			
			while(aux!=NULL){
				
				cout<<aux->dato[1]<<" -> ";
				aux = aux->siguiente;
			}
			cout<<endl<<endl;
		}
		
		funcion();
	}
	
	void graficar(){
		
		h.open("Tabla_Hash.dot", ios::out);
	
			if(h.fail())
				cout<<"Ha ocurrido un error al crear el archivo";
	
			
				h<<"digraph G {"<<endl;
				h<<" nodesep=.05;"<<endl;
				h<<" rankdir=LR;"<<endl;
				h<<" node [shape=record,width=.1,height=.1];"<<endl;
				h<<" node [shape=squere]"<<endl;
	
				for(int i=0; i<50; i++){
			
					h<<i;
		
					if(arreglo[i].siguiente!=NULL)
						h<<"->";
	
					nodo *aux = arreglo[i].siguiente;
	
					while(aux!=NULL){
		
						h<<aux->dato[1];
				
						if(aux->siguiente!=NULL)
					
							h<<" -> ";
		
						aux = aux->siguiente;
					}
			
					h<<";";
					h<<endl;
				}
		
				h<<endl;
				h<<"}";
	
				h.close();
		
			system("dot -Tpng Tabla_Hash.dot > Tabla_Hash.png");
			system("Tabla_Hash.png");	
				
			}
};

void menu(){
	
	
	system("cls");
	cout<<"\n\t\t\t--T A B L A   D E   H A S H--";
	cout<<"\n\t   Tabla de Hash creada por medio de funcion cuadratica.";
	cout<<"\n\n\t\t  Selecciona las siguientes operaciones: ";
	cout<<"\n\n\t\t  [1] INSERTAR UN DATO";
	cout<<"\n\t\t  [2] VER DATOS";
	cout<<"\n\t\t  [3] VER EN GRAPHVIZ";
	cout<<"\n\t\t  [4] SALIR";
	cout<<"\n\n\t\t  Digita tu opcion: ";
	cin>>op;
	
}

int main(){

	tHash h;
	
	system("color 70");
	
	do{
		
		menu();
		
		switch(op){
			
			case 1: system("cls");
					cout<<"\n\t\t\t--T A B L A   D E   H A S H--";
					h.insertar();
					getch();
					break;
					
			case 2: system("cls");
					cout<<"\n\t\t\t--T A B L A   D E   H A S H--"<<endl<<endl;
					h.ver();
					getch();
					break;
					
			case 3: system("cls");
					cout<<"\n\t\t\t--T A B L A   D E   H A S H--";
					cout<<"\n\n\n\t\tSe esta creando el archivo";
					cout<<"\n\n\n\t\tPresiona cualquier tecla para ver la imagen.";
					cout<<endl<<"\n\t\tpromt...";
					h.graficar();
					getch();
					break;
		}
	}	
	while(op!=4);
	
	return 0;
	
}
