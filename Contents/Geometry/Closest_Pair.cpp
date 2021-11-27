// from aizu
struct Info {
  Info() { x = y = 0; }
  Info(double arg_x, double arg_y) {
    x = arg_x;
    y = arg_y;
  }
  bool operator<(const struct Info& arg) const { 
    return x < arg.x; 
  };
  double x, y;
};

int N;

bool compare_y(Info left, Info right) { 
  return left.y < right.y; 
}

Info* info;

double closest_pair(Info* array, int tmp_N) {
  if (tmp_N <= 1) return DBL_MAX;

  int mid = tmp_N / 2;
  double x = array[mid].x;
  double dist =
      min(closest_pair(array, mid), closest_pair(array + mid, tmp_N - mid));
  inplace_merge(array, array + mid, array + tmp_N, compare_y);

  vector<Info> V;
  for (int i = 0; i < tmp_N; i++) {
    if (fabs(array[i].x - x) >= dist) continue;

    for (int j = 0; j < V.size(); j++) {
      double dx = array[i].x - V[V.size() - j - 1].x;
      double dy = array[i].y - V[V.size() - j - 1].y;
      if (dy >= dist) break;
      dist = min(dist, sqrt(dx * dx + dy * dy));
    }
    V.push_back(array[i]);
  }
  return dist;
}

int main() {
  scanf("%d", &N);
  info = (Info*)malloc(sizeof(Info) * N);

  for (int i = 0; i < N; i++) {
    scanf("%lf %lf", &info[i].x, &info[i].y);
  }

  sort(info, info + N);

  printf("%.7lf\n", closest_pair(info, N));
}
