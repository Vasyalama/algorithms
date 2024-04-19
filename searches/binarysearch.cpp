#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// binary search in sorted array
// returns true if target is in the array, otherwise false
bool binarySearch(vector<int>& arr, int target){
    int l = 0;
    int r = arr.size();
    while(l < r){
        int m = (l + r) / 2;
        if (arr[m] == target)
            return true;
        if (arr[m] < target)
            l = m + 1;
        else   // if (arr[m] > target)
            r = m;
    }

    return false;
}

// binary search for upperbound in sorted array
// return upperbound for given target element, if there is not palce for it returns size of array
int upperBound(vector<int>& arr, int target){
    int l = 0;
    int r = arr.size();
    while(l < r){
        int m = (l + r)/2;
        if (arr[m] <= target)
            l = m + 1;
        else // arr[m] > target
            r = m;
    }
    return l;
}

// binary search for lowerbound in sorted array
// return lowerbound for given target element, if there is not palce for it returns size of array
int lowerBound(vector<int>& arr, int target){
    int l = 0;
    int r = arr.size();
    while(l < r){
        int m = (l + r)/2;
        if (arr[m] < target)
            l = m + 1;
        else // arr[m] >= target
            r = m;
    }
    return l;
}

int main(){
    
    vector<int> a = {2, 4, 5, 5, 5, 37, 622, 76, 78};

    cout << "binary search" << endl;
    cout << "my implementation: " << binarySearch(a, 5) << " std::binary_search: " << std::binary_search(a.begin(), a.end(), 5) << endl;
    cout << "my implementation: " << binarySearch(a, 6) << " std::binary_search: " << std::binary_search(a.begin(), a.end(), 6) << endl;
    cout << "my implementation: " << binarySearch(a, 100) << " std::binary_search: " << std::binary_search(a.begin(), a.end(), 100) << endl;

    cout << "lower bound" << endl;
    cout << "my implementation: " << lowerBound(a, 5) << " std::lower_bound: " << std::lower_bound(a.begin(), a.end(), 5) - a.begin() << endl;
    cout << "my implementation: " << lowerBound(a, 6) << " std::lower_bound: " << std::lower_bound(a.begin(), a.end(), 6) - a.begin() << endl;
    cout << "my implementation: " << lowerBound(a, 100) << " std::lower_bound: " << std::lower_bound(a.begin(), a.end(), 100) - a.begin() << endl;

    cout << "upper bound" << endl;
    cout << "my implementation: " << upperBound(a, 5) << " std::upper_bound: " << std::upper_bound(a.begin(), a.end(), 5) - a.begin() << endl;
    cout << "my implementation: " << upperBound(a, 6) << " std::upper_bound: " << std::upper_bound(a.begin(), a.end(), 6) - a.begin() << endl;
    cout << "my implementation: " << upperBound(a, 100) << " std::upper_bound: " << std::upper_bound(a.begin(), a.end(), 100) - a.begin() << endl;

    return 0;
}