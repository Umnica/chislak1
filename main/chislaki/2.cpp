#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double H(double a, double b, const int n) {
	double h = (abs(b - a)) / (double)n;
	return h;
}

double f(double x) {
	return x * x;
}

double fDiff(double x) {
	return 2 * x;
}

double D(double x, double a, double b, double h) {
	if (x == a)
		return (f(x + h) - f(x)) / h;
	else if (x == b)
		return (f(x) - f(x - h)) / h;
	else
		return (f(x + h) - f(x - h)) / (2 * h);
}

double dis(double a, double b) {
	double c = abs(a - b);
	return c;
}

int main() {
	double a = -10;
	double b = 10;
	double n = 10;
	double h = H(a, b, n);

	cout << fixed << setprecision(4);
	cout << "x\t\tfDiff(x)\tD\t\t|D - fDiff|\n";
	for (double i = a; i <= b; i += h)
		cout << i << setw(15) << fDiff(i) << setw(15) << D(i, a, b, h) << setw(19) << dis(fDiff(i), D(i, a, b, h)) << "\n";
	return 0;
}