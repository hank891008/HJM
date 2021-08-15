vector<Pt> convex_hull(vector<Pt> &a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int sz = a.size(), m = 0;
  vector<Pt> ret(sz + 5); // safe 1 up
  for (int i = 0; i < sz; i++) {
    while (m > 1 &&
      cross(ret[m - 1] - ret[m - 2], a[i] - ret[m - 2]) <= EPS) {
      m--;
    }
    ret[m++] = a[i];
  }
  int k = m;
  for (int i = sz - 2; i >= 0; i--) {
    while (m > k &&
      cross(ret[m - 1] - ret[m - 2], a[i] - ret[m - 2]) <= EPS) {
      m--;
    }
    ret[m++] = a[i];
  }
  if (sz > 1) {
    m--;
  }
  ret.resize(m);
  return ret;
}