#include <iostream>
#include <cmath>
#include <iomanip>
double e = 0.1;
using namespace std;
void f(double x) {
    double term = 1, summ = 0;
    for (int k = 0; fabs(term) >= e; k++) {
        if (k != 0) {
            term *= -1 * x;
            term /= 2 * k * k + 2 * k;
        }
        else {
            term = -1 * x;
        }
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