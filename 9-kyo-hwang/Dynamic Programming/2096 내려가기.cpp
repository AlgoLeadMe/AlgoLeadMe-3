#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector max_dp(3, 0), min_dp(3, 0);

  for (int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    vector max_tmp(3, 0), min_tmp(3, 0);

    max_tmp[0] = a + max(max_dp[0], max_dp[1]);
    max_tmp[1] = b + max({max_dp[0], max_dp[1], max_dp[2]});
    max_tmp[2] = c + max(max_dp[1], max_dp[2]);

    min_tmp[0] = a + min(min_dp[0], min_dp[1]);
    min_tmp[1] = b + min({min_dp[0], min_dp[1], min_dp[2]});
    min_tmp[2] = c + min(min_dp[1], min_dp[2]);

    max_dp = max_tmp;
    min_dp = min_tmp;
  }

  cout << max({max_dp[0], max_dp[1], max_dp[2]}) << " "
       << min({min_dp[0], min_dp[1], min_dp[2]});

  return 0;
}