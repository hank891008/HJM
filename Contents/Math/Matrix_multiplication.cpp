struct Matrix {
  int row, col;
  vector<vector<int>> v;
  Matrix() : row(0), col(0) {}
  Matrix(int r, int c) : row(r), col(c) {
    v = vector<vector<int>>(r, vector<int>(c, 0));
  }
};
Matrix operator * (Matrix &a, Matrix &b) {
  assert(a.col == b.row);
  Matrix ret(a.row, b.col);
  for (int i = 0; i < a.row; i++) {
    for (int j = 0; j < b.col; j++) {
      for (int k = 0; k < a.col; k++) {
        ret.v[i][j] += a.v[i][k] * b.v[k][j];
      }
    }
  }
  return ret;
}