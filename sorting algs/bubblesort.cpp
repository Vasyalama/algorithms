#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> & arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = 1; j < arr.size() - i; j++){
            if (arr[j - 1] > arr[j]){
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {2, 3, 1, 14, 7, 0, 4};
    cout << "input array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "sorted array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}