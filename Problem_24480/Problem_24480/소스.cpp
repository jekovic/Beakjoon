#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

bool visited[MAX];
int n, m, r;
vector<int> a[MAX];
int res[MAX];
int cnt = 0;
void dfs(int start) {
	if (visited[start]) return;
	visited[start] = true;
	//cout << start << '\n';
	cnt++;
	res[start] = cnt;
	for (int i = 0; i != a[start].size(); i++) {
		int temp = a[start][i];
		dfs(temp);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].rbegin(), a[i].rend());
	}

	dfs(r);

	/*for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			cout << 0 << '\n';
		}
	}*/

	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
	return 0;
}