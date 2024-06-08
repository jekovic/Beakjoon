#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX 501
#define INF 1e12

using namespace std;

int n;
int m;
long long Dist[MAX];

vector<pair<int, pair<int, int >>> r;


bool bell() {
	Dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int from = r[j].first;
			int to = r[j].second.first;
			int cost = r[j].second.second;

			if (Dist[from] == INF) continue;

			if (Dist[to] > cost + Dist[from]) {
				Dist[to] = cost + Dist[from];

				if (i == n) return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		r.push_back({ a, {b, c} });
	}

	fill(Dist, Dist + MAX, INF);

	bool ret = 	bell();

	if (ret) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		if (Dist[i] == INF) {
			cout << -1;
		}
		else {
			cout << Dist[i];
		}
		cout << '\n';
	}

	return 0;
}