int kadane2D(int array[N][M]) {
  // Modify the array's elements to now hold the sum
  // of all the numbers that are above that element in its column
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      array[i][j] += array[i - 1][j];
    }
  }

  int ans = 0;  // Holds the maximum sum matrix found till now

  for (int bottom = 0; bottom < N; bottom++) {
    for (int top = bottom; top < N; top++) {
      // loop over all the N^2 sub problems
      int[] sums = new int[N];

      // store the sum of numbers between the two rows
      // in the sums array
      for (int i = 0; i < M; i++) {
        if (bottom > 0) {
          sums[i] = array[top][i] - array[bottom - 1][i];
        } else {
          sums[i] = array[top][i];
        }
      }

      // O(n) time to run 1D kadane's on this sums array
      ans = Math.max(ans, kadane1d(sums));
    }
  }
  return ans;
}