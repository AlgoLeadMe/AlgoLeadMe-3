#include <iostream>
#include <vector>

using namespace std;
using Loc = pair<int, int>;

#define x first
#define y second

Loc operator+(const Loc &a, const Loc &b) { return {a.x + b.x, a.y + b.y}; }

struct BC {
  int Index, X, Y, C, P;

  BC() : Index(-1), X(-1), Y(-1), C(-1), P(-1) {}
  BC(int inIndex, int inX, int inY, int inC, int inP)
      : Index(inIndex), X(inX), Y(inY), C(inC), P(inP) {}

  [[nodiscard]] inline int D(const Loc &loc) const {
    return abs(X - loc.x) + abs(Y - loc.y);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const vector<Loc> offset = {{}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int M, A;
  vector<int> aMvTrajectories, bMvTrajectories;
  vector<BC> BCs;
  Loc aLoc, bLoc;

  auto Input = [&]() {
    cin >> M >> A;
    aMvTrajectories.assign(M + 1, 0);
    bMvTrajectories.assign(M + 1, 0);
    BCs.assign(A, {});

    for (int T = 1; T <= M; ++T) {
      cin >> aMvTrajectories[T];
    }
    for (int T = 1; T <= M; ++T) {
      cin >> bMvTrajectories[T];
    }

    int bcCnt = 0;
    for (auto &[Index, X, Y, C, P] : BCs) {
      cin >> Y >> X >> C >> P;
      Index = bcCnt++;
    }

    aLoc = {1, 1};
    bLoc = {10, 10};
  };

  auto Charge = [&]() {
    int maxCharge = 0;
    for (const auto &aBC : BCs) {
      const int aDist = aBC.D(aLoc);
      const int aAmt = aDist <= aBC.C ? aBC.P : 0;

      for (const auto &bBC : BCs) {
        const int bDist = bBC.D(bLoc);
        const int bAmt = bDist <= bBC.C ? bBC.P : 0;

        const int curCharge =
            (aBC.Index != bBC.Index ? aAmt + bAmt : max(aAmt, bAmt));

        maxCharge = max(maxCharge, curCharge);
      }
    }
    return maxCharge;
  };

  auto Move = [&]() {
    int totalCharge = 0;
    for (int time = 0; time <= M; ++time) {
      aLoc = aLoc + offset[aMvTrajectories[time]];
      bLoc = bLoc + offset[bMvTrajectories[time]];

      totalCharge += Charge();
    }
    return totalCharge;
  };

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    Input();
    cout << "#" << tc << " " << Move() << "\n";
  }

  return 0;
}