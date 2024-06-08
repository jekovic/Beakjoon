#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int d[10001];

int dp(int k) {
	if (k == 1)
		return 1;
	else if (k ==2) {
		return 2;
	}
	else if (k == 3) {
		return 3;
	}
	return d[k] = dp(k - 3) + (k / 2) + 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		int N;
		cin >> N;

		cout << dp(N) << '\n';
	}

	return 0;
}