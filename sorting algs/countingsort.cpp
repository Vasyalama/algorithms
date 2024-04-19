#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(vector<int> & a, int r){
    vector<int> c(r + 1, 0);
    vector<int> sorted(a.size());
    for (int i = 0; i < a.size(); i++){
        c[a[i]]++;
    }

    for (int i = 1; i <= r; i++){
        c[i] += c[i - 1];
    }

    for (int i = a.size() - 1; i >= 0; i--){
        sorted[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    return sorted;
}



int main(){
    vector<int> arr = {0, 6, 6, 8, 1};
    vector<int> sortedArray = countingSort(arr, 8);
    
    cout << "input array: ";
    for (int elem : arr){
        cout << elem << " ";
    }
    cout << endl;
    cout << "sorted array: ";
    for (int elem : sortedArray){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}