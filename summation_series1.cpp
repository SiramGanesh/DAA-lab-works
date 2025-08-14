// Approach 1
// Time Complexity: O(n)
#include <iostream>
#include <cmath>
using namespace std;

double series_sum_iterative(double X, int n) {
    double sum = 0;
    double term = 1; // X^0
    for (int i = 0; i <= n; i++) {
        sum += term;
        term *= X; // Next power of X
    }
    return sum;
}

int main() {
    double X;
    int n;
    cout << "Enter X and n: ";
    cin >> X >> n;
    cout << "Sum = " << series_sum_iterative(X, n) << endl;
}
