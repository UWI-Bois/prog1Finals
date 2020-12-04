// main.cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <itcl.h>
#include "util.h"
using namespace std;

int main () {
    double open_prices[MAX_OPEN_PRICES]; // from input file
    double entries[MAX_ENTRIES]; // for user entries
    double search_results[MAX_SEARCH_RESULTS]; // for search
    double disparities[MAX_DISPARITIES]; // all disparities

    double entry = 0;
    int made_entries = 0;

    int isOpenPrices = populateArrayFromFile(open_prices);

    if(isOpenPrices > 0){
        // printDoubleArray(open_prices);
        populateDisparities(open_prices, disparities);
//        printDoubleArray(disparities, MAX_DISPARITIES);

        getHighestIndexFromArray(open_prices, MAX_OPEN_PRICES);
        getLowestIndexFromArray(open_prices, MAX_OPEN_PRICES);
        getAverageOpenIndexFromArray(open_prices);
        getHighestIndexFromArray(disparities, MAX_DISPARITIES);
        getLowestIndexFromArray(disparities, MAX_DISPARITIES);


        while(entry != -1){
            cout << "enter val: ";
            cin >> entry;
            made_entries += addEntry(entry, entries);
        }
        cout << "made_entries = " << made_entries << endl;
        printDoubleArray(entries, made_entries);

    }

    return 0;
}
