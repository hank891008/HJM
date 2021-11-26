const double EPS = 1e-6;
// target function
double f(double x) { return x * x; }
double ternarySearch() {
  double L = -1e5, R = 1e5;
  while (R - L > EPS) {
    double mr = (L + R) / 2.0;
    double ml = (L + mr) / 2.0;
    if (f(ml) < f(mr)) {
      R = mr;
    } else {
      L = ml;
    }
  }
  return L;
}