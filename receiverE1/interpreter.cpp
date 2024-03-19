#include "interpreter.h"

int frameslot = 0; 

string bytesplitter(string &frame){
    // get 8 characters substring of the main string
    string byte = frame.substr(0, 8); 
    frame.erase(0, 8);
    return byte; 
}

void frameinterpreter(string frame, bool FawFrame){
    // split the PCM30 frame into its components 
    vector<string> frameComponents;
    for (int i = 0; i < 32; i++){
        frameComponents.push_back(bytesplitter(frame));
    }

    if(FawFrame){
        cout << "Frame Alignment Word: " << frameComponents[0] << endl;
    }else{  
        cout << "Aux byte 1: " << frameComponents[0] << endl;
    }
    
    for (int i = 1; i < 16; i++){
        cout << "Frame Slot: " << i+1 << ": " << frameComponents[i] << endl;
    }

    cout << "Sinalization Slot: " << frameComponents[16] << endl;

    for (int i = 17; i < 32; i++){
        cout << "Frame Slot: " << i+1 << ": " << frameComponents[i] << endl;
    }
}
