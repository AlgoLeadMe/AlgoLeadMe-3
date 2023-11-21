#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using edge = pair<int, int>;  // dst, cost

constexpr int INF = 1e9;

int N;
vector<vector<edge>> adjacent;

vector<int> dijkstra(int s) {
  vector<int> dists(N + 1, INF);
  priority_queue<edge, vector<edge>, greater<>> pq;

  dists[s] = 0;
  pq.emplace(0, s);  // dist, src

  while (!pq.empty()) {
    const auto [d, u] = pq.top();  // distance, src
    pq.pop();

    for (const auto &[v, w] : adjacent[u]) {  // dst, weight
      if (dists[v] > d + w) {
        dists[v] = d + w;
        pq.emplace(d + w, v);
      }
    }
  }

  return dists;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> N;
  adjacent.resize(N + 1);
  
  int A, B, C;
  cin >> A >> B >> C;

  int M;
  cin >> M;

  while (M--) {
    int D, E, L;
    cin >> D >> E >> L;

    adjacent[D].emplace_back(E, L);
    adjacent[E].emplace_back(D, L);
  }

  vector<vector<int>> dists = {dijkstra(A), dijkstra(B), dijkstra(C)};

  int max_d = 0, answer = 0;
  for (int i = 1; i <= N; i++) {
    if (i == A || i == B || i == C) continue;

    int min_d = min({dists[0][i], dists[1][i], dists[2][i]});
    if (min_d > max_d) {
      max_d = min_d;
      answer = i;
    }
  }

  cout << answer;

  return 0;
}