#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<thread>
#include "NajkraciPut.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


int main() {
	NajkraciPut Put;
	Tocka A(0, 0, 0);
	Tocka B(0, 0, 0);
	Tocka X(0, 0, 0);
	bool pogodak = false;

	Put.Upis(A, B);
	Put.Provjera(A, B);
	Put.napuniPolje(A, B);
	X = A;

	Put.iscrtaj(A, B, X);
	cout<<"Najbrzi put iznosi: "<<Put.najbrziPut(A, B, X)<<" celija"<<endl;

	return 0;
}