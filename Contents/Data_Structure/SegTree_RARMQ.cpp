struct Node {
  int val, tag;
  Node *lc, *rc;
  Node() : lc(nullptr), rc(nullptr), tag(0) {}
  void pull() {
    if (!lc) {
      val = rc->val;
    } else if (!rc) {
      val = lc->val;
    } else {
      val = max(lc->val, rc->val);
    }
  }
  void push() {
    if (lc) {
      lc->tag += tag;
      lc->val += tag;
    }
    if (rc) {
      rc->tag += tag;
      rc->val += tag;
    }
    tag = 0;
  }
};
struct SegmentTree {
  Node *root;
  SegmentTree() : root(nullptr) {}
  void build(Node* &T, int l, int r, const vector<int> &o) {
    T = new Node();
    if (l == r) {
      T->val = o[l];
      return;
    }
    int mid = (l + r) / 2;
    build(T->lc, l, mid, o);
    build(T->rc, mid + 1, r, o);
    T->pull();
  }
  void update(Node* &T, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
      T->val += v;
      T->tag += v;
      return;
    }
    T->push();
    int mid = (l + r) / 2;
    if (qr <= mid) {
      update(T->lc, l, mid, ql, qr, v);
    } else if (mid < ql) {
      update(T->rc, mid + 1, r, ql, qr, v);
    } else {
      update(T->lc, l, mid, ql, mid, v);
      update(T->rc, mid + 1, r, mid + 1, qr, v);
    }
    T->pull();
  }
  int query(Node* &T, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return T->val;
    }
    T->push();
    int mid = (l + r) / 2;
    if (qr <= mid) {
      return query(T->lc, l, mid, ql, qr);
    } else if (mid < ql) {
      return query(T->rc, mid + 1, r, ql, qr);
    } else {
      return max(query(T->lc, l, mid, ql, mid),
                query(T->rc, mid + 1, r, mid + 1, qr));
    }
  }
};