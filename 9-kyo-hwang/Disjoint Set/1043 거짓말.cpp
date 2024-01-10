#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> parents;

int find(int x) {
  while (x != parents[x]) {
    parents[x] = parents[parents[x]];
    x = parents[x];
  }

  return parents[x];
}

void unite(int x, int y) { 
  x = find(x);
  y = find(y);

  if (x == y) {
    return;
  }

  if (x < y) {
    parents[y] = x;
  } else if(x > y) {
    parents[x] = y;
  }
}

void input_party_info(vector<int>& party) {
  int num_member;
  cin >> num_member;

  while (num_member--) {
    int member;
    cin >> member;

    party.emplace_back(member);
  }
}

void update_relationship(const vector<int>& party) {
  if (party.size() <= 1) {
    return;
  }

  for (int i = 0; i < party.size() - 1; i++) {
    unite(party[i], party[i + 1]);
  }
}

bool can_speak_lie(const vector<int>& party) {
  if (party.size() < 1) {
    return false;
  }

  for (const auto& member : party) {
    if (find(member) == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;  // human, party

  parents.resize(N + 1);
  iota(parents.begin(), parents.end(), 0);

  int num_true;
  cin >> num_true;

  while (num_true--) {
    int t;
    cin >> t;

    parents[t] = 0;
  }

  vector<vector<int>> parties(M + 1);
  for (int i = 1; i <= M; i++) {
    input_party_info(parties[i]);
  }

  for (const auto& party : parties) {
    update_relationship(party);
  }

  int answer = 0;
  for (const auto& party : parties) {
    answer += can_speak_lie(party);
  }

  cout << answer;

  return 0;
}