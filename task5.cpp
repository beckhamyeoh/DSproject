#include <iostream>
using namespace std;

int main() {
    double arr[] = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int in[size];
    
    int max = 0;
    for (int i = 0; i < size; i++) {
        arr[i] *= 10;
        arr[i] -= 970;
        in[i] = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    int count[max + 1];
    for (int i = 0; i < max + 1; i++) count[i] = 0;
    
    for (int i = 0; i < size; i++){
        int j = in[i];
        count[j] += 1;
    }

    for (int i = 1; i < max + 1; i++) count[i] += count[i-1];
    
    double out[size];
    
    for (int i = size - 1; i >= 0; i--){
        int j = in[i];
        count[j] -= 1;
        out[count[j]] = j;
    }
    
    for (int i = 0; i < size; i++){
        out[i] += 970;
        out[i] /= 10.0;
        cout << out[i] << " ";
    }
    cout << endl;
    
    return 0;
}
