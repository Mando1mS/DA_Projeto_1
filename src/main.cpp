#include <iostream>
#include "CSV_reader.cpp"

int main() {
    vector<vector<string>> data = csv_Reader("network.csv");
    for (const auto& row : data) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}