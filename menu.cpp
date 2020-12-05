//
// Created by ajays on 12/4/20.
//

#include "menu.h"
#include "util.h"

int menu () {
    /*  The following function generates the menu. Edit the menu options so that
        it displays the correct options for your program.
    */
    //system("cls");
    system("clear");
    int choice;
    bool validChoice;

    validChoice = false;

    while (!validChoice) {
        cout << "  COMP 1601 - Two-Day Assessment: Apple Stocks" << endl;
        cout << "  ================================================" << endl;
        cout << endl;
        cout << "                   M E N U" << endl;
        cout << endl;
        cout << "  1.  Highest Open Price." << endl;
        cout << "  2.  Lowest Open Price." << endl;
        cout << "  3.  Average Open Price" << endl;
        cout << "  4.  Highest Disparity" << endl;
        cout << "  5.  Lowest Disparity." << endl;
        cout << "  6.  Graph showing open prices over a given range." << endl;
        cout << "  7.  Search for an entry(s)." << endl;
        cout << "  8.  Update entry by open price." << endl;
        cout << "  9.  Add data to dataset." << endl;
        cout << "  10.  Save data to a file." << endl;
        cout << "  11.  Quit" << endl;
        cout << endl;
        cout << "  Please choose an option or " << OPTION_QUIT << " to quit: ";
        cin  >> choice;

        if (choice >= 1 && choice <= OPTION_QUIT) {
            validChoice = true;
        } else{
            //system("cls");
            system("clear");
        }

    }

    return choice;
}

int option1(double arr[], int size){
    // highest open
    cout << "-=-=-=You chose option 1!-=-=-=-" << endl;
    cout << "The highest Open Price: " << endl;
    getHighestIndexFromArray(arr, size);
    cout << SEP;
    pressEnterToContinue();
}

int option2(double arr[], int size){
    // lowest open
    cout << "-=-=-=You chose option 2!-=-=-=-" << endl;
    cout << "The lowest Open Price: " << endl;
    getLowestIndexFromArray(arr, size);
    cout << SEP;
    pressEnterToContinue();
}

int option3(double arr[]){
    // avg open
    cout << "-=-=-=You chose option 3!-=-=-=-" << endl;
    cout << "The Average Open Price: " << endl;
    getAverageOpenIndexFromArray(arr);
    cout << SEP;
    pressEnterToContinue();
}

int option4(double arr[], int size){
    // lowest open
    cout << "-=-=-=You chose option 4!-=-=-=-" << endl;
    cout << "The Highest Disparity: " << endl;
    getHighestIndexFromArray(arr, size);
    cout << SEP;
    pressEnterToContinue();
}

int option5(double arr[], int size){
    // lowest open
    cout << "-=-=-=You chose option 5!-=-=-=-" << endl;
    cout << "The Lowest Disparity: " << endl;
    getLowestIndexFromArray(arr, size);
    cout << SEP;
    pressEnterToContinue();
}

int option6(double arr[], int size){
    // lowest open
    cout << "-=-=-=You chose option 6!-=-=-=-" << endl;
    cout << "Graph showing range: " << endl;
    // call soln function here
    cout << SEP;
    pressEnterToContinue();
}

int option7(double haystack[], int sizeHaystack, int *needles){
    // search array
    /*
     * haystack = the data array to query
     * sizeHaystack = size of dataset
     * needles = search results
     */
    cout << "-=-=-=You chose option 7!-=-=-=-" << endl;
    cout << "Search by Open Price, enter -1 to exit search feature :) " << endl;
    double searchVal = 0.0;
    int searchIndex = 0;
    while(searchVal != -1){
        cout << "Enter open price to search for (eg: 120): ";
        cin >> searchVal;
        searchIndex = getIndexesByValue(searchVal, haystack, sizeHaystack, needles);
        cout << "Entries found = " << searchIndex << endl;
        printIntArray(needles, searchIndex);
        resetSearches(needles);
    }
    cout << SEP;
    pressEnterToContinue();
}

int option8(int sizeHaystack, int needles[], double disparities[], double haystack[]) {
    // update entries in array based on searched value
    /*
     * haystack = the dataset array to query
     * sizeHaystack = size of dataset
     * needles = search results
     */
    cout << "-=-=-=You chose option 8!-=-=-=-" << endl;
    cout << "UPDATE all entries by Open Price, enter -1 to exit update feature :) " << endl;
    double searchVal = 0, updateVal = 0;
    int searchIndex = 0;
    while(searchVal != -1){
        cout << "Enter open price to search for (eg: 120) OR -1 to exit: ";
        cin >> searchVal;
        if(searchVal == -1){
            break;
        }
        cout << "Enter open price to update (eg: 120): ";
        cin >> updateVal;
        searchIndex = getIndexesByValue(searchVal, haystack, sizeHaystack, needles);
        if(searchIndex > 0){
            cout << "Entries found = " << searchIndex << endl;
            printIntArray(needles, searchIndex);
            cout << "results found, updating values..." << endl;
            for (int i = 0; i < searchIndex; ++i) { // update entries
                int needleVal = needles[i];
                haystack[needleVal] = updateVal;
                cout << "updating haystack[" << needleVal << "] -> " << updateVal << endl;
            }
            populateDisparities(haystack, disparities);
            resetSearches(needles);
        } else{
            cout << "no entries found :(" << endl;
        }
    }
    cout << SEP;
    pressEnterToContinue();
}

int option10(double *opens, double *entries, double *disparities, int numEntries) {
    cout << "You have chosen option 10 -> save data to file!" << endl;
    ofstream outf;
    outf.open(ONAME);
    cout << outf.is_open() << endl;
    if(!outf){
        cout << "error opening file: " << ONAME << endl;
        return -1;
    } else{
        cout << "success opening file: " << ONAME << endl;
    }
    // print opens to file
    outf << "=-=-=- Open Prices for AAPL (2012-2017) -=-=-=\n";
    for (int i = 0; i  < MAX_OPEN_PRICES; ++i) {
        outf << opens[i] << endl;
    }
    // print custom entries to file
    outf << "=-=-=- User entries -=-=-=\n";
    for (int i = 0; i  < numEntries; ++i) {
        outf << entries[i] << endl;
    }
    // print disparities to file
    outf << "=-=-=- DISPARITIES -=-=-=\n";
    for (int i = 0; i  < MAX_DISPARITIES; ++i) {
        outf << disparities[i] << endl;
    }
    outf.close();
}

int option9(double *entries) {
    cout << "You have chosen option 9!" << endl;
    cout << "Make up to 50 valid open price entries!" << endl;
    double entry = 0;
    int numEntries = 0;
    while(entry != -1){
        cout << "enter a value to input (eg 120) OR -1 to exit: ";
        cin >> entry;
        if(entry == -1){
            break;
        }
        numEntries = addEntry(entry, entries);
    }
    cout << "Here are the entries you made thus far: " << endl;
    printDoubleArray(entries, numEntries);
    return numEntries;
}
