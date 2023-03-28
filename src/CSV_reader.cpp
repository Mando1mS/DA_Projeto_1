#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace  std;

vector<vector<string>> read_csv(const string& filename) {
    ifstream file(filename);
    vector<vector<string>> dataread;
    if (!file.is_open()) {
        cerr << "Couldn't open the file " << filename << endl;
        return dataread;
    }
    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;

        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
        dataread.push_back(row);
    }
    file.close();
    return dataread;
}
