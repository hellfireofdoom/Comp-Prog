#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // seed with the test number for reproducibility
    
    int w = rand() % 30 + 1; // random number from 1 to 30
    cout << w << endl;
}