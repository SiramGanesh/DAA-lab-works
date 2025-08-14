// Approach 2 
// Time Complexity: O(log n)
#include <iostream>
using namespace std;

double power(double base, int exp) {
    double result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

double series_sum_log(double X, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0)
        return series_sum_log(X, n / 2) * (1 + power(X, n / 2 + 1));
    else
        return series_sum_log(X, n - 1) + power(X, n);
}

int main() {
    double X;
    int n;
    cout << "Enter X and n: ";
    cin >> X >> n;
    cout << "Sum = " << series_sum_log(X, n) << endl;
}
