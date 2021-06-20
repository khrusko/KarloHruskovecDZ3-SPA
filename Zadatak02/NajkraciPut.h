#pragma once
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Tocka {
	int redak;
	int stupac;
	int udaljenost;
	Tocka(int r, int s, int u) : redak(r), stupac(s), udaljenost(u)
	{
	}

};

class NajkraciPut
{
private:
	static const unsigned int REDAKA = 21;
	static const unsigned int STUPACA = 41;

public:
	char Polje[REDAKA][STUPACA];
	void Upis(Tocka& A, Tocka& B);
	int Provjera(Tocka& A, Tocka& B);
	void napuniPolje(Tocka& A, Tocka& B);
	void iscrtaj(Tocka& A, Tocka& B, Tocka& C);
	int najbrziPut(Tocka& A, Tocka& B, Tocka& C);
};

