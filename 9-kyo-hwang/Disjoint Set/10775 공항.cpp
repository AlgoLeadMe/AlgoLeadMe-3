#include <cstdio>

int parent[100001];

int find(int x) {
  while (x != parent[x]) {
    parent[x] = parent[parent[x]];
    x = parent[x];
  }

  return parent[x];
}

int main() {
  int G, P;
  scanf(" %d %d", &G, &P);
  
  for (int i = 0; i <= G; i++) {
    parent[i] = i;
  }

  int i;
  for (i = 0; i < P; i++) {
    int g;
    scanf(" %d", &g);

    int p = find(g);
    if (p == 0) {
      break;
    }

    parent[p] = p - 1;
  }

  printf("%d\n", i);
  return 0;
}