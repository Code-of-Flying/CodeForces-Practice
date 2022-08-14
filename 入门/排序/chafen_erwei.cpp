/*
 @author: small-cai
 @time: 2022/8/14
 @problem: 差分。
 @explain 构造二维差分数组，
          其实跟一维差分数组很像，不懂的可以去网上查。
*/
#include <iostream>
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0)

const int N = 1e3 + 10;
int b[N][N], a[N][N];

void Insert(int l1, int r1, int l2, int r2, int c) {
  b[l1][r1] += c;
  b[l1][r2 + 1] -= c;
  b[l2 + 1][r1] -= c;
  b[l2 + 1][r2 + 1] += c;
}

int main() {
  IOS;
  int n, m, q;
  std::cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      Insert(i, j, i, j, a[i][j]);
    }
  }
  while (q--) {
    int l1, r1, l2, r2, c;
    std::cin >> l1 >> r1 >> l2 >> r2 >> c;
    Insert(l1, r1, l2, r2, c);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
      std::cout << a[i][j] << " \n"[j == m];
    }
  }
  return 0;
}
