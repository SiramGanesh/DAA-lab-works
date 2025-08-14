// approach 3
// Time complexity: O(1)
#include <iostream>
#include <cmath>
using namespace std;

double series_sum_formula(double X, int n) {
    if (X == 1)
        return n + 1;
    return (pow(X, n + 1) - 1) / (X - 1);
}

int main() {
    double X;
    int n;
    cout << "Enter X and n: ";
    cin >> X >> n;
    cout << "Sum = " << series_sum_formula(X, n) << endl;
}
