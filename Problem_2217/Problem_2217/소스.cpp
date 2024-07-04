#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int result;
vector<int> rope;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		rope.push_back(t);
	}
}

void solve() {
	sort(rope.begin(), rope.end());

	for (int i = 0; i != rope.size(); i++) {
		int val = rope[i] * (rope.size() - i);
		result = max(result, val);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << result;

	return 0;
}