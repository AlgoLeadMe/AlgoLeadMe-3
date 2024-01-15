#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const vector<pii> offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
vector<vector<bool>> is_cheese;

enum class EPaper {
  EMPTY,
  CHEESE,
};

bool is_out_of_bound(int x, int y) {
  return x < 0 || x >= N || y < 0 || y >= M;
}

bool has_everything_melted() {
  for (const auto &r : is_cheese) {
    for (const auto &c : r) {
      if (c == true) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  is_cheese.assign(N, vector(M, false));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int data;
      cin >> data;

      is_cheese[i][j] = data;
    }
  }

  int times = 0;
  while (!has_everything_melted()) {
    deque<pii> emptyq;
    vector contact_counts(N, vector(M, 0));
    vector visited(N, vector(M, false));

    // 1. find outside cheese
    emptyq.emplace_back(0, 0);
    visited[0][0] = true;

    while (!emptyq.empty()) {
      const auto [x, y] = emptyq.front();
      emptyq.pop_front();

      for (const auto &[dx, dy] : offset) {
        int nx = x + dx, ny = y + dy;

        if (is_out_of_bound(nx, ny) || visited[nx][ny]) {
          continue;
        }

        if (is_cheese[nx][ny]) {
          contact_counts[nx][ny] += 1;
        } else {
          visited[nx][ny] = true;
          emptyq.emplace_back(nx, ny);
        }
      }
    }

    // 2. melt cheese
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (contact_counts[i][j] >= 2) {
          is_cheese[i][j] = false;
        }
      }
    }

    times += 1;
  }

  cout << times;

  return 0;
}