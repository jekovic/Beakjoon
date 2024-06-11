#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 10001
using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int result;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d, p });
	}
}

void solve() {
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			pq.pop();
		}
	}

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
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