#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<vector<int>> graph(N + 1);
  vector<int> times(N + 1, 0);
  vector<int> indegrees(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    cin >> times[i];

    int pre;
    while (true) {
      cin >> pre;
      if (pre == -1) {
        break;
      }

      graph[pre].emplace_back(i);
      indegrees[i] += 1;
    }
  }

  queue<int> q;
  vector<int> dp(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (indegrees[i] == 0) {
      q.emplace(i);
      dp[i] = times[i];
    }
  }

  for (int i = 1; i <= N; i++) {
    if (q.empty()) {
      break;
    }

    const int from = q.front();
    q.pop();

    for (const int &to : graph[from]) {
      indegrees[to] -= 1;
      dp[to] = max(dp[to], dp[from] + times[to]);

      if (indegrees[to] == 0) {
        q.emplace(to);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << dp[i] << "\n";
  }

  return 0;
}