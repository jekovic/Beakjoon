#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 801
#define INF 10000001
using namespace std;
int n, m;
vector<pair<int, int>> a[MAX];
int v1, v2;
int d[MAX];
vector<int> r1, r2, r3;

void dj(int k) {

	priority_queue<pair<int, int >> pq;
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	d[k] = 0;
	pq.push({ k, 0 });

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int dis = -pq.top().second;
		pq.pop();

		if (dis > d[cur]) continue;
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;
			int nextdis = dis + a[cur][i].second;
			
			if (nextdis < d[next]) {
				d[next] = nextdis;
				pq.push({ next, -nextdis });
			}
		}
	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		a[q].push_back({ w,e });
		a[w].push_back({ q,e });
	}

	cin >> v1 >> v2;

	dj(1);
	int d1_v1 = d[v1];
	int d1_v2 = d[v2];

	dj(v1);
	int v1_v2 = d[v2];
	int v1_n = d[n];

	dj(v2);
	int v2_n = d[n];

	int result;

	result = min(INF, d1_v1 + v1_v2 + v2_n);
	result = min(result, d1_v2 + v1_v2 + v1_n);

	if (result >= INF) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;

}
