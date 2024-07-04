#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int N, K;
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long res;

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		pq.push(t);
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		a += b;
		pq.push(a);
		pq.push(a);
	}

	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solve();
	cout << res;
	return 0;
}