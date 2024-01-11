#include <iostream>
#include <vector>

using namespace std;
using node = pair<int, int>;

vector<vector<node>> tree;
vector<bool> visited;
int max_node = 0, max_dist = 0;

void dfs(int from, int total_dist = 0) {
  visited[from] = true;

  if (total_dist > max_dist) {
    max_node = from;
    max_dist = total_dist;
  }

  for (const auto &[to, distance] : tree[from]) {
    if (!visited[to]) {
      dfs(to, total_dist + distance);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int V; cin >> V;
  tree.resize(V + 1);

  for (int i = 1; i <= V; ++i) {
    int src_num;
    cin >> src_num;

    int dst_num, dst_dist;
    while (cin >> dst_num && dst_num != -1) {
      cin >> dst_dist;
      tree[src_num].emplace_back(dst_num, dst_dist);
    }
  }

  visited.assign(V + 1, false);
  dfs(1);
  visited.assign(V + 1, false);
  dfs(max_node);

  cout << max_dist;
  
  return 0;
}