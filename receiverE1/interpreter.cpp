#include "interpreter.h"

int frameslot = 0; 

string bytesplitter(string &frame){
    // get 8 characters substring of the main string
    string byte = frame.substr(0, 8); 
    frame.erase(0, 8);
    return byte; 
}

void framesplitter(string frame, bool FawFrame){
    // split the PCM30 frame into its components 
    vector<string> frameComponents;
    for (int i = 0; i < 32; i++){
        frameComponents.push_back(bytesplitter(frame));
    }

    // print the frame components
    cout << "Frame components: " << endl;

    if(FawFrame){
        cout << "Frame Alignment Word: " << frameComponents[0] << endl;

        for (int i = 1; i < 15; i++){
            cout << "Data byte " << i << ": " << frameComponents[i] << endl;
        }
    }


}
