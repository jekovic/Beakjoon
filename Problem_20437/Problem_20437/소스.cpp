#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		string W;
		int K;
		cin >> W >> K;

		vector<int> alpha(26, 0);
		
		for (int i = 0; i < W.size(); i++) {
			int idx = int(W[i] - 'a');
			alpha[idx] += 1;
		}

		int min_len = 1e9;
		int max_len = 0;

		for (int i = 0; i != W.size(); i++) {
			if (alpha[W[i] - 'a'] < K)
				continue;
			int cnt = 0;

			for (int j = i; j != W.size(); j++) {
				if (W[i] == W[j])
					cnt++;

				if (cnt == K) {
					min_len = min(min_len, j - i + 1);
					max_len = max(max_len, j - i + 1);
					break;
				}
			}
		}

		//for (int i = 0; i < 26; i++) {
		//	if (alpha[i].size() >= K) {
		//		flag = false;
		//		for (int j = 0; j+K-1 < alpha[i].size(); j++) {

		//			int d = alpha[i][j + K-1] - alpha[i][j] + 1;
		//			
		//			min_len = min(min_len, d);

		//			// 시작과 끝이 같은지 추론 가능?
		//			
		//			max_len = max(max_len, d); 
		//		}
		//	}
		//}
	
		if (min_len == 1e9 || max_len == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << min_len << ' ' << max_len << '\n';
		}
	}

	return 0;
}