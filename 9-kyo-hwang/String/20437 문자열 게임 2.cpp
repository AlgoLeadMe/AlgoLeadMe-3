#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  unordered_map<char, vector<int>> alpha_indices;

  while (T--) {
    string W;
    int K;
    cin >> W >> K;

    alpha_indices.clear();

    for (int i = 0; i < W.length(); i++) {
      alpha_indices[W[i]].emplace_back(i);
    }

    int minlen = 10001, maxlen = 0;
    for (const auto &[alpha, indices] : alpha_indices) {
      if (indices.size() < K) {
        continue;
      }

      for (int l = 0, r = K - 1; r < indices.size(); l++, r++) {
        int len = indices[r] - indices[l] + 1;
        minlen = min(minlen, len);
        maxlen = max(maxlen, len);
      }
    }

    if (minlen == 10001)
      cout << -1 << "\n";
    else
      cout << minlen << " " << maxlen << "\n";
  }

  return 0;
}