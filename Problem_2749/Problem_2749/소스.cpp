#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;
const int M = 1000000; // M = 10^k  => k = 6
const int period = 15 * pow(10, 5); // 15*10^(k-1)
vector<int> dp;

void fibo(long long n) {
	dp[1] = 1;
	dp[2] = 1;
	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
		}
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N;
	cin >> N;
	N %= period;
	dp.assign(N + 1, 0);

	fibo(N);

	cout << dp[N];

	return 0;
}