#include <cstdio>

#define MAX 30

int N, M;
int SP1[MAX][MAX], SP2[MAX][MAX];

bool is_correct_vaccine() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (SP1[i][j] != SP2[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void flood_fill(const int from, const int to, int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= M || SP1[x][y] != from) {
    return;
  }

  SP1[x][y] = to;
  flood_fill(from, to, x - 1, y);
  flood_fill(from, to, x, y + 1);
  flood_fill(from, to, x + 1, y);
  flood_fill(from, to, x, y - 1);
}

int main() {
  scanf(" %d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf(" %d", &SP1[i][j]);
    }
  }

  int x = -1, y = -1, from = 0, to = 0;
  bool flag = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf(" %d", &SP2[i][j]);

      if (!flag && SP1[i][j] != SP2[i][j]) {
        x = i;
        y = j;
        
        from = SP1[i][j];
        to = SP2[i][j];

        flag = true;
      }
    }
  }

  if (flag) {
    flood_fill(from, to, x, y);
  }
  
  if (!flag || is_correct_vaccine()) {
    printf("YES");
  } else {
    printf("NO");
  }

  return 0;
}