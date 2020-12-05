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
        cout << "  9.  Save data to a file." << endl;
        cout << "  10.  Quit" << endl;
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

int option7(double haystack[], int sizeHaystack, double needles[]){
    // search array
    cout << "-=-=-=You chose option 7!-=-=-=-" << endl;
    cout << "Search by Open Price, enter -1 to exit search feature :) " << endl;
    double searchVal = 0.0;
    int searchIndex = 0;
    while(searchVal != -1){
        cout << "Enter open price to search for (eg: 120): ";
        cin >> searchVal;
        searchIndex = getIndexesByValue(searchVal, haystack, sizeHaystack, needles);
        cout << "Entries found = " << searchIndex << endl;
        printDoubleArray(needles, searchIndex);
    }
    cout << SEP;
    pressEnterToContinue();
}
