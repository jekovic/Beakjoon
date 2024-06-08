#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 101
#define INF 987654321
using namespace std;
int n,m;
int a[MAX][MAX];

void floyd() {
	int d[MAX][MAX];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				d[i][j] = INF;
			}
			else {
				d[i][j] = a[i][j];
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n;j++) {
			if (i == j || d[i][j] == INF) {
				d[i][j] = 0;
			}
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		if (a[q][w] != 0)
		{
			if (a[q][w] > e) {
				a[q][w] = e;
			}
		}
		else {
			a[q][w] = e;
		}
	}

	floyd();

	return 0;
}