#include <iostream>
using namespace std;

int main() {
    int array[] = {2, 3, 0, 6, 1, 5};
    
    int numOfInts = sizeof(array) / sizeof(array[0]);
    
    int sumOG = 0;
    for (int i = 0; i < numOfInts; i++) sumOG += array[i];
    
    int sumTotal = 0;
    for (int i = 1; i <= numOfInts; i++) sumTotal += i;
    
    cout << "Int missing: " << (sumTotal - sumOG) << endl;
    return 0;
}
