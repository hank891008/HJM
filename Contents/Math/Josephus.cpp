int josephus(int n, int k) {  // 有n個人圍成一圈,每k個一次
  return n > 1 ? (josephus(n - 1, k) + k) % n : 0;
}  // 回傳最後一人的編號, 0 index