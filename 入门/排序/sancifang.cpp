/*
 @author: small-cai
 @time: 2022/8/14
 @problem: 求一个数的三次方跟。
*/
#include <iomanip>
#include <iostream>
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0)

int main() {
  IOS;
  double x;
  std::cin >> x;

  double l = -1e4, r = 1e4;
  while (r - l > 1e-8) {
    double mid = (l + r) / 2;
    // check
    if (mid * mid * mid >= x) {
      r = mid;
    } else {
      l = mid;
    }
  }
  std::cout << std::setprecision(6) << l << std::endl;
  return 0;
}
