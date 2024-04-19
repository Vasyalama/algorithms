#include <iostream>
#include <vector>

using namespace std;

void shakerSort(vector<int> & arr){
    int lastSwap = 0;
    for (int i = 0; i < arr.size(); i++){
        int j = lastSwap;
        int swapcount = 0;
        if (i%2 == 0){
            j++;
            for (; j < arr.size(); j++){
                if (arr[j - 1] > arr[j]){
                    swap(arr[j - 1], arr[j]);
                    lastSwap = j - 1;
                    swapcount++;
                }
            }
        }
        else{
            for (; j > 0; j--){
                if (arr[j] < arr[j - 1]){
                    swap(arr[j], arr[j - 1]);
                    lastSwap = j;
                    swapcount++;
                }
            }
        }
        if (swapcount == 0){
            return;
        }
        cout << i << endl;
    }
}

int main(){
    
    vector<int> arr = {5, 4, 3, 2, 1, 0};
    cout << "input array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    shakerSort(arr);

    cout << "sorted array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}