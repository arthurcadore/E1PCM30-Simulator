#include "main.h"

string AuxBit = "1";
string FAW = "0011011";
string FAWcomplete = AuxBit + FAW; 

int frameindex = 1; 
bool alignment = false; 

int main() {

    while(true){
        // import the frame
        string frame = importFrame("../transmission/pcm30_transmission_pipe");
        concatenator(frame);

        // align the frame
        if (!alignment){
        cout << "PCM 30 Frame not aligned, aligning..." << endl;
        alignment = aligner(frame, FAWcomplete);
        }else {
            cout << endl;
            cout << "###################################" << endl;
            cout << "Frame " << frameindex << " content: " << endl << endl;
            // check if the frame is a FAW frame by verifing if frame index is an odd number
            if (frameindex % 2 != 0){
                string frame = frameGetter(); 
               // cout << "This is a FAW frame: " << frame << endl;
                frameinterpreter(frame, true, alignment, FAWcomplete);

            }else{
                string frame = frameGetter(); 
             //   cout << "This is not a FAW frame: " << frame << endl;
                frameinterpreter(frame, false, alignment, FAWcomplete);
            }

            frameindex++;
        }
        // sleep for 125ms
        usleep(125000);
    }
}
