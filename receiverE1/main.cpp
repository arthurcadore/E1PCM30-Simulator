#include "main.h"

int main() {
    vector<string> frame = importFrame("frame.txt");
    for (int i = 0; i < frame.size(); i++) {
        cout << frame[i] << endl;
    }
    return 0;
}