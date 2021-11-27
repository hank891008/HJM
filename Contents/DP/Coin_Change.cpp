// from aizu
int main() {
  int n, m, min, tmp;
  scanf("%d", &n);
  int minimum[n + 1];
  scanf("%d", &m);
  int coin[m];
  for (int i = 0; i < m; i++) scanf("%d", &coin[i]);

  minimum[0] = 0;
  minimum[1] = 1;
  for (int i = 2; i <= n; i++) {
    min = n + 1;
    for (int k = 0; k < m; k++) {
      if (coin[k] <= i) {
        tmp = 1 + minimum[i - coin[k]];
        min = (min <= tmp) ? min : tmp;
      }
    }
    minimum[i] = min;
  }

  printf("%d\n", minimum[n]);

  return 0;
}
