/*
  Created by Anton Ivanenko in October,2016
  Simulated Annealing Algorithm for solving Queen Problem
*/

#pragma once

//Create random positions of Queens
void RandomFillField (int[],const int);

//Looks for number of bad position and the worst position
int NumberBadPos (const int[], int, int &);

//Change two Queens: worst and random;
void RandomChangeTwoQueens(int[], const int, int);

//Copy our vector
void CopyVector(int[], int[],const int);

//Print our field as a matrix
void PrintField (int *, const int);

#endif
