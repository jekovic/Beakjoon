//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//
//using namespace std;
//int N;
//int revenue = 0;
//
//void dfs(int money, int idx, vector<pair<int, int>>& work) {
//	if (idx == N) {
//		revenue = max(money, revenue);
//		return;
//	}
//	if (idx > N) return;
//	revenue = max(money, revenue);
//	dfs(money + work[idx].second, idx + work[idx].first, work);
//	dfs(money, idx + 1, work);
//
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//	
//	vector<pair<int, int>> work;
//
//	for (int i = 1; i <= N; i++) {
//		int q, w;
//		cin >> q >> w;
//		work.push_back({ q, w });
//	
//	}
//
//	dfs(0, 0, work);
//
//	cout << revenue;
//
//	return 0;
//}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>	

using namespace std;

int N;
int result[17];
int day[17];
int money[17];

void dp() {
	int deadline = 0;
	for (int i = N; i > 0; i--) {
		deadline = i + day[i];
		if (deadline > N + 1) { //  진행 불가 
			result[i] = result[i + 1];
		}
		else {
			result[i] = max(result[i + 1], result[deadline] + money[i]);
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int q, w;
		cin >> q >> w;
		day[i] = q;
		money[i] = w;
	}

	dp();

	cout << result[1] << '\n';

	return 0;
}