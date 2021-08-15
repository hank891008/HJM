// 0-base
// 對於個長度為 n 的字串 s
// 定義函數 z[i] 表示 s 和 s[i, n - 1]
//（即以 s[i] 開頭的後綴）的最長公共前綴（LCP）的長度
// z[0] = 0。
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}