#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int d, n, m;
  std::cin >> d >> n >> m;

  std::vector<int> vec(n + 1);
  vec[0] = 0, vec[n] = d;

  for (int i = 1; i < n; ++i)
    std::cin >> vec[i];

  std::sort(vec.begin(), vec.end());

  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int k;
    std::cin >> k;

    auto itr = std::upper_bound(vec.begin(), vec.end(), k);

    ans += std::min(k - *(itr - 1), *itr - k);
  }

  std::cout << ans << std::endl;
}
