//
// Created by ajays on 12/4/20.
//

#ifndef COMP1601_FINALS_MENU_H
#define COMP1601_FINALS_MENU_H
#include "util.h"
using namespace std;

// options
#define OPTION_HIGHEST_OPEN 1
#define OPTION_LOWEST_OPEN 2
#define OPTION_AVG_OPEN 3
#define OPTION_HIGHEST_DISPARITY 4
#define OPTION_LOWEST_DISPARITY 5
#define OPTION_GRAPH 6
#define OPTION_SEARCH 7
#define OPTION_UPDATE 8
#define OPTION_ADD_ENTRY 9
#define OPTION_SAVE 10
#define OPTION_QUIT 11
// globals
#define SEP "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"

// functions protos
int menu ();
int option1(double arr[], int size);
int option2(double arr[], int size);
int option3(double arr[]);
int option4(double arr[], int size);
int option5(double arr[], int size);
int option6(double arr[], int size);
int option7(double haystack[], int sizeHaystack, int *needles);
int option8(int sizeHaystack, int needles[], double disparities[], double haystack[]);
int option10(double *opens, double *entries, double *disparities, int numEntries);
int option9(double *entries);
#endif //COMP1601_FINALS_MENU_H
