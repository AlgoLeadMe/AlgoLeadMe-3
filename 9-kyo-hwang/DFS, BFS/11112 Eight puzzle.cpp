#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_set>

using namespace std;

// f, g, board
// f = g(step) + h(heuristic)
// minimum f -> minimum g
using Node = tuple<int, int, string>;

const string &target = "12345678#";
const vector<pair<int, int>> offset = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

unordered_set<string> visited, impossible;

int astar(const string &board) { 
  visited.clear();

  priority_queue<Node, vector<Node>, greater<>> pq;
  pq.emplace(0, 0, board);
  visited.emplace(board);

  while (!pq.empty()) {
    const auto [f, g, current] = pq.top();
    pq.pop();

    if (current == target) {
      return g;
    }

    if (impossible.find(current) != impossible.end()) {
      return -1;
    }

    int pos = current.find('#');
    int x = pos / 3, y = pos % 3;

    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) {
        continue;
      }

      int npos = nx * 3 + ny;
      string next = current;
      swap(next[pos], next[npos]);
      
      if (visited.find(next) != visited.end()) {
        continue;
      }

      int h = 0;
      for (int i = 0; i < 9; i++) {
        if (target[i] != next[i]) {
          h += 1;
        }
      }

      pq.emplace(g + h, g + 1, next);
      visited.emplace(next);
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cin.ignore();

  while (n--) {
    string board;
    for (int i = 0; i < 3; i++) {
      string buffer;
      cin >> buffer;
      board += buffer;
    }
    cin.ignore();

    int result = astar(board);
    if (result == -1) {
      cout << "impossible\n";
      for (const auto &key : visited) {
        impossible.emplace(key);
      }
    } else {
      cout << result << "\n";
    }
  }

  return 0;
}