// from aizu
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

#define SIZE 25

struct Info {
  Info() { value = 0, weight = 0; }
  Info(ll arg_value, ll arg_weight) {
    value = arg_value;
    weight = arg_weight;
  }
  bool operator<(const struct Info &arg) const { return weight < arg.weight; }

  ll value, weight;
};

ll N, W;
ll POW[SIZE];
ll table_B[1 << 21];
Info info[45];

int main() {
  POW[0] = 1;
  for (int i = 1; i < SIZE; i++) {
    POW[i] = POW[i - 1] * 2;
  }

  scanf("%lld %lld", &N, &W);

  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &info[i].value, &info[i].weight);
  }

  if (N == 1) {
    if (info[0].weight <= W) {
      printf("%lld\n", info[0].value);
    } else {
      printf("0\n");
    }

    return 0;
  }

  vector<int> A, B;
  for (int i = 0; i < N / 2; i++) {
    A.push_back(i);
  }
  for (int i = N / 2; i < N; i++) {
    B.push_back(i);
  }

  vector<Info> vec_A, vec_B;
  for (int state = 0; state < POW[A.size()]; state++) {
    ll sum_w = 0;
    ll sum_value = 0;
    for (int loop = 0; loop < A.size(); loop++) {
      if (state & POW[loop]) {
        sum_w += info[A[loop]].weight;
        sum_value += info[A[loop]].value;
      }
    }
    vec_A.push_back(Info(sum_value, sum_w));
  }
  sort(vec_A.begin(), vec_A.end());

  for (int state = 0; state < POW[B.size()]; state++) {
    ll sum_w = 0;
    ll sum_value = 0;
    for (int loop = 0; loop < B.size(); loop++) {
      if (state & POW[loop]) {
        sum_w += info[B[loop]].weight;
        sum_value += info[B[loop]].value;
      }
    }
    vec_B.push_back(Info(sum_value, sum_w));
  }
  sort(vec_B.begin(), vec_B.end());

  table_B[0] = vec_B[0].value;
  for (int i = 1; i < vec_B.size(); i++) {
    //ある重さ以下の最大価値を求める
    table_B[i] = max(table_B[i - 1], vec_B[i].value);
  }

  int tail = vec_B.size() - 1;
  ll ans = 0;
  for (int i = 0; i < vec_A.size(); i++) {
    while (tail >= 0 && vec_A[i].weight + vec_B[tail].weight > W) tail--;
    if (tail < 0) break;

    ans = max(ans, vec_A[i].value + table_B[tail]);
  }

  printf("%lld\n", ans);
  return 0;
}
