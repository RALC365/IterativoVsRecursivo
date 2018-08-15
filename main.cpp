// Titulo: Recursivo vs Iterativo
//Serie de Fibonacci
//
// Proposito: crear un programa que genere una tabla de datos
//de los tics que toma la misma tarea, pero con algoritmos 
//diferentes y ver el más eficiente 
//
// Clase: CCC209 – Q3 – 2018
//
// Author: Richardson Cárcamo

#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;

std::vector<int> Iterativo;;
std::vector<int> Recursivo;

int FibonacciIterativo(int);

int FibonacciRecursivo(int , int, int);

int main(){
	std::ofstream fs("Iterativo_VS_Recursivo.xlsx"); 
	cout << "Iterativo Fibonacci: " << FibonacciIterativo(1000) << endl;
	
	cout << "Recursivo Fibonacci: " << FibonacciRecursivo(0, 1, 1000) << endl;
	
	fs << "Iterativo,Recursivo" << std::endl;
	int p = Iterativo.size();
	for(int i = 0; i < Iterativo.size(); i++){
		fs << Iterativo[i] << "," << Recursivo[i] << endl;
	}

	fs.close();
	return 0;
}


int FibonacciIterativo(int lim){
	static int ini, fin;
	int a = 0, b = 1, c = 0;
	for(int i = 0; i < lim ; i++){
		ini=clock();
		
		c = a + b;
		b = a;
		a = c;
		fin=clock();
		Iterativo.push_back(fin - ini);
	}
	return a;
}

int FibonacciRecursivo(int ant, int des, int lim){
	static int ini, fin;
	ini=clock();
	
	if(lim == 0){
		cout << endl;
		return ant + des;	
	}
	int c = ant + des; 
	c = FibonacciRecursivo(des, c, --lim);
	fin=clock();
	Recursivo.push_back(fin - ini);
	return c;
}