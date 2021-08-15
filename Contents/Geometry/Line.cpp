struct Line {
  Pt st;
  Pt ed;
};
// return point side
// left, on line, right -> 1, 0, -1
int side(Line l, Pt a) {
  dvt cross_val = cross(a - l.st, l.ed - l.st);
  if (cross_val > EPS) {
    return 1;
  } else if (cross_val < -EPS) {
    return -1;
  } else {
    return 0;
  }
}
// AB infinity, CD segment
bool has_intersection(Line AB, Line CD) {
  int c = side(AB, CD.st);
  int d = side(AB, CD.ed);
  if (c == 0 || d == 0) {
    return true;
  } else {
    // different side
    return c == -d;
  }
}
// find intersection point, two line, not seg
pair<int, Pt> intersection(Line a, Line b) {
  Pt A = a.ed - a.st;
  Pt B = b.ed - b.st;
  Pt C = b.st - a.st;
  dvt mom = cross(A, B);
  dvt son = cross(C, B);
  if (std::abs(mom) <= EPS) {
    if (std::abs(son) <= EPS) {
      return {1, {}}; // same line
    } else {
      return {2, {}}; // parallel
    }
  } else {            // ok
    return {0, a.st + A * (son / mom)};
  }
}
// line to point distance
dvt dis_lp(Line l, Pt a) {
  return area3x2(l.st, l.ed, a) / dis_pp(l.st, l.ed);
}