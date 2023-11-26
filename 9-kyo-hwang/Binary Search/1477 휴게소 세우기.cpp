#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, L;
  cin >> N >> M >> L;

  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  v.emplace_back(0), v.emplace_back(L);

  sort(v.begin(), v.end());

  int low = 1, high = L - 1;
  int answer = 1001;
  while (low <= high) {
    int mid = (low + high) / 2;

    int numCanBuild = 0;
    for (int i = 1; i < v.size(); i++) {
      int dist = v[i] - v[i - 1];
      numCanBuild += dist / mid;
      if (dist % mid == 0) numCanBuild--;
    }

    if (numCanBuild > M) {
      low = mid + 1;
    } else {
      answer = min(answer, mid);
      high = mid - 1;
    }
  }

  cout << answer;

  return 0;
}