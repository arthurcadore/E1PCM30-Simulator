#include "main.h"
#include <unistd.h>

int frameindex = 1; 
bool alignment = false; 

int main() {

    for (int i = 0; i < 20; i++) {
        // import the frame
        string frame = importFrame(i, "../examples/testTXcode.txt");
        concatenator(frame);

        // align the frame
        if (!alignment){
        cout << "Frame not aligned" << endl;
        alignment = aligner(frame);
        }else {
            cout << "Frame Aligned" << endl;
            // check if the frame is a FAW frame by verifing if frame index is an odd number
            if (frameindex % 2 != 0){
                cout << "This is a FAW frame: " << frameGetter() << endl;
                
            }
            cout << "This is not a FAW frame: " << frameGetter() << endl;
            frameindex++;
        }
        // sleep for 1 second
        sleep(1);
    }
}
