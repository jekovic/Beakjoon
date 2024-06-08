#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 8

using namespace std;

int n, m;
int res[MAX];

void dfs( int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		res[cnt] = i;
		dfs(cnt+1);

	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	dfs(0);

	return 0;
}