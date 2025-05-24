#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 7, 5, 8, 11, 2, 6, 50};
    
    int l = 0;
    int r = 0;
    
    int max = 0;
    int buy = 0;
    int sell = 0;
    
    int compareMax = 0;
    int compareBuy = 0;
    int compareSell = 0;
    
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++){
        l = arr[i];
        r = arr[i + 1];
        r -= l;
        if (r > 0){
            if (compareMax == 0) {
                compareMax = r;
                compareBuy = i;
                compareSell = i + 1;
            }
            else {
                compareMax += r;
                compareSell = i + 1;
            }
        }
        else{
            max = compareMax;
            compareMax = 0;
            buy = compareBuy;
            sell = compareSell;
        }
    }
    
    if (compareMax > max){
        max = compareMax;
        buy = compareBuy;
        sell = compareSell;
    }
    
    cout << "Max profit of $" << max << " if buy on day " << (buy + 1) << " and sell on day " << (sell + 1) << endl;
    
    return 0;
}
