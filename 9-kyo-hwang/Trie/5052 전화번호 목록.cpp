#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
 public:
  Trie() : root(new Node()) {}

  void insert(const string &str) { 
    Node *p = root;
    for (const char &ch : str) {
      int i = ch - '0';
      if (!p->next[i]) p->next[i] = new Node;
      p = p->next[i];
    }
    p->leaf = true;
  }

  bool search(const string& str) {
    Node *p = root;
    for (const char &ch : str) {
      int i = ch - '0';
      if (!p->next[i]) return false;

      p = p->next[i];
      if (p->leaf) return true;
    }
    return false;
  }

 private:
  struct Node {
    bool leaf;
    vector<Node *> next;

    Node() : leaf(false) { next.assign(10, nullptr); }
  };

  Node *root;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int t; cin >> t;
  
  while (t--) {
    Trie *trie = new Trie;

    int n; cin >> n;
    vector<string> phone_numbers(n);
    for (string &phone : phone_numbers) {
      cin >> phone;
    }
    sort(phone_numbers.begin(), phone_numbers.end());

    bool flag = true;
    for (const string &phone : phone_numbers) {
      if (trie->search(phone)) {
        flag = false;
        break;
      }
      trie->insert(phone);
    }

    cout << (flag ? "YES" : "NO") << "\n";
    delete trie;
  }

  return 0;
}