#include <iostream>

using namespace std;

int main(){
	int d=22;
	int numero[1]={d};
	int cuadrado;
	int digito;
	int suma;
	int cifras = 0;
	
	cuadrado= numero[1]*numero[1];
	cout<<cuadrado<<endl<<endl;
	
//	while(cuadrado!=0){
//	
//		digito = cuadrado%10;
//		cuadrado = cuadrado/10;
//	
//		cout<<digito<<endl;
//		
//	}

		
	while(cuadrado!=0){
		
		cuadrado/=10;
		cifras++;
	}
	
		cout<<"nuemero tiene "<<cifras<<" cifras"<<endl;
	
	while(cuadrado!=0){
	
		suma = suma + cuadrado%10;
		cuadrado = cuadrado/10;		
	}
	
		cout<<suma<<endl;
			
	int mediana;
	
	//if()
	
	return 0;
	
}