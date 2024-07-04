#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int N;
vector<pair<int, int>> meet;
int result = 1;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		meet.push_back({ q, w });
	}
}

void solve() {
	sort(meet.begin(), meet.end(), compare);

	int end_time = meet[0].second;
	for (int i = 1; i != meet.size(); i++) {
		const auto& temp = meet[i];
		if (temp.first >= end_time) {
			end_time = temp.second;
			result++;
		}
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