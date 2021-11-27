// from aizu
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

int main() {
  char A[1001], B[1001];
  int len_A, len_B;
  scanf("%s %s", A, B);

  for (len_A = 0; A[len_A] != '\0'; len_A++);
  for (len_B = 0; B[len_B] != '\0'; len_B++);

  int** dp = new int*[len_B + 1];

  for (int row = 0; row <= len_B; row++) {
    dp[row] = new int[len_A + 1];
  }

  for (int col = 0; col <= len_A; col++) {
    dp[0][col] = col;
  }

  for (int row = 1; row <= len_B; row++) {
    dp[row][0] = row;
  }

  int cost;

  for (int row = 1; row <= len_B; row++) {
    for (int col = 1; col <= len_A; col++) {
      if (A[col - 1] == B[row - 1]) {
        cost = 0;
      } else {
        cost = 1;
      }
      dp[row][col] = min(dp[row - 1][col - 1] + cost,
        min(dp[row - 1][col] + 1, dp[row][col - 1] + 1));
    }
  }

  printf("%d\n", dp[len_B][len_A]);
}
