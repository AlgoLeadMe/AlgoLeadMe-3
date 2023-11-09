#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	bool result = true;
	
	while(t--) {
		int l, s, n, k, m;  // 학생 수, 등수, A+ 비율, 수행 평가 개수, 과락 점수
		cin >> l >> s >> n >> k >> m;
		vector<int> v(k); // 수행 평가 k개의 각 점수
		for(int &i : v) cin >> i;
		
		if(s >= l * (double)n / 100) {
			result = false;
		} else {
			for(const int i : v) {
				if(i <= m) {
					result = false;
					break;
				}
			}
		}
	}
	
	cout << result;
	return 0;
}