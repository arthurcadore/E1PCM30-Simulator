#include "main.h"

int frameindex = 1;

int main() {
  while(true){

    string newFrame; 
    // check if the frame is a FAW frame by verifing if frame index is an odd number  
    if (frameindex % 2 != 0){
      newFrame = createFrame(true);
    }else{
      newFrame = createFrame(false);
    }

    cout << "Frame " << frameindex << " content: " << endl << endl;
    cout << newFrame << endl;
    writer(newFrame);

    frameindex++;

    // sleep for 125ms
    usleep(125000);

    // after 22 frames, send a misalignment to simulate a misalignment problem 
    if (frameindex == 100){
      misalignment();
    }
  }
}