#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int R, C;
vector<vector<char>> lake;
deque<pii> waters, swans;
vector<int> parents;

const vector<pii> &offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool out_of_bound(int x, int y) { return x < 0 || x >= R || y < 0 || y >= C; }

int find(int x) {
  while (x != parents[x]) {
    parents[x] = parents[parents[x]];
    x = parents[x];
  }
  return parents[x];
}

void unite(int u, int v) {
  u = find(u);
  v = find(v);

  if (u > v) {
    parents[v] = u;
  } else if (u < v) {
    parents[u] = v;
  }
}

int convert_coord(int x, int y) { return x * C + y; }

void unite_water() {
  for (const auto &[x, y] : waters) {
    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (out_of_bound(nx, ny) || lake[nx][ny] == 'X') {
        continue;
      }

      unite(convert_coord(x, y), convert_coord(nx, ny));
    }
  }
}

int convert_coord(pii p) { return p.X * C + p.Y; }

bool did_swans_meet() {
  return find(convert_coord(swans[0])) == find(convert_coord(swans[1]));
}

void melt_glaciers() {
  for (int cnt = waters.size(); cnt > 0; --cnt) {
    const auto [x, y] = waters.front();
    waters.pop_front();

    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (out_of_bound(nx, ny) || lake[nx][ny] != 'X') {
        continue;
      }
      lake[nx][ny] = '.';
      waters.emplace_back(nx, ny);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  lake.resize(R, vector<char>(C));

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> lake[i][j];

      if (lake[i][j] == 'X') {
        continue;
      }

      waters.emplace_back(i, j);
      if (lake[i][j] == 'L') {
        swans.emplace_back(i, j);
      }
    }
  }

  parents.resize(R * C);
  iota(parents.begin(), parents.end(), 0);

  int days = 0;
  while (!waters.empty()) {
    unite_water();
    if (did_swans_meet()) {
      break;
    }
    melt_glaciers();
    days += 1;
  }

  cout << days;

  return 0;
}