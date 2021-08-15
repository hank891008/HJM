const int MAXN = ;
int n;
vector<int> G[MAXN];
int vy[MAXN], my[MAXN];
bool match(int u) {
  for (int v : G[u]) {
    if (vy[v]) {
      continue;
    }
    vy[v] = true;
    if (my[v] == -1 || match(my[v])) {
      my[v] = u;
      return true;
    }
  }
  return false;
}
int sol() {
  int cnt = 0;
  memset(my, -1, sizeof(my));
  for (int i = 0; i < n; i++) {
    memset(vy, 0, sizeof(vy));
    if (match(i)) {
      cnt++;
    }
  }
  return cnt;
}