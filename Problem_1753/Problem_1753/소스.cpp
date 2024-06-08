#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 11111111;
vector<pair<int, int>> a[30001];
int d[20001];

void dijkstra(int s) {
	d[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (d[cur] < distance) continue;

		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;
			int nextDis = a[cur][i].second + distance;

			if (nextDis < d[next]) {
				d[next] = nextDis;
				pq.push(make_pair(-nextDis, next));
			}
		}

	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	int start;
	cin >> start;
	
	for (int i = 1; i <= v;i++) {
		d[i] = INF;
	}
	
	for (int i = 0; i < e; i++) {
		int q, w, r;
		cin >> q >> w >> r;
		a[q].push_back(make_pair(w, r));
	//	a[w].push_back(make_pair(q, r));
	}

	dijkstra(start);

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}

	return 0;
}