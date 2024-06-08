#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int home_x, home_y;
int rock_x, rock_y;
vector<pair<int, int>> conv;
vector<int> visited;

void input() {

	cin >> N;

	cin >> home_x >> home_y;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		conv.push_back({ q, w });
	}
	visited.assign(N, 0);

	cin >> rock_x >> rock_y;
}

void init() {
	visited.clear();
	conv.clear();
}

bool bfs() {

	queue<pair<int, int>> q;
	q.push({ home_x, home_y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (abs(rock_x - cx) + abs(rock_y - cy) <= 1000) return true;

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			if (abs(conv[i].first - cx) + abs(conv[i].second - cy) <= 1000){
				visited[i] = true;
				q.push({ conv[i].first, conv[i].second });
			}
		}
	}
	return false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {

		input();

		bool flag = bfs();

		if (flag == true) {
			cout << "happy";
		}
		else {
			cout << "sad";
		}

		init();

		cout << '\n';
	}

	return 0;
}