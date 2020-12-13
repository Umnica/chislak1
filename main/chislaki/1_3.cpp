#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double e = 0.1;
const int n = 5;
double a = 0, b = 10;
int i, j, k;


double H(double a, double b, const int n) {
    double h = (abs(b - a)) / (double)n;
    return floor(h);
}


double y(double x) {
    double term = -1 * x, summ = term;
    for (k = 1; abs(term) >= e; k++) {
        term *= -1 * x;
        term /= (double)2 * k * k + (double)2 * k;
        summ += term;
    }
    return summ;
}


double L(double x, double* pointsX, double* pointsY) {
    double summ = 0;
    double term = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j != i) {
                term *= x - pointsX[j];
                term /= pointsX[i] - pointsX[j];
            }
        }
        summ += pointsY[i] * term;
        term = 1;
    }
    return summ;
}


double dis(double a, double b) {
    double c = abs(a - b);
    return c;
}


int main() {
    double h = H(a, b, n);

    double pointsX[n];
    double pointsY[n];

    i = 0;
    for (double x = a; x < b; x += h, i++) {
        pointsX[i] = x;
        pointsY[i] = y(x);
    }

    cout << setprecision(4) << setw(1) << "x\ty(x)" << "\tL\t|L - y(x)|" << endl;
    i = 0;
    for (double x = a; x < b; x += h, i++) {
        cout << setprecision(4) << setw(1) << x << "\t" << y(x) << "\t" << L(x, pointsX, pointsY) << "\t" << dis(L(x, pointsX, pointsY), y(x)) << endl;
        double m = x + h / 2;
        cout << setprecision(4) << setw(1) << m << "\t" << y(m) << "\t" << L(m, pointsX, pointsY) << "\t" << dis(L(m, pointsX, pointsY), y(m)) << endl;
    }
    return 0;
}