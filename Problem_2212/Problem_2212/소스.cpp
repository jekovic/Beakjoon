#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;
int N, K;
vector<int> sensor;
int result = 0;

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		sensor.push_back(t);
	}
}

void solve() {
	sort(sensor.begin(), sensor.end());

	vector<int> dv;
	for (int i = 0; i != sensor.size() - 1; i++) {
		int t = sensor[i + 1] - sensor[i];
		dv.push_back(t);
	}

	sort(dv.rbegin(), dv.rend());

	for (int i = 0; i != K - 1; i++) {
		dv.erase(dv.begin());
	}

	for (int i = 0; i != dv.size(); i++) {
		result += dv[i];
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	if (K >= N) {
		cout << 0;
		return 0;
	}

	solve();

	cout << result;

	return 0;
}