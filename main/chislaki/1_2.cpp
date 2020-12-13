#include <iostream>
#include <cmath>
#include <iomanip>
double e = 0.1;
using namespace std;
double f(double x) {
    double term = -1*x, summ = term;
    for (int k = 1; abs(term) >= e; k++) {
        term *= -1 * x;
        term /= (double)2 * k * k + (double)2 * k;
        summ += term;
    }
    return summ;
}
int main() {
    double n = 10;
    double a = 0, b = 10, h = (b-a)/n;
    cout << "\t" << setprecision(4) << setw(1) << "x\tf(x)" << endl;
    for (double x = a; x <= b; x += h)
        cout << "\t" << setprecision(4) << setw(1) << x << "\t" << f(x) << endl;
    return 0;
}