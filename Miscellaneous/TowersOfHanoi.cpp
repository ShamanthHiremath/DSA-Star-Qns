// #include <iostream>
#include<bits/stdc++.h>
using namespace std;
int i=0;
void moveDisk(int disk, char source, char destination) {
    i++;
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

void towersOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        moveDisk(1, source, destination);
        return;
    }
    // the ultimate goal is to move all the rings to destination using some or the other stack rod (auxillary)
    //u move the rings from source to destination using the auxillary
    towersOfHanoi(numDisks - 1, source, destination, auxiliary);
    //for every move u make from one rod to the other, print it
    moveDisk(numDisks, source, destination);
    //u move the move from auxillary to destination using source
    towersOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    towersOfHanoi(numDisks, 'A', 'B', 'C');
    cout<<"/n/nJOB DONE IN  "<<i<<"  MOVES i.e (2^n - 1) MOVES";

    return 0;
}
