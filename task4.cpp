#include <iostream>
using namespace std;

int Max(int arr[], int s){
    int maxM = 0;
    int max = 0;
    int min = 0;
    int minM = 0;
    
    for (int i = 0; i < s; i++){
        int n = arr[i];
        if (n > 0){
            if (n > maxM){
                max = maxM;
                maxM = n;
            }
            else{
                if (n > max) max = n;
            }
        }
        else{
            if (n < minM){
                min = minM;
                minM = n;
            }
            else{
                if (n < min) min = n;
            }
        }
    }
    
    maxM *= max;
    minM *= min;
    if (maxM > minM) return maxM;
    return minM;
};


int main() {
    int arr[] = {5, -10, -6, 9, 4};
    
    int n = Max(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "Largest Product: " << n << endl;
    return 0;
}
