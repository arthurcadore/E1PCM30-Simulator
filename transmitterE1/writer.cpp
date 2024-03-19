#include <iostream>
#include <fstream>
using namespace std;

string jumboframe; 

// concatenator function to store the frame recived into final of jumboframe 
void concatenator(string frame)
{
    jumboframe = jumboframe + frame;
}


void writerpipe(string frame) {

    ofstream fifo("../transmission/pcm30_transmission_pipe", ios::out | ios::trunc);

    if (!fifo.is_open()) {
        cerr << "error opening the pipe" << endl;
        return;
    }
    
    fifo << frame << endl;

    fifo.close();
    return;
}

string randomstring(){
    string str;

    int stringlength = rand() % 256 + 1;
    for (int i = 0; i < stringlength; i++) {
        int bit = rand() % 2;
        str += to_string(bit);
    }

    return str; 
}

void writer(string frame, bool misalignment){

  if(misalignment){
      string random = randomstring();
      concatenator(random);
    }
    
    concatenator(frame);

    // write to pipe 256 bits of jumboframe and erase them from jumboframe
    if(jumboframe.length() >= 256){
        writerpipe(jumboframe.substr(0, 256));
        jumboframe.erase(0, 256);
    }
}