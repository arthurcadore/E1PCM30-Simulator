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

    ofstream fifo("/tmp/pcm30_transmission_pipe", ios::out | ios::trunc);

    if (!fifo.is_open()) {
        cerr << "error opening the pipe" << endl;
        return;
    }
    
    fifo << frame << endl;

    fifo.close();
    return;
}

void writer(string frame, bool misalignment){

  if(misalignment)
    {
      // create a random binary string of variable length of 1 to 256 bits 

      string randomBinary;
      for (int i = 0; i < 256; i++){
          randomBinary += to_string(rand() % 2);
      }
       

    }
     concatenator(frame);



}