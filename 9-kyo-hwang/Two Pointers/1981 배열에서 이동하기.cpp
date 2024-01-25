#include <cstdio>
#include <cstring>
#include <queue>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

const std::pair<int, int> offset[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, min_val = 200, max_val = 0;
int arr[101][101];

bool is_out_of_bound(int x, int y) {
  return !(0 <= x && x < n && 0 <= y && y < n);
}

bool is_not_within_range(const int lower_bound, const int upper_bound, int x) {
  return !(lower_bound <= x && x <= upper_bound);
}

bool bfs(int lower_bound, int upper_bound) {
  bool visited[101][101];
  memset(visited, false, sizeof(visited));

  std::deque<std::pair<int, int>> q;
  q.emplace_back(0, 0);
  visited[0][0] = true;

  while (!q.empty()) {
    const auto [x, y] = q.front();
    q.pop_front();

    if (x == n - 1 && y == n - 1) {
      return true;
    }

    for (const auto &[dx, dy] : offset) {
      int nx = x + dx, ny = y + dy;
      if (is_out_of_bound(nx, ny) ||
          is_not_within_range(lower_bound, upper_bound, arr[nx][ny]) ||
          visited[nx][ny]) {
        continue;
      }

      visited[nx][ny] = true;
      q.emplace_back(nx, ny);
    }
  }

  return false;
}

bool can_move_within_range(int lower_bound, int upper_bound) {
  if (is_not_within_range(lower_bound, upper_bound, arr[0][0])) {
    return false;
  }

  return bfs(lower_bound, upper_bound);
}

int main() {
  scanf(" %d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf(" %d", &arr[i][j]);
      min_val = min(min_val, arr[i][j]);
      max_val = max(max_val, arr[i][j]);
    }
  }

  int ans = 200;
  int ptr1 = min_val, ptr2 = min_val;
  while (ptr1 <= ptr2 && ptr2 <= max_val) {
    if (can_move_within_range(ptr1, ptr2)) {
      ans = min(ans, ptr2 - ptr1);
      ptr1 += 1; // range decrease
    } else {
      ptr2 += 1; // range increase
    }
  }

  printf("%d", ans);

  return 0;
}