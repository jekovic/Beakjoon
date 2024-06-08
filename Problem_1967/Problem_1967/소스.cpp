#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX	10001

using namespace std;
bool visited[MAX];
int leaf;
int dist;

vector<int> res;
vector<pair<int, int>> a[MAX];

void dfs(int start, int cnt) {
	if (dist < cnt) {
		dist = cnt;
		leaf = start;
	}

	for (int i = 0; i != a[start].size(); i++) {
		int s = a[start][i].first;
		int d = a[start][i].second;
		if (!visited[s]) {
			visited[s] = true;
			dfs(s, cnt + d);
			visited[s] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		a[q].push_back({ w, e });
		a[w].push_back({ q, e });
	}
	visited[1] = true;
	dfs(1, 0);
	fill(visited, visited + n + 1, false);
	dist = 0;
	
	visited[leaf] = true;
	dfs(leaf, 0);

	cout << dist;

	return 0;
}