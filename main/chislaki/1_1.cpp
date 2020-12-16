#include <iostream>
#include <cmath>
#include <iomanip>
double e = 0.1;
using namespace std;
void f(double x) {
    double term = -1*x, summ = term;
    for (int k = 1; abs(term) >= e; k++) {
        term *= -1 * x;
        term /= (double)4 * k * k + (double)2 * k;
        summ += term;
        cout << setprecision(4) << "\t" << k << setw(20) << term << setw(20) << summ << endl;
    }
    cout << summ << endl;
}

int main() {
    cout << "\t" << "k" << setw(20) << "term" << setw(20) << "summ" << endl;
    double x = 10;
    f(x);
    return 0;
}
(2k+1)! = (2k+1)*(2k)*(2k-1)*(2k-2)*...*(k)*...*(1)
