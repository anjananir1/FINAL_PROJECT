// StockAnalyzer.cpp
#include "StockAnalyzer.h"
#include <iomanip>
#include <cmath>
#include <unistd.h>
#include <limits.h>

// Helper function to trim whitespace and control characters
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \r\n\t");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \r\n\t");
    return str.substr(first, (last - first + 1));
}

void StockAnalyzer::loadData(string filename) {
    entries.clear();
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string date = trim(line.substr(0, commaPos));
            string closeStr = trim(line.substr(commaPos + 1));
            double close = stod(closeStr);
            entries.push_back({ date, close });
        }
    }
    file.close();

    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    cout << "Current Working Directory: " << cwd << endl;
    cout << "Loaded " << entries.size() << " stock entries.\n";
}

void StockAnalyzer::printAverageClosingPrice() {
    if (entries.empty()) {
        cout << "No data loaded.\n";
        return;
    }
    double sum = 0;
    for (auto& e : entries)
        sum += e.close;
    double average = sum / entries.size();
    cout << fixed << setprecision(3);
    cout << "Average Closing Price: $" << average << endl;
}

void StockAnalyzer::printClosingPriceGraph() {
    if (entries.empty()) {
        cout << "No data loaded.\n";
        return;
    }

    double maxClose = 0;
    for (auto& e : entries)
        if (e.close > maxClose)
            maxClose = e.close;

    cout << "\n--- Closing Price Line Graph ---\n";
    for (auto& e : entries) {
        int barLength = static_cast<int>((e.close / maxClose) * 50);
        cout << e.date << ": ";
        for (int i = 0; i < barLength; ++i)
            cout << "|";
        cout << " $" << fixed << setprecision(2) << e.close << endl;
    }
}

void StockAnalyzer::searchByDate(string targetDate) {
    if (entries.empty()) {
        cout << "No data loaded.\n";
        return;
    }
    bool found = false;
    for (auto& e : entries) {
        if (trim(e.date) == trim(targetDate)) {
            cout << "Closing price on " << e.date << ": $" << fixed << setprecision(2) << e.close << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Date not found." << endl;
    }
}

