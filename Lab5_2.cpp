#include <iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {

    if (low == high) {
        minVal = maxVal = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;

    int min1, max1, min2, max2;
    findMinMax(arr, low, mid, min1, max1);
    findMinMax(arr, mid + 1, high, min2, max2);

    minVal = (min1 < min2) ? min1 : min2;
    maxVal = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {10, 3, 45, 7, 23, 89, 2, 77};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal, maxVal;
    findMinMax(arr, 0, n - 1, minVal, maxVal);

    cout << "Smallest element: " << minVal << endl;
    cout << "Largest element: " << maxVal << endl;

    return 0;
}
