#include <math.h>

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

double fn(double x) {
  double result = (-6 * pow(x, 2)) + (5 * x) + 3;
  return result;
}

double integral(double x) {
  double result = (-2 * pow(x, 3)) + (2.5 * pow(x, 2)) + (3 * x);
  return result;
}

double trapezoid(double a, double b, long n, int iteration = 1) {
  double deltaX = (b - a) / n;

  if (iteration == 1) {
    return a;
  } else {
    return a + iteration * (deltaX);
  }
}

int main() {
  double a;         // Upper bound
  double b;         // Lower bound
  float tolerance;  // Tolerance value
  long n;           // Number of trapezoids to use in the approximation

  cin >> a;
  cin >> b;
  cin >> tolerance;
  cin >> n;

  cout << fixed << setprecision(4);

  cout << "Lower Range: " << b << endl;
  cout << "Upper Range: " << a << endl;
  cout << "Initial trapezoid count: " << n << endl;

  cout << endl;

  /* Exact */
  double bBound = integral(b);
  double aBound = integral(a);
  double exact = bBound - aBound;

  /* Approximation */
  double approximation = trapezoid(a, b, n);
  int iteration = 1;
  while (approximation < exact - tolerance) {
    n += 2;
    approximation += trapezoid(a, b, n, iteration);
    iteration += 1;
  }

  cout << "Trap count:" << n << ",";
  cout << " estimate:" << approximation - tolerance << ",";
  cout << " exact:" << exact << ",";
  cout << " tolerance:" << tolerance << endl;
}

