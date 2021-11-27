// from aizu
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_SIZE 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

#define SIZE 100000

vector<int> G[SIZE];
int N;
bool visited[SIZE];
int visited_order[SIZE], parent[SIZE], lowest[SIZE], number;

void dfs(int cur, int pre_node) {
  visited_order[cur] = lowest[cur] = number;
  number++;

  visited[cur] = true;

  int next;

  for (int i = 0; i < G[cur].size(); i++) {
    next = G[cur][i];
    if (!visited[next]) {
      parent[next] = cur;
      dfs(next, cur);
      lowest[cur] = min(lowest[cur], lowest[next]);
    } else if (visited[next] == true && next != pre_node) {
      lowest[cur] = min(lowest[cur], visited_order[next]);
    }
  }
}

void art_points() {
  for (int i = 0; i < N; i++) visited[i] = false;

  number = 1;
  dfs(0, -1);

  int tmp_parent, root_num = 0;

  vector<int> V;

  for (int i = 1; i < N; i++) {
    tmp_parent = parent[i];
    if (tmp_parent == 0) {
      root_num++;
    } else if (visited_order[tmp_parent] <= lowest[i]) {
      V.push_back(tmp_parent);
    }
  }
  if (root_num >= 2) {
    V.push_back(0);
  }
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());

  for (int i = 0; i < V.size(); i++) {
    printf("%d\n", V[i]);
  }
}

int main() {
  int E;
  scanf("%d %d", &N, &E);
  int from, to;
  for (int i = 0; i < E; i++) {
    scanf("%d %d", &from, &to);
    G[from].push_back(to);
    G[to].push_back(from);
  }
  art_points();
}
