#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    return max(
        max(maxSubArraySum(arr, l, m),
        maxSubArraySum(arr, m + 1, h)),
        maxCrossingSum(arr, l, m, h)
    );

}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum Subarray Sum is " << max_sum << endl;
    return 0;
}
