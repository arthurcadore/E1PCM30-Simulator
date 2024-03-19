#include "main.h"
#include <unistd.h>

int frameindex = 0; 
bool alignment = false; 

int main() {

    for (int i = 0; i < 20; i++) {
        // import the frame
        string frame = importFrame(frameindex, "../examples/testTXcode.txt");

        // increment the frame index
        frameindex++;
        concatenator(frame);
        
        // align the frame
        if (!alignment){
        cout << "Frame not aligned" << endl;
        alignment = aligner(frame);
        }else {
            cout << "Frame Aligned" << endl;
            cout << "Frame: " << frameGetter() << endl;
        }
        // sleep for 1 second
        sleep(1);
    }
}
