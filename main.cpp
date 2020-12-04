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
    double added_data[MAX_DISPARITIES]; // for user entries
    double disparities[MAX_DISPARITIES];

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

    }

    return 0;
}
