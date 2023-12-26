#include <iostream>
#include <vector>

#define X first
#define Y second

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector A(N, vector(N, 0));
  for (auto &r : A) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  const vector<pair<int, int>> OFFSET = {
      {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
      {0, 1}, {1, 1},  {1, 0},   {1, -1},
  };  // {0, 0}은 더미 역할

  auto simulation = [&](int d, int s, vector<pair<int, int>> clouds) {
    // 1. move cloud
    const auto &[dx, dy] = OFFSET[d];
    while (s--) {
      for (auto &[x, y] : clouds) {
        x += dx, y += dy;

        if (x < 0) {
          x = N - 1;
        } else if (x >= N) {
          x = 0;
        }

        if (y < 0) {
          y = N - 1;
        } else if (y >= N) {
          y = 0;
        }
      }
    }

    // 2. rain
    for (const auto &[x, y] : clouds) {
      A[x][y] += 1;
    }

    // 4. water copy bug
    for (int i : {2, 4, 6, 8}) {
      for (const auto &[x, y] : clouds) {
        int nx = x + OFFSET[i].X, ny = y + OFFSET[i].Y;
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || A[nx][ny] == 0) {
          continue;
        }

        A[x][y] += 1;
      }
    }

    // 5. make cloud
    vector<pair<int, int>> new_clouds;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (A[i][j] < 2) {
          continue;
        }

        bool flag = false;
        for (const auto &[x, y] : clouds) {
          if (i == x && j == y) {
            flag = true;
            break;
          }
        }

        if (flag) {
          continue;
        }

        new_clouds.emplace_back(i, j);
        A[i][j] -= 2;
        if (A[i][j] < 0) {
          A[i][j] = 0;
        }
      }
    }

    return new_clouds;
  };

  vector<pair<int, int>> clouds = {{N - 1, 0}, {N - 1, 1}, {N - 2, 0}, {N - 2, 1}};
  while (M--) {
    int d, s;
    cin >> d >> s;

    clouds = simulation(d, s, clouds);
  }

  int total_rains = 0;
  for (const auto &r : A) {
    for (const auto &c : r) {
      total_rains += c;
    }
  }
  cout << total_rains;

  return 0;
}