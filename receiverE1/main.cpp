#include "main.h"

int frameindex = 1; 
bool alignment = false; 

int main() {

    while(true){
        // import the frame
        string frame = importFrame("../transmission/pcm30_transmission_pipe");
        concatenator(frame);

        // align the frame
        if (!alignment){
        //cout << "Frame not aligned" << endl;
        alignment = aligner(frame);
        }else {
            cout << endl;
            cout << "###################################" << endl;
            cout << "Frame " << frameindex << " content: " << endl << endl;
            // check if the frame is a FAW frame by verifing if frame index is an odd number
            if (frameindex % 2 != 0){
                string frame = frameGetter(); 
               // cout << "This is a FAW frame: " << frame << endl;
                frameinterpreter(frame, true);

            }else{
                string frame = frameGetter(); 
             //   cout << "This is not a FAW frame: " << frame << endl;
                frameinterpreter(frame, false);
            }

            frameindex++;
        }
        // sleep for 125ms
        usleep(125000);
    }
}
