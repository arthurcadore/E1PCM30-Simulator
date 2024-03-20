#include "main.h"

int frameindex = 1;
int randomframe = 20;

int main() {
  while(true){

    if(frameindex == randomframe){
      cout << endl << endl;
      cout << "##########################" << endl;
      cout << "Simulating misalignment..." << endl;
      frameindex = 1;
      misalignment();

      // create a new random frame index
      randomframe = rand() % 100 + 1;
      cout << "##########################" << endl;
      cout << "New random frame index: " << randomframe << endl;
      cout << endl << endl;
    }

    string newFrame; 
    // check if the frame is a FAW frame by verifing if frame index is an odd number  
    if (frameindex % 2 != 0){
      newFrame = createFrame(true);
      cout << "Frame " << frameindex << " with FAW: " << newFrame << endl;
    }else{
      newFrame = createFrame(false);
      cout << "Frame " << frameindex << " without FAW: " << newFrame << endl;
    }

    writer(newFrame);
    frameindex++;

    // sleep for 125ms
    usleep(125000);
  }
}