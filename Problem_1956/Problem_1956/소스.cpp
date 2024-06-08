#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 401
#define INF 987654321

using namespace std;

int v, e;
int route[MAX][MAX];
vector<int> res;

void floyd()
{
	int d[MAX][MAX];

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (route[i][j] == 0) {
				d[i][j] = INF;
			}
			else {
				d[i][j] = route[i][j];
			}
		}
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		res.push_back(d[i][i]);
	}
	
	sort(res.begin(), res.end());

	if (res[0] == 0 || res[0] == INF) {
		cout << -1;
	}
	else {
		cout << res[0];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		route[a][b] = c;
	}

	floyd();

	return 0;
}