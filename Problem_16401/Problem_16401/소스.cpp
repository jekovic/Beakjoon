#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
vector<long long> s;
long long result;

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		long long q;
		cin >> q;
		s.push_back(q);
	}
}

void bs() {
	long long lo = 1;
	long long hi = 1e9;

	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		int sum = 0;
		for (auto& a : s) {
			sum += a / mid;

		}
		if (sum >= M) {
			lo = mid + 1;
			result = mid;
		}
		else {
			hi = mid - 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();

	cout << result;

	return 0;
}