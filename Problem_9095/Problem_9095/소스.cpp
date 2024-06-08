#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> res;

void init() {
	res.clear();
}

void dp(int n) {
	res[0] = 1;
	res[1] = 1;
	res[2] = 2;
	res[3] = 4;
	res[4] = 7;
	for (int i = 5; i <= n; i++) {
		res[i] = res[i - 1] + res[i - 2] + res[i - 3];
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	while (T--) {
		init();

		int N;
		cin >> N;
		res.assign(N + 1, 0);

		dp(N);

		cout << res[N] << '\n';
	}

	return 0;
}