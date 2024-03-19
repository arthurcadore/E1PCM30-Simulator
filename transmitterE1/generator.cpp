

// Create a new PCM-30 frame using random data for the payload slots. 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

string AuxBit = "1";
string FAW = "0011011";
string FAWcomplete = AuxBit + FAW; 

string randomBinary(){
    string binary;
    for (int i = 0; i < 8; i++){
        binary += to_string(rand() % 2);
    }
    return binary;
}

string sinalization(){
    string binary;
    for (int i = 0; i < 8; i++){
        binary += to_string(rand() % 2);
    }
    return binary;
}

string auxbyte(){
    string binary;
    for (int i = 0; i < 8; i++){
        binary += to_string(rand() % 2);
    }
    return binary;
}

string createFrame(bool FAWframe){
    
    string frame; 

    if(FAWframe){
        frame += FAWcomplete;
    }else{
    frame += auxbyte();
    } 

    for (int i = 0; i < 15; i++){
        frame += randomBinary();
    }

    frame += sinalization();

    for (int i = 0; i < 15; i++){
        frame += randomBinary();
    }

    return frame;
}



