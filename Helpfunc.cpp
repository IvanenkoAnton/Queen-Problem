/*
  Created by Anton Ivanenko in October,2016
  Simulated Annealing Algorithm for solving Queen Problem
*/

#include "Helpfunc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#define RandomSize 10 //has to be less,then boardsize

using namespace std;

void RandomFillField(int vector[], const int size) {

	int j;

	for (int i = 0; i < size; i++) {
		j = 0;
		vector[i] = rand() % (size);
		while (j < i ) {
			if (vector[i] == vector[j]) {
				vector[i] = rand() % (size);
				j = -1;
			}
			j++;
		}
	}
}

int NumberBadPos(const int vector[], int size, int &worst) {

	int BadPos = 0, Pos;
	int k, Max = 0;

	worst = 0;
	for (int i = 0; i < size; i++) {
		Pos = 0;
		k = 1;
		while ((i - k >= 0) && (vector[i] + k < size)) {
			if (vector[i - k] == (vector[i] + k)) {
				Pos++;
			}
			k++;
		}
		k = 1;
		while ((i + k < size) && (vector[i] - k >=0)) {
			if (vector[i + k] == (vector[i] - k)) {
				Pos++;
			}
			k++;
		}
		k = 1;
		while ((i - k >= 0) && (vector[i] - k >= 0)) {
			if (vector[i - k] == (vector[i] - k)) {
				Pos++;
			}
			k++;
		}
		k = 1;
		while ((i + k < size) && (vector[i] + k < size)) {
			if (vector[i + k] == (vector[i] + k)) {
				Pos++;
			}
			k++;
		}
		BadPos += Pos;
		if (Max < Pos) {
			Max = Pos;
			worst = i;
		}
	}
	return BadPos;
}

void RandomChangeTwoQueens(int vector[], const int size, int worst) {

	int temp;
	int randpos;

	while (true) {
		randpos = (size - 1) - rand() % (RandomSize);
		if (randpos != worst) {
			break;
		}
	}

	temp = vector[worst];
	vector[worst] = vector[randpos];
	vector[randpos] = temp;

}

void CopyVector(int Vect1[], int Vect2[],const int size) {

	for (int i = 0; i < size; i++) {
		Vect1[i] = Vect2[i];
	}
}

void PrintField(int *vect, const int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (vect[i] != j) {
				cout << "0 ";
			}
			else {
				cout << "1 ";
			}
		}
		cout << endl;
	}
}
