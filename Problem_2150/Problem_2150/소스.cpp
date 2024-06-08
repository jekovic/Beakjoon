#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 10001

using namespace std;

int v, e;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

//항상 처음 방문하는 노드만 실행 
int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int result = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0) result = min(result, dfs(y));
		else if (!finished[y]) result = min(result, d[y]);
	}

	if (result == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return result;
}

void printResult(vector<vector<int>> s) {
	for (int i = 0; i != s.size(); i++) {
		for (int j = 0; j != s[i].size(); j++) {
			cout << s[i][j] << ' ';
		}
		cout << -1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int q, w;
		cin >> q >> w;
		a[q].push_back(w);
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}

	cout << SCC.size() << '\n';
	sort(SCC.begin(), SCC.end());
	printResult(SCC);

	return 0;
}