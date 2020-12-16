#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double e = 0.001;

// фун дистанции
double dis(double a, double b) {
	double c = abs(a - b);
	return c;
}


// фун шага 
double H(double a, double b, int n) {
	double h = (abs(b - a)) / (double)n;
	return h;
}


// просто функция 
double f(double x) { return pow(x, 2); }


// левый прямоугольник
double lP(double a, double b, double n) {
	double h = H(a, b, n);
	double s = 0;
	for (double i = 0; i < n; i++)
		s += f(a + (i * h));
	return h * s;
}


// метод симпосона 
double simpson(double a, double b, double n) {
	double h = H(a, b, n);
	double s = 0;
	double x = a + h;
	double res;
	// по нечетным
	for (int i = 1; i < n / 2 + 1; i++) {
		s += 4 * f(x);
		x += 2 * h;
	}
	x = a + 2 * h;
	// по четным
	for (int i = 1; i < n / 2; i++) {
		s += 2 * f(x);
		x += 2 * h;
		res = (h / 3) * (f(a) + f(b) + s);
	}
	return res;
}


// Оченка погрешности по правилу рунге исп ч-ый м. симпосона
double sR(double a, double b, double n) {
	double h = H(a, b, n);
	double sn = 100;
	double s2n = 0;
	double n1;
	while ((dis(sn, s2n) / 15) >= e) {
		sn = simpson(a, b, n);
		s2n = simpson(a, b, 2 * n);
		n1 = n;
		n *= 2;
	}
	cout << sn << " " << n1 << "\n";
	return n1;
}


// Оценка погрешности по левым прямоугол исп ч-ый м. симпосона
double lR(double a, double b, double n) {
	double sn = 100;
	double s2n = 0;
	double n1;
	while ((dis(sn, s2n) / 3) >= e) {
		sn = lP(a, b, n);
		s2n = lP(a, b, 2 * n);
		n1 = n;
		n *= 2;
	}
	cout << sn << " " << n1 << "\n";
	return n1;
}


int main() {
	double a = 1;
	double b = 3;
	double n = 10;

	sR(a, b, n);
	lR(a, b, n);

	return 0;
}
