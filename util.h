//
// Created by ajays on 12/3/20.
//

#ifndef COMP1601_FINALS_UTIL_H
#define COMP1601_FINALS_UTIL_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

#define OPTION_QUIT 10 // useful constant
#define MAX_OPEN_PRICES 1258
#define MAX_DISPARITIES 629 // MAX_OPEN_PRICES/2
#define MAX_SEARCH_RESULTS 50
#define FNAME "inf.txt"
#define ONAME "outf.txt"
#define HIGHEST 999999

void printStars (int numStars);
void printStars2 (int n);
int menu ();
int populateArrayFromFile(double arr[]);
void printDoubleArray(double arr[], int size);
int makeOutFileFromArray(double arr[]);
int getHighestIndexFromArray(double arr[], int size);
int getLowestIndexFromArray(double arr[], int size);
double getAverageOpenIndexFromArray(double arr[]);
int populateDisparities(double opens[], double arr[]);
void printIntArray(int arr[], int size);
#endif //COMP1601_FINALS_UTIL_H
