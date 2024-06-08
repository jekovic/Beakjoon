/*
	https://www.acmicpc.net/problem/1260
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int b[1000];	//bfs
int c[1000];	//dfs

void bfs(int start, vector<vector<int>> node) {
	queue<int> q;
	q.push(start);
	b[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < node[x].size(); i++) {
			sort(node[x].begin(), node[x].end());
			int y = node[x][i];
			if (!b[y]) {
				q.push(y);
				b[y] = true;
			}
		}
	}
}

void dfs(int x, vector<vector<int>> node) {
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	int k = node[x].size();
	for (int i = 0; i < node[x].size(); i++) {
		sort(node[x].begin(), node[x].end());
		int y = node[x][i];
		/*if (y != 0) {
		}*/
		dfs(y, node);
	}
}

int main() {

	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> node(n+1);
	//vector<int> node(n+1, 0);
	//vector<int> b(n, 0);
	//vector<int> c(n, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);

	}

	dfs(v, node);
	cout << endl;
	bfs(v, node);

	return 0;
}