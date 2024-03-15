#include "frameimporter.h"

// the import frame functions read line by line of the archive inputed. 
// each line has 256 bits of the frame in sequence. 
// the functions create a vector of strings, each string is a line of the frame.
// the vector is returned to the caller.

vector<string> importFrame(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw invalid_argument("File not found");
    }
    vector<string> frame;
    string line;
    while (getline(file, line)) {
        frame.push_back(line);
    }
    file.close();
    return frame;
}

