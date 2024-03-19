#include "writer.h"

string jumboframe; 

// concatenator function to store the frame recived into final of jumboframe 
void concatenator(string frame){
    jumboframe = jumboframe + frame;
}


void writerpipe(string frame) {
    // Abre o pipe nomeado em modo de escrita e leitura
    ofstream fifo("pcm30_transmission_pipe", ios::out | ios::in);

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

void misalignment(){
    string random = randomstring();
    concatenator(random);
}

void writer(string frame){
    
    
    concatenator(frame);

    // write to pipe 256 bits of jumboframe and erase them from jumboframe
    if(jumboframe.length() >= 256){
        writerpipe(jumboframe.substr(0, 256));
        jumboframe.erase(0, 256);
    }
}