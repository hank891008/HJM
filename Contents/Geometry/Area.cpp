// triangle
dvt area3(Pt a, Pt b, Pt c) {
  return std::abs(cross(b - a, c - a) / 2);
}
dvt area3x2(Pt a, Pt b, Pt c) { // for integer
  return std::abs(cross(b - a, c - a));
}
// simple convex area(can in)
dvt area(vector<Pt> &a) {
	dvt ret = 0;
	for (int i = 0, sz = a.size(); i < sz; i++) {
		ret += cross(a[i], a[(i + 1) % sz]);
	}
	return std::abs(ret) / 2;
}
// check point in/out a convex
int io_convex(vector<Pt> convex, Pt q) {
	// convex is Counterclockwise
	for (int i = 0, sz = convex.size(); i < sz; i++) {
		Pt cur = convex[i] - q;
		Pt nex = convex[(i + 1) % sz] - q;
		dvt cross_val = cross(cur, nex);
		if (std::abs(cross_val) <= EPS) {
			return 0;  // on edge
		}
		if (cross_val < 0) {
			return -1; // outside
		}
	}
	return 1;      // inside
}