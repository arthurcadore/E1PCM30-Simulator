#include "frameimporter.h"

// function to import a frame from a pipe, which is a string read from the pipe
string importFrame(const string& pipename) {
    ifstream pipe(pipename);
    if (!pipe.is_open()) {
        throw runtime_error("Could not open pipe");
    }

    // read the pipe into a single string
    string line;
    string content;
    while (getline(pipe, line)) {
        content += line;
    }

    // return the frame
    return content;
}