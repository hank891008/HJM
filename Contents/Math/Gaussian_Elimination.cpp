const double EPS = 1e-6;
double Gauss(vector<vector<double>> &d) {
  int n = d.size(), m = d[0].size();
  double det = 1;
  for (int i = 0; i < m; i++) {
    int p = -1;
    for (int j = i; j < n; j++) {
      if (fabs(d[j][i]) < EPS) {
        continue;
      }
      if (p == -1 || fabs(d[j][i]) > fabs(d[p][i])) {
        p = j;
      }
    }
    if (p == -1) {
      continue;
    }
    if (p != i) {
      det *= -1;
    }
    for (int j = 0; j < m; j++) {
      swap(d[p][j], d[i][j]);
    }
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      double z = d[j][i] / d[i][i];
      for (int k = 0; k < m; k++) {
        d[j][k] -= z * d[i][k];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    det *= d[i][i];
  }
  return det;
}
// new
const int MAXN = 300;
const double EPS = 1e-8;
int n;
double A[MAXN][MAXN];
void Gauss() {
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = i; j < n; j++) {
      if (fabs(A[j][i]) > EPS) {
        swap(A[j], A[i]);
        ok = 1;
        break;
      }
    }
    if (!ok) continue;
    double fs = A[i][i];
    for (int j = i + 1; j < n; j++) {
      double r = A[j][i] / fs;
      for (int k = i; k < n; k++) {
        A[j][k] -= A[i][k] * r;
      }
    }
  }
}