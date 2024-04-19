#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> & arr){
    for (int i = 0; i < arr.size(); i++){
        int min = arr[i];
        int indexToSwapWith = i;
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[j] < min){
                min = arr[j];
                indexToSwapWith = j;
            }
        }
        swap(arr[i], arr[indexToSwapWith]);
    }
}

int main(){
    vector<int> arr = {2, 3, 1, 14, 7, 0, 4};
    cout << "input array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "sorted array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}