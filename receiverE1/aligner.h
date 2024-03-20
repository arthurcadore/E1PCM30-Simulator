#ifndef ALIGNER_H
#define ALIGNER_H

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void concatenator(string frame); 

bool finderFAW(string FAW);

bool aligner(string frame, string FAW);

string frameGetter();

void erasejumboframe();

void eraseindex();

#endif