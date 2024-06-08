#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> ch;
vector<pair<int, int>> selected;

int result = 987654321;
int visited[14];

int cal_dis(pair<int,int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void cal_h(vector<pair<int, int>>& v) {
	int total_dis = 0;
	for (const auto& h : house) {
		int dis = 987654321;
		for (const auto& a : v) {
			dis = min(dis, cal_dis(h, a));
		}
		total_dis += dis;
	}
	result = min(total_dis, result);
}

void dfs(int idx, int cnt) {

	if (cnt == M) {
		cal_h(selected);
		return;
	}

	for (int i = idx; i != ch.size(); i++) {
		
		if (!visited[i]) {
			visited[i] = 1;
			selected.push_back(ch[i]);
			dfs(i + 1, cnt + 1);
			visited[i] = 0;
			selected.pop_back();
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int t;
			cin >> t;

			if (t == 1) {
				house.push_back({ i, j });
			}
			else if (t == 2) {
				ch.push_back({ i, j });
			}
		}
	}

	dfs(0, 0);

	cout << result;

	return 0;
}