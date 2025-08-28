#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(int arr[], int n) {

    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int bucketCount = maxVal - minVal + 1;  

    vector<vector<int>> buckets(bucketCount);

    for (int i = 0; i < n; i++) {
        buckets[arr[i] - minVal].push_back(arr[i]);
    }

    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}