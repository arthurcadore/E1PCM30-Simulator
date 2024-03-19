#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

string bytesplitter(string &frame); 

void frameinterpreter(string frame, bool FawFrame);

#endif // INTERPRETER_H
