#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

long long dp[91];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	
	cin >> N;

	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];

	return 0;
}