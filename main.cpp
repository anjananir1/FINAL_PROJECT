// main.cpp
#include <iostream>
#include <limits>
#include <unistd.h>   // for getcwd
#include <climits>    // for PATH_MAX
#include "StockAnalyzer.h"

using namespace std;

// Displays the main menu options to the user
void showMenu() {
    cout << "\n---- BlackRock Stock Analyzer ----\n";
    cout << "1. Load Data\n";
    cout << "2. Average Closing Price\n";
    cout << "3. Show Line Graph\n";
    cout << "4. Search Closing Price by Date\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    StockAnalyzer analyzer;
    int option;
    string filename = "BLK.csv"; // CSV file containing stock data

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                analyzer.loadData(filename);
                break;
            case 2:
                analyzer.printAverageClosingPrice();
                break;
            case 3:
                analyzer.printClosingPriceGraph();
                break;
            case 4: {
                string date;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                analyzer.searchByDate(date);
                break;
            }
            case 5:
                cout << "Thanks for using BlackRock Stock Analyzer!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    } while (option != 5);

    return 0;
}
