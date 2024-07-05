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
vector<pair<int,int>> line;
int result = 0;


bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		line.push_back({ q, w });
	}
}

void solve() {
	sort(line.begin(), line.end(), compare);
	//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue<pair<int, int>> pq;
	pq.push({ line[0].second, line[0].first});

	for (int i = 1; i != line.size(); i++) {
		int s = line[i].first, e = line[i].second;
		
		if (pq.top().first >= s) {
			if (e > pq.top().first) {
				int idx = pq.top().second;
				pq.pop();
				pq.push({ e, idx });
			}
		}
		else {
			pq.push({ e, s });
		}
	}

	while (!pq.empty()) {
		result += abs(pq.top().first - pq.top().second);
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