#include "aligner.h"

string AuxBit = "0";
string FAW = "0011011";
string FAWcomplete = AuxBit + FAW; 
string jumboframe;
int alignIndex = 1;

// concatenator function to store the frame recived into final of jumboframe 
void concatenator(string frame)
{
    alignIndex++;
    jumboframe = jumboframe + frame;
}

// aligner function to align the jumboframe and extract the frames
// the aligner function find for the FAW in the jumboframe and count the number of bits before the FAW

bool finderFAW(){
    
    // find the FAWcomplete in the jumboframe and count the number of bits before the FAWcomplete
    int i = jumboframe.find(FAWcomplete);
    if (i == -1){
        return false;
    }
    else{
        // if the FAWcomplete is found, erase all the bits before the FAWcomplete. 
        jumboframe.erase(0, i);
        return true;
    }
}

// aligner main function 

bool aligner(string frame){

    // print the jumboframe length
    cout << "jumboframe length: " << jumboframe.length() << endl;

    if (alignIndex == 5){
        alignIndex = 0;
        return finderFAW();; 
    }

    return false; 
}

string frameGetter(){
    string frame = jumboframe.substr(0, 256);
    jumboframe.erase(0, 256);
    return frame;
}


