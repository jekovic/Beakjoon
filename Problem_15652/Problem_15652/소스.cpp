#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9

using namespace std;

int n, m;
int res[MAX];

void dfs(int index, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int j = index; j <= n; j++) {
		res[cnt] = j;
		dfs(j, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	dfs(1, 0);

	return 0;
}