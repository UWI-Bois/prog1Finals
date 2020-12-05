//
// Created by ajays on 12/3/20.
//
#include "util.h"

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
    for (int i = 0; i  < size; ++i) {
        cout << arr[i] << endl;
    }
}

void printIntArray(int arr[], int size) {
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

int getIndexesByValue(double needle, double *haystack, int sizeHaystack, int *needles){
    /*
     * if 0 is returned, then no results were found :)
     */
    int j = 0;
    for (int i = 0; i  < sizeHaystack; ++i) {
        if (haystack[i] == needle && j < MAX_SEARCH_RESULTS){
            needles[j++] = i;
        }
    }
    return j;
}

int addEntry(double val, double arr[]){
    int count = 0;
    for (int i = 0; i < MAX_ENTRIES; ++i) {
        if(arr[i] == -1){ // ENSURE TO INITIALIZE THE ARRAY WITH resetEntries()
            // cout << "addEntry[" << i << "] says: " << arr[i] << endl;
            arr[i] = val;
            count++;
            break; // break out of for loop
        }
        count++;
    }
    return count;
}

void pressEnterToContinue(){
    cout << "Press ENTER to continue... " << flush;
}

void resetSearches(int *searches){
    for (int i = 0; i < MAX_SEARCH_RESULTS; ++i) {
        searches[i] = -1;
    }
}
void resetEntries(double *entries){
    for (int i = 0; i < MAX_ENTRIES; ++i) {
        entries[i] = -1;
    }
}
