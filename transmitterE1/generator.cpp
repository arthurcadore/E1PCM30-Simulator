#include "generator.h"

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
    string binary = "11010100";
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



