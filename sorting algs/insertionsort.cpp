#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int> & arr, int j, int i){
    for (int k = i; k > j; k--){
        swap(arr[k], arr[k - 1]);
    }
}

void insertionSort(vector<int> & arr){
    for (int i = 1; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            if (arr[j] > arr[i]){
                insert(arr, j, i);
                break;
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

    insertionSort(arr);

    cout << "sorted array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}