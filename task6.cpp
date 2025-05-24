#include <iostream>
#include <unordered_map>

using namespace std;

void LongestSequence(int arr[], int size){
    unordered_map<int, string> map;
    for (int i = 0; i < size; i++)
        map.insert({arr[i], ""});
    
    int len = 1;
    int compareLen = 1;
    
    int start = 0;
    
    for (int i = 0; i < size; i++){
        auto target = map.find(arr[i]);
        
        auto next = map.find(target->first + 1);
        while (next != map.end()){
            compareLen++;
            next = map.find(next->first + 1);
        }
        
        if (compareLen > len){
            len = compareLen;
            start = target->first;
        }
        compareLen = 1;
    }
    
    cout << "Longest sequence ";
    for (int i = start; i < start + len; i++)
        cout << i << " ";
    cout << "has length " << len << endl;
    
};

int main() {
    int arr[] = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    //vector<int> v =
    LongestSequence(arr, sizeof(arr) / sizeof(arr[0]));
    
    return 0;
}
