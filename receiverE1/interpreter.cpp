#include "interpreter.h"

string binaryToHex(const string &binary) {
    stringstream ss;
    ss << std::hex << std::setfill('0');
    
    // convert every 8 bits to a hex number
    for (size_t i = 0; i < binary.length(); i += 8) {
        string byte = binary.substr(i, 8); 
        int value = std::stoi(byte, nullptr, 2); 
        ss << setw(2) << value;
    }
    
    return ss.str();
}

string bytesplitter(string &frame){
    // get 8 characters substring of the main string
    string byte = frame.substr(0, 8); 
    frame.erase(0, 8);
    return byte; 
}

vector<string> slotsplitter(string &frame){
    // split the frame string of 8 bits into 2 strings of 4 bits 
    // store the 2 strings in a vector
    vector<string> slot;
    slot.push_back(frame.substr(0, 4));
    slot.push_back(frame.substr(4, 4));

    return slot;
}

int cyclechecker(int frameindex){
    // calculate cycle number 1 to 15 by using the frame index
    int cycleNumber = (frameindex % 15) + 1;

    // adjust the cycle number to be in the range 1 to 16
    if (cycleNumber == 16) {
        cycleNumber = 1;
    }

    return cycleNumber;
}
void sinalizationSlot(string &slot, int frameindex){

    int cycleNumber = cyclechecker(frameindex);

    cout << "Sinalization Slot " << cycleNumber << " " << endl;

    vector<string> slotComponents = slotsplitter(slot);

    cout << "Phone Channel " << cycleNumber << " : " << slotComponents[0] << endl;
    cout << "Phone Channel " << cycleNumber+15 << " : " << slotComponents[1] << endl;
}

void frameinterpreter(string frame, bool FawFrame, bool &alignment, string FAW, int frameindex){
    // split the PCM30 frame into its components 
    vector<string> frameComponents;
    for (int i = 0; i < 32; i++){
        frameComponents.push_back(bytesplitter(frame));
    }

    if(FawFrame){
        if (frameComponents[0] == FAW){
        cout << "Frame Alignment Word: " << frameComponents[0] << endl;
        }else {
            alignment = false;
            cout << "Frame not aligned, realigning..." << endl;
            return;
        }
    }else{  
        cout << "Service Word: " << frameComponents[0] << endl;
    }

    sinalizationSlot(frameComponents[16], frameindex);

    
    for (int i = 1; i < 16; i++){

        if (i < 9)
        {
        cout << "FS-" << "0" << i+1 << ": " << binaryToHex(frameComponents[i]) << " " << "|" << " ";
        }else 
        {
        cout << "FS-" << i+1 << ": " << binaryToHex(frameComponents[i]) << " " << "|" << " ";
        }
    }
    cout << endl;
    for (int i = 17; i < 32; i++){
        cout << "FS-" << i << ": " << binaryToHex(frameComponents[i]) << " " << "|" << " ";
    }
    cout << endl;
}
