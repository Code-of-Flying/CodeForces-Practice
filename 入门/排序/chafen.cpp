/*
 @author: small-cai
 @time: 2022/8/14
 @problem: 差分。
 @explain 构造差分数组，b[i] = a[i] - a[i-1],所以实际
          上改变的是 b[l] 和 b[l+1];
*/
#include <iostream>
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0)

const int N = 1e5 + 10;
int b[N], a[N];

void Insert(int l, int r, int c) {
  b[l] += c;
  b[r + 1] -= c;
}

int main() {
  IOS;
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    Insert(i, i, a[i]);
  }
  while (m--) {
    int l, r, c;
    std::cin >> l >> r >> c;
    Insert(l, r, c);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + b[i];
    std::cout << a[i] << " \n"[i == n];
  }
  return 0;
}
