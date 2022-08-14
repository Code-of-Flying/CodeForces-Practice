/*
 @author: small-cai
 @time: 2022/8/14
 @problem: 寻找逆序对个数，也可以通过树状数组求解。
*/

#include <iostream>
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
const int N = 1e5 + 10;
typedef long long ll;

int q[N], tmp[N];

ll merge_sort(int l, int r) {
  if (l >= r) return 0;
  int mid = l + r >> 1;
  ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);

  int k = 0, i = l, j = mid + 1;

  while (i <= mid && j <= r) {
    if (q[i] <= q[j])
      tmp[k++] = q[i++];
    else {
      tmp[k++] = q[j++];
      res += mid - i + 1;
    }
  }
  while (i <= mid) tmp[k++] = q[i++];
  while (j <= r) tmp[k++] = q[j++];

  for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
  return res;
}

int main() {
  IOS;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> q[i];
  std::cout << merge_sort(0, n - 1) << std::endl;
  return 0;
}