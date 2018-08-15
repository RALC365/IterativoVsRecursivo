#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//ofstream fs("Iterativo_VS_Recursivo.xlsx"); 
vector<int> Iterativo;;
vector<int> Recursivo;

int FibonacciIterativo(int);

int FibbonacciRecursivo(int , int, int);

int main(){
	ofstream fs("Iterativo_VS_Recursivo.xlsx"); 
	cout << "Iterativo Fibbonacci: " << FibonacciIterativo(1000) << endl;
	
	cout << "Recursivo Fibbonacci: " << FibbonacciRecursivo(0, 1, 1000) << endl;
	
	fs << "Iterativo,Recursivo" << endl;
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

int FibbonacciRecursivo(int ant, int des, int lim){
	static int ini, fin;
	ini=clock();
	
	if(lim == 0){
		cout << endl;
		return ant + des;	
	}
	int c = ant + des; 
	c = FibbonacciRecursivo(des, c, --lim);
	fin=clock();
	Recursivo.push_back(fin - ini);
	return c;
}