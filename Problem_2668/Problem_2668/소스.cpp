#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int N;
vector<int> num;
vector<int> vis;
vector<int> res;

void input() {
	cin >> N;

	num.assign(N + 1, 0);
	vis.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
}

void dfs(int cur, int start) {
	if (vis[cur]) {
		if (start == cur) res.push_back(cur);
		return;
	}
	vis[cur] = true;
	dfs(num[cur], start);
}

void solve() {
	for (int i = 1; i <= N; i++) {
		vis.assign(N + 1, 0);
		dfs(i, i);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << res.size() << '\n';
	for (int r : res) {
		cout << r << '\n';
	}

	return 0;
}