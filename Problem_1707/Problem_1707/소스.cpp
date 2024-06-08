#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> g[20001];
int visited[20001];
bool flag = false;
int cur = 1;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = cur;

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (int i = 0; i != g[t].size(); i++) {
			int n = g[t][i];
			if (visited[t] == visited[n]) {
				flag = true;
				return;
			}
			if (visited[n] == 0) {
				visited[n] = visited[t] * (-1);
				q.push(n);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		int v, e;
		cin >> v >> e;

		for (int i = 0; i < 20001; i++) {
			g[i].clear();
			visited[i] = 0;
			flag = false;
		}
			
		for (int t = 0; t < e; t++) {
			int q, w;
			cin >> q >> w;
			
			g[q].push_back(w);
			g[w].push_back(q);
		}

		for (int i = 0; i < v; i++) {
			if (!visited[i]) {
				bfs(i);
			}
		}

		if (flag == true) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}

	
	return 0;
}