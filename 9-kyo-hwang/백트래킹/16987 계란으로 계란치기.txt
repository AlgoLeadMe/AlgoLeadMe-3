#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Egg = pair<int,int>;  // S, W

#define S first
#define W second

int N;
vector<Egg> eggs;

int backtracking(int current = 0, int broken = 0) {
  // 가장 오른쪽 끝 계란에 도달했다면 지금까지 부순 계란의 개수 반환
  if (current == N) {
    return broken;
  }

  // 현재 계란이 깨졌거나 모든 계란이 깨졌다면, 계란을 치지 않고 넘어감.
  if (eggs[current].S <= 0 || broken == N - 1) {
    return backtracking(current + 1, broken);
  }

  int count = 0;
  for (int next = 0; next < N; next++) {
    // 다음으로 깨는 계란이 자기 자신이거나 이미 깨졌다면 수행하지 않음
    if (current == next || eggs[next].S <= 0) continue;

    eggs[current].S -= eggs[next].W;
    eggs[next].S -= eggs[current].W;

    // 모든 백트래킹의 경우에 대해 가장 큰 값을 취함
    count = max(count, backtracking(current + 1, broken + (eggs[current].S <= 0) + (eggs[next].S <= 0)));

    eggs[current].S += eggs[next].W;
    eggs[next].S += eggs[current].W;
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  eggs.resize(N);
  
  for (auto &[S, W] : eggs) cin >> S >> W;

  cout << backtracking();

  return 0;
}