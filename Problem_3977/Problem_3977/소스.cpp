#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int id, d[MAX];
bool visited[MAX];
stack<int> s;
vector<int> a[MAX];
vector<vector<int>> SCC;
int c[MAX];
bool isDegree[MAX];
vector<int> result;

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int result = d[x];
	for (int i = 0; i != a[x].size(); i++) {
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
			c[t] = SCC.size() + 1;
			visited[t] = true;
			if (t == x) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return result;
}


int main() {
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		int n, m;
		cin >> n >> m;

		fill(visited, visited + MAX, false);
		fill(d, d + MAX, 0);
		fill(isDegree, isDegree + MAX, false);
		fill(c, c + MAX, 0);
		id = 0;
		SCC.clear();
		result.clear();
		for (int i = 1; i <=n; i++) {
			a[i].clear();
		}		
		for (int i = 0; i < m; i++) {
			int q, w;
			cin >> q >> w;
			a[q+1].push_back(w+1);
		}

		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				if (c[i] != c[y]) {
					isDegree[c[y]] = true;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < SCC.size(); i++) {
			if (!isDegree[i+1]) {
				cnt++;
				for (int j = 0; j != SCC[i].size(); j++) {
					result.push_back(SCC[i][j] - 1);
				}
			}
		}
		sort(result.begin(), result.end());
		if (cnt != 1) {
			cout << "Confused" << '\n' << '\n' ;
		}
		else {
			for (int i = 0; i != result.size(); i++) {
				cout << result[i] << '\n';
			}
			cout << '\n';
		}
	}

	return 0;
}