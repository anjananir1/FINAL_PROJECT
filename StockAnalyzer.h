// StockAnalyzer.h
#ifndef STOCK_ANALYZER_H
#define STOCK_ANALYZER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Represents one record of stock data with date and closing price
struct StockEntry {
    string date;      // Date in YYYY-MM-DD format
    double close;     // Closing price of the stock on that date
};

// Handles loading, analyzing, and displaying stock market data
class StockAnalyzer {
private:
    vector<StockEntry> entries;  // Stores all loaded stock entries

public:
    // Loads stock data from a CSV file
    void loadData(string filename);

    // Prints the average closing price across all entries
    void printAverageClosingPrice();

    // Prints a scaled terminal line graph of closing prices
    void printClosingPriceGraph();

    // Searches and prints the closing price for a given date
    void searchByDate(string targetDate);
};

#endif // STOCK_ANALYZER_H
