#include <string>
#include <vector>

using namespace std;

int dfs(const string &name, vector<int> indices, int cnt = 0, int pos = 0) {
  if (indices.empty()) {
    return cnt;
  }

  int lpos = indices.back();
  int lcnt = cnt + min(name[lpos] - 'A', 'Z' - name[lpos] + 1);
  if (lpos <= pos) {
    lcnt += pos - lpos;
  } else {
    lcnt += pos + name.size() - lpos;
  }

  int left = dfs(name, vector(indices.begin(), indices.end() - 1), lcnt, lpos);

  int rpos = indices.front();
  int rcnt = cnt + min(name[rpos] - 'A', 'Z' - name[rpos] + 1);
  if (pos <= rpos) {
    rcnt += rpos - pos;
  } else {
    rcnt += rpos + name.size() - pos;
  }
  int right = dfs(name, vector(indices.begin() + 1, indices.end()), rcnt, rpos);

  return min(left, right);
}

int solution(string name) {
  vector<int> indices;
  for (int i = 0; i < name.size(); ++i) {
    if (name[i] != 'A') {
      indices.emplace_back(i);
    }
  }

  return dfs(name, indices);
}