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
vector<pair<int, int>> study;
int result;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	//return a.second < b.second;
	return a.first < b.first;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		study.push_back({ q, w });
	}
}

void solve() {
	sort(study.begin(), study.end(), compare);
	priority_queue<int, vector<int>, greater<int>> pq;
	int end_time = study[0].second;
	pq.push(end_time);

	for (int i = 1; i != study.size(); i++) {
		int s = study[i].first, e = study[i].second;

		if (pq.top() > s) {
			pq.push(e);
		}
		else {
			pq.pop();
			pq.push(e);
		}
	}
	result = pq.size();
}

/*
	최대 수업의 갯수가 아닌 강의실의 갯수를 구해야 함을 주의!
*/

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	
	solve();
	
	cout << result;

	return 0;
}