#include <iostream>
#include <vector>
using namespace std;

void mergeArray(vector<int> & arr, int l, int m, int r){
    int len = m - l + 1;
    vector<int> lm(len);
    for (int i = 0; i < len; i++){
        lm[i] = arr[l + i];
    }
    int p1 = 0;
    int p2 = m + 1;
    int index = l;
    while(index <= r){
        if ((p1 < len && p2 <= r && lm[p1] <= arr[p2]) || (p1 < len && p2 > r)){
            arr[index++] = lm[p1++];
        }
        else if ((p1 < len && p2 <= r && lm[p1] > arr[p2]) || (p1 >= len && p2 <= r)){
            arr[index++] = arr[p2++];
        }
    }
}

void mergeSort(vector<int> & arr, int l, int r){
    if (l == r){
        return;
    }

    int m = (l + r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    mergeArray(arr, l, m, r);
}

int main(){
    vector<int> arr = {2, 3, 1, 14, 7, 0, 4};
    cout << "input array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "sorted array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}