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
// |a| x |b| x cos(x)
dvt iproduct(const Pt &a, const Pt &b) {
  return a.x * b.x + a.y * b.y;
}
// |a| x |b| x sin(x)
dvt cross(const Pt &a, const Pt &b) {
  return a.x * b.y - a.y * b.x;
}
dvt dis_pp(const Pt &a, const Pt, &b) {
  dvt dx = a.x - b.x;
  dvt dy = a.y - b.y;
  return sqrt(dx * dx, dy * dy);
}