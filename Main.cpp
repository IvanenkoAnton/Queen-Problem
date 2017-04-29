/*
  Created by Anton Ivanenko in October,2016
  Simulated Annealing Algorithm for solving Queen Problem
*/


// main part, where the algorithm is situated

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Helpfunc.h"

/*size of board - N >= 8, #define RandomSize 8, if N<8, change #define RandomSize in Helpfunc.cpp*/
#define N 100 //size of the board
using namespace std;

int main() {

	srand(time(NULL));

	int VectField[N];
	int TempVectField[N];
	int E1, E2, delE, Worst, k;
    float MinTemp = 1e-60, MaxTemp = 15 , P, al;
	clock_t begtime, endtime;

	RandomFillField(VectField, N);
	cout << "Size of Board: " << N << endl;
	cout << "Number of bad positions: " << NumberBadPos(VectField, N, Worst) << endl;
	CopyVector(TempVectField, VectField, N);
	E1 = NumberBadPos(VectField, N, Worst);
	E2 = E1;
	begtime = clock() / CLOCKS_PER_SEC;

	for (int i = 0; i < 50; i++) {
		RandomChangeTwoQueens(TempVectField, N, Worst);
		delE = NumberBadPos(TempVectField, N, Worst);
		if (E2 < delE) {
			delE = E2;
			CopyVector(VectField, TempVectField, N);
		}
	}

	E2 = delE;
	delE = E1 - E2;
	MaxTemp = (double)delE / (-log(.75));

	cout << "MaxTemp: " << MaxTemp << endl;

	k = 1;
	while (MinTemp < MaxTemp) {

		for (int i = 0; i < 130; i++) {

			RandomChangeTwoQueens(TempVectField, N, Worst);
			E2 = NumberBadPos(TempVectField, N, Worst);
			if (E2 < E1) {
				E1 = E2;
				CopyVector(VectField, TempVectField, N);
			}
			else {
				P = exp((E1 - E2) / MaxTemp);
				al = (double)rand() / (RAND_MAX + 1);
				if (al < P) {
					E1 = E2;
					CopyVector(VectField, TempVectField, N);
				}
			}
		}

		if (E1 == 0) {
			break;
		}

		cout << "Number of bad positions: " << E1 << endl;
		MaxTemp *= 0.85 ;
		k++;
	}

	endtime = clock() / CLOCKS_PER_SEC;
	cout << "Number of bad positions: " << E1 << endl;
	cout << "Iter: " << k << endl;
	cout << "Time: " << endtime - begtime << " sec" << endl;
    PrintField(VectField, N);
	system("pause");
	return 0;
}
