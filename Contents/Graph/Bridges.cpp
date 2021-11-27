// from aizu
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Edge {
  bool operator<(const struct Edge &arg) const {
    if (s != arg.s) {
      return s < arg.s;
    } else {
      return t < arg.t;
    }
  }
  int s, t;
};
struct Info {
  Info(int arg_to, int arg_edge_id) {
    to = arg_to;
    edge_id = arg_edge_id;
  }
  int to, edge_id;
};

int V, E, number;
int order[100000], lowlink[100000];
bool visited[100000];
Edge edge[100000];
vector<Info> G[100000];

void recursive(int cur) {
  order[cur] = number++;
  lowlink[cur] = order[cur];

  int next;

  for (int i = 0; i < G[cur].size(); i++) {
    next = G[cur][i].to;

    if (order[next] == -1) {
      visited[G[cur][i].edge_id] = true;
      recursive(next);
      lowlink[cur] = min(lowlink[cur], lowlink[next]);

    } else if (visited[G[cur][i].edge_id] == false) {
      lowlink[cur] = min(lowlink[cur], order[next]);
    }
  }
}

int main() {
  scanf("%d %d", &V, &E);
  for (int i = 0; i < E; i++) {
    scanf("%d %d", &edge[i].s, &edge[i].t);
    if (edge[i].s > edge[i].t) {
      swap(edge[i].s, edge[i].t);
    }
    G[edge[i].s].push_back(Info(edge[i].t, i));
    G[edge[i].t].push_back(Info(edge[i].s, i));
  }

  sort(edge, edge + E);

  number = 0;
  for (int i = 0; i < V; i++) {
    order[i] = -1;
    lowlink[i] = -1;
  }
  for (int i = 0; i < E; i++) {
    visited[i] = false;
  }

  recursive(0);

  int from, to;
  for (int i = 0; i < E; i++) {
    from = edge[i].s;
    to = edge[i].t;
    if (order[edge[i].s] > order[edge[i].t]) {
      swap(from, to);
    }
    if (order[from] < lowlink[to]) {
      printf("%d %d\n", edge[i].s, edge[i].t);
    }
  }
  return 0;
}
