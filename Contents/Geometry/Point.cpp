// notice point type!!!
using dvt = int;
const double EPS = 1e-6;
const double PI = acos(-1);

struct Pt {
  dvt x;
  dvt y;
};
bool operator < (const Pt &a, const Pt &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool operator == (const Pt &a, const Pt &b) {
  return a.x == b.x && a.y == b.y;
}
Pt operator + (const Pt &a, const Pt &b) {
  return {a.x + b.x, a.y + b.y};
}
Pt operator - (const Pt &a, const Pt &b) {
  return {a.x - b.x, a.y - b.y};
}
// multiply constant
Pt operator * (const Pt &a, const dvt c) {
  return {a.x * c, a.y * c};
}
Pt operator / (const Pt &a, const dvt c) {
  return {a.x / c, a.y / c};
}
// |a| x |b| x cosθ
dvt iproduct(const Pt &a, const Pt &b) {
  return a.x * b.x + a.y * b.y;
}
// |a| x |b| x sinθ
dvt cross(const Pt &a, const Pt &b) {
  return a.x * b.y - a.y * b.x;
}