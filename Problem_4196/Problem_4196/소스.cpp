/*
	https://www.acmicpc.net/problem/4196
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;
int id, d[MAX];
stack<int> s;
vector<int> a[MAX];
vector<vector<int>> SCC;
bool visited[MAX];
int group[MAX];
int n, isDegree[MAX];

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int result = d[x];
	
	for (int i = 0;i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0) result = min(result, dfs(y));
		else if (!visited[y]) result = min(result, d[y]);
	}

	if (result == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			visited[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int l = 0; l < t; l++) {
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(visited, visited + MAX, 0);
		fill(isDegree, isDegree + MAX, false);
		id = 0;
		for (int i = 0; i < MAX; i++) {
			a[i].clear();
		}
		int m;
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int q, w;
			cin >> q >> w;
			a[q].push_back(w);
		}

		for (int k = 1; k <= n; k++) {
			if (d[k] == 0) dfs(k);
		}

		for (int r = 1; r <= n; r++) {
			for (int j = 0; j < a[r].size(); j++) {
				int y = a[r][j];
				if (group[r] != group[y]) {
					isDegree[group[y]] = true;
				}
			}
		}
		int result = 0;
		for (int i = 1; i <= SCC.size(); i++) {
			if (!isDegree[i]) result++;
		}
		cout << result << '\n';
		
	}

	return 0;
}