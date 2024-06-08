#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, m;
int two;
vector<int> a[MAX];
int d[MAX];
bool c[MAX];

bool dfs(int x) {
	for (int i = 0;i != a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> two;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;	

		for (int j = 0; j < k; j++) {
			int q;
			cin >> q;
			a[i].push_back(q);
		}
	}


	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}
	

	int extra = 0;
	for (int i = 1; i <= n && two > extra; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) extra++;
	}

	cout << cnt + extra;

	return 0;
}