#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> ans;
    int G;
    cin >> G;

    for (int k = 1; k <= G; k++) {
        if (G % k == 0) {
            int j = G / k;
            int i = k;
            if (j > i && (j+i) % 2 == 0 && (j-i) % 2 == 0)
                ans.push_back((j+i) / 2);
        }
    }

    if (ans.size() > 0) {
        sort(ans.begin(), ans.end());
        for (int a = 0; a < ans.size(); a++)
            cout << ans[a] << endl;
    } else
        cout << -1 << endl;

    return 0;
}