#include <iostream>
#include <vector>

using namespace std;

int partition_LAMUTO(vector<int>& a, int q, int r) {
    int x = a[q];
    int p = q;
    int j = q + 1;
    while (j <= r) {
        if (a[j] >= x) {
            j++;
        }
        else if (a[j] <= x) {
            p++;
            swap(a[p], a[j]);
            j++;
        }
    }

    swap(a[q], a[p]);
    return p;
}

int partition_HOARE(vector<int>& a, int q, int r) {
    int x = a[q];
    int i = q - 1;
    int j = r + 1;
    while (true) {
        do {
            j--;
        } while (a[j] > x);

        do {
            i++;
        } while (a[i] < x);

        if (i < j) {
            swap(a[i], a[j]);
        }
        else {
            return j;
        }
    }

}


void quickSort(vector<int>& a, int q, int r) {
    if (q >= r) {
        return;
    }

    //int p = partition_LAMUTO(a, q, r);
    //quickSort(a, q, p - 1);
    //quickSort(a, p + 1, r);
    int p = partition_HOARE(a, q, r);
    quickSort(a, q, p);
    quickSort(a, p + 1, r);

}

int main() {
    vector<int> arr = { 2, 3, 1, 14, 7, 3, 0, 4 };
    cout << "input array: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "sorted array: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}