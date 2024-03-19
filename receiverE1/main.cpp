#include "main.h"
#include <unistd.h>

int frameindex = 0; 
bool alignment = false; 

int main() {

    for (int i = 0; i < 10; i++) {
        // import the frame
        string frame = importFrame(frameindex, "../examples/testTXcode.txt");

        frameindex++;

        // align the frame
        aligner(frame);

        // sleep for 1 second
        sleep(1);
    }
}
