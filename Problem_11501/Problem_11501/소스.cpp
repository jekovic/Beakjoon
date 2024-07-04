#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> day;
long long result;

void init() {
	result = 0;
	day.clear();
}

void input() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		day.push_back(t);
	}
}

void solve() {
	int max_val = -1;
	for (int i = day.size() - 1; i >= 0; i--) {
		max_val = max(max_val, day[i]);
		result += max_val - day[i];
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {

		init();

		input();

		solve();

		cout << result << '\n';

	}

	return 0;
}