#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51

using namespace std;

int n;
vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int state[MAX][3];

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

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int q, w, e;
		cin >> q >> w >> e;

		state[i][0] = q;
		state[i][1] = w;
		state[i][2] = e;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (state[i][0] >= state[j][0] && state[i][1] >= state[j][1] && state[i][2] >= state[j][2]) {
				a[i].push_back(j);
			}
			else if (state[i][0] <= state[j][0] && state[i][1] <= state[j][1] && state[i][2] <= state[j][2]) {
				a[j].push_back(i);
			}
		}
	}



	int cnt = 0;

	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i)) cnt++;
		}
	}


	cout << n - cnt;

	return 0;
}