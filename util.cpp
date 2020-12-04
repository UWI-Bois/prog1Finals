//
// Created by ajays on 12/3/20.
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "util.h"

using namespace std;

void printStars (int numStars) {
    int i;

    for(i = 1; i<= numStars; i= i+1)
        cout << "*";

    cout << endl;
}

void printStars2 (int n) {
    int i;

    for (i=1; i<=n-1; i=i+1)
        cout << " ";

    cout << "*";
}

int menu () {
    /*  The following function generates the menu. Edit the menu options so that
        it displays the correct options for your program.
    */
    int choice;
    bool validChoice;

    validChoice = false;

    while (!validChoice) {
        cout << "  COMP 1601 - Two-Day Assessment: Program 2" << endl;
        cout << "  ================================================" << endl;
        cout << endl;
        cout << "                   M E N U" << endl;
        cout << endl;
        cout << "  1.  Highest/Lowest height of weather balloon." << endl;
        cout << "  2.  Check if height was increasing." << endl;
        cout << "  3.  On which hours was the height less than N?" << endl;
        cout << "  4.  Did the weather balloon reach this height?" << endl;
        cout << "  5.  Insert a new height of the weather balloon." << endl;
        cout << "  6.  Generate a graph showing height of weather balloon." << endl;
        cout << "  7.  Save data to a file." << endl;
        cout << "  8.  Quit" << endl;
        cout << endl;
        cout << "  Please choose an option or " << QUIT << " to quit: ";
        cin  >> choice;

        if (choice >= 1 && choice <= QUIT)	// QUIT is a constant; its use is optional.
            validChoice = true;
        else
            system("cls");					// useful way to clear the screen. Works on Windows only.
    }

    return choice;
}

int populateArrayFromFile(double arr[]) {
    // return max index (size - 1) of array if successful,
    // return -1 if fail reading file
    ifstream inf;
    inf.open(FNAME);
    if(!inf){
        cout << "error opening file: " << FNAME << endl;
        return -1;
    } else{
        cout << "success opening file: " << FNAME << endl;
    }
    // load data into array
    double openPrice;
    int i = 0;
    inf >> openPrice;
    while(openPrice != -1){
        arr[i++] = openPrice; // increment i after using it :)
        inf >> openPrice;
    }
    // arr[i] = 0; // cap off
    inf.close();
    return i;
}

void printDoubleArray(double arr[], int size) {
    // cout << "Open Prices for AAPL:\n";
    for (int i = 0; i  < size; ++i) {
        cout << arr[i] << endl;
    }
}

int makeOutFileFromArray(double arr[]){
    // return max index (size - 1) of array if successful,
    // return -1 if fail reading file
    ofstream outf;
    outf.open(ONAME);
    cout << outf.is_open() << endl;
    if(!outf){
        cout << "error opening file: " << FNAME << endl;
        return -1;
    } else{
        cout << "success opening file: " << FNAME << endl;
    }
    cout << "Edited Open Prices for AAPL:\n";
    for (int i = 0; i  < MAX_OPEN_PRICES; ++i) {
        outf << arr[i] << endl;
    }
    outf.close();
}

int getHighestIndexFromArray(double arr[], int size) {
    // option 1
    // returns index of the highest value
    double highest = 0;
    int idx = -1;
    for (int i = 0; i  < size; ++i) {
        if (arr[i] > highest){
            highest = arr[i];
            idx = i;
        }
    }
    cout << "highest found at i = " << idx
        << "  with value = " << highest << endl;
    return idx;
}

int getLowestIndexFromArray(double arr[], int size) {
    // option 1
    // returns index of the lowest value
    double lowest = HIGHEST;
    int idx = -1;
    for (int i = 0; i  < size; ++i) {
        if (arr[i] < lowest){
            lowest = arr[i];
            idx = i;
        }
    }
    cout << "lowest found at i = " << idx
         << "  with value = " << lowest << endl;
    return idx;
}

double getAverageOpenIndexFromArray(double arr[]){
    // option 1
    // returns avg of the sum value
    double sum = 0;
    for (int i = 0; i  < MAX_OPEN_PRICES; ++i) {
        sum += arr[i];
    }
    double avg = sum / MAX_OPEN_PRICES;
    cout << "avg = " << avg << endl;
    return avg;
}

int populateDisparities(double opens[], double arr[]){
    // return max index (size - 1) of array if successful,
    // return -1 if fail
    // opens[] = open_prices, arr[] = disparities
    /*
     * disparity = close - open
     * close = n+1
     * open = n
     */
    int idx = 0;
    for (int i = 0; i < MAX_OPEN_PRICES; ++i) {
        if(i < MAX_DISPARITIES){
            double open = opens[i];
            double close = opens[i+1];
            double disparity = close - open;
            if(disparity < 0){
                disparity *= -1.0;
            }
            arr[idx++] = disparity;
        } else {
            break;
        }
    }
    return idx;
}
