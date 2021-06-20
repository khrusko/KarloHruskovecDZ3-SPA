#pragma once 

#include "NajkraciPut.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<thread>
#include<ctime>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
void NajkraciPut::napuniPolje(Tocka& A, Tocka& B)
{
	for (int r = 1; r < REDAKA; r++) {

		for (int s = 1; s < STUPACA; s++) {
			if (r == A.redak && s == A.stupac)
				Polje[r][s] = 'A';
			else if (r == B.redak && s == B.stupac)
				Polje[r][s] = 'B';
			else
				Polje[r][s] = '-';
		}
	}
}

void NajkraciPut::iscrtaj(Tocka& A, Tocka& B, Tocka& C)
{
	for (int r = 1; r < REDAKA; r++) {
		for (int s = 1; s < STUPACA; s++)
			cout << Polje[r][s];
		cout << endl;
	}
	cout << endl;

}

void NajkraciPut::Upis(Tocka& A, Tocka& B)
{
	cout << "A redak: "; cin >> A.redak;
	cout << "A stupac: "; cin >> A.stupac;

	cout << "B redak: "; cin >> B.redak;
	cout << "B stupac: "; cin >> B.stupac;
}

int NajkraciPut::Provjera(Tocka& A, Tocka& B)
{
	/*Redak 1-20
	Stupac 1-40
	Provjera */

	if (A.redak < 1 || A.redak>20) {
		cout << "Krivi unos" << endl;
		return 1;
	}
	if (B.redak < 1 || B.redak>20) {
		cout << "Krivi unos" << endl;
		return 2;
	}
	if (A.stupac < 1 || A.stupac>40) {
		cout << "Krivi unos" << endl;
		return 3;
	}
	if (B.stupac < 1 || B.stupac>40) {
		cout << "Krivi unos" << endl;
		return 4;
	}
}

int NajkraciPut::najbrziPut(Tocka& A, Tocka& B, Tocka& C)
{
    Tocka pocetak(0,0,0);
    /*pocetak.redak = 0;
    pocetak.stupac = 0;
    pocetak.udaljenost = 0;*/

    bool posjeceno[REDAKA][STUPACA];
    for (int r = 0; r < REDAKA; r++) {
        for (int s = 0; s < STUPACA; s++)
        {
                posjeceno[r][s] = false;

            if (Polje[r][s] == 'A')
            {
                pocetak.stupac = s;
                pocetak.redak = r;
            }
        }
    }

    queue<Tocka> q;
    q.push(pocetak);
    //default
    posjeceno[pocetak.redak][pocetak.stupac] = true;
    while (!q.empty()) {
        Tocka p = q.front();
        q.pop();

    //Pronaden
        if (Polje[p.redak][p.stupac] == 'B')
            return p.udaljenost;

        //GT
        if (p.redak - 1 >= 0 &&
            posjeceno[p.redak - 1][p.stupac] == false) {
            q.push(Tocka(p.redak - 1, p.stupac, p.udaljenost + 1));
            posjeceno[p.redak - 1][p.stupac] = true;
            Polje[p.redak][p.stupac] = '*';
        }

        //DT
        if (p.redak + 1 < REDAKA &&
            posjeceno[p.redak + 1][p.stupac] == false) {
            q.push(Tocka(p.redak + 1, p.stupac, p.udaljenost + 1));
            posjeceno[p.redak + 1][p.stupac] = true;
            Polje[p.redak][p.stupac] = '*';
        }

        //LT
        if (p.stupac - 1 >= 0 &&
            posjeceno[p.redak][p.stupac - 1] == false) {
            q.push(Tocka(p.redak, p.stupac - 1, p.udaljenost + 1));
            posjeceno[p.redak][p.stupac - 1] = true;
            Polje[p.redak][p.stupac] = '*';
        }

        //RT
        if (p.stupac + 1 < STUPACA &&
            posjeceno[p.redak][p.stupac + 1] == false) {
            q.push(Tocka(p.redak, p.stupac + 1, p.udaljenost + 1));
            posjeceno[p.redak][p.stupac + 1] = true;
            Polje[p.redak][p.stupac] = '*';
        }
        Polje[A.redak ][A.stupac ] = 'A';
        Polje[B.redak ][B.stupac ] = 'B';
        iscrtaj(A,B,C);
        sleep_for(milliseconds(100));
        system("cls");
        
    }
    return 1;

}
