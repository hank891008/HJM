// from aizu
const ll maxn = 1e6 + 5;
const ll INF = 2147483647;
ll tree[maxn << 2], a[maxn], laze[maxn << 2];
void push_down(int rt, int ln, int rn) {
  if (laze[rt] != -1) {
    laze[rt << 1] = laze[rt];
    laze[rt << 1 | 1] = laze[rt];
    tree[rt << 1] = laze[rt];
    tree[rt << 1 | 1] = laze[rt];
    laze[rt] = -1;
  }
}
void push_up(int rt) { tree[rt] = min(tree[rt << 1 | 1], tree[rt << 1]); }
void build(ll l, ll r, ll rt) {
  if (l == r) {
    tree[rt] = a[l];
    return;
  }
  ll m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  push_up(rt);
}
//区间更新
void update(ll L, ll R, ll c, ll l, ll r, ll rt) {
  if (L <= l && r <= R) {
    laze[rt] = c;
    tree[rt] = c;
    return;
  }
  ll m = (l + r) >> 1;
  push_down(rt, m - l + 1, r - m);
  if (m >= L) update(L, R, c, l, m, rt << 1);
  if (m < R) update(L, R, c, m + 1, r, rt << 1 | 1);
  push_up(rt);
}

//区间更新的区间查询
ll query(ll L, ll R, ll l, ll r, ll rt) {
  if (L <= l && r <= R) {
    return tree[rt];
  }
  ll m = (l + r) >> 1, sum = INF;
  push_down(rt, m - l + 1, r - m);
  if (m >= L) sum = min(sum, query(L, R, l, m, rt << 1));
  if (m < R) sum = min(sum, query(L, R, m + 1, r, rt << 1 | 1));
  return sum;
}
void init() {
  for (int i = 0; i < maxn; i++) a[i] = INF;
  for (int i = 0; i < maxn * 4; i++) laze[i] = -1;
  build(0, n - 1, 1);
}
/*
update(x,y,z,0,n-1,1);
query(x,y,0,n-1,1)
*/