#include <iostream>
#include <vector>

constexpr auto INF = 1e9;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<vector<int>> arr(N + 1, vector<int>(N + 1, INF));
  for (int i = 1; i <= N; i++) arr[i][i] = 0;

  for (int i = 1; i <= K; i++) {
    int a, b;
    cin >> a >> b;

    arr[a][b] = -1;
    arr[b][a] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (i == j || i == k || j == k) continue;

        if (arr[i][k] == -1 && arr[k][j] == -1)
          arr[i][j] = -1;
        else if (arr[i][k] == 1 && arr[k][j] == 1)
          arr[i][j] = 1;
      }
    }
  }

  int S;
  cin >> S;
  while (S--) {
    int a, b;
    cin >> a >> b;

    if (arr[a][b] == INF)
      cout << 0 << "\n";
    else
      cout << arr[a][b] << "\n";
  }

  return 0;
}