/*
 @author: small-cai
 @time: 2022/8/14
 @problem: 寻找 第k小数
*/

#include <iostream>
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
int n, k;

const int maxn = 100100;
int a[maxn];

int quick_select(int l, int r, int k) {
  if (l == r) {
    return a[l];
  }
  int i = l - 1, j = r + 1;
  int x = a[l];
  while (i < j) {
    while (a[++i] < x)
      ;
    while (a[--j] > x)
      ;
    if (i < j) std::swap(a[i], a[j]);
  }
  int sl = j - l + 1;
  if (k <= sl) return quick_select(l, j, k);
  return quick_select(j + 1, r, k - sl);
}

int main() {
  IOS;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::cout << quick_select(0, n - 1, k) << std::endl;
  return 0;
}