#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 1001
#define INF 987654321

using namespace std;

int N, M, K;
vector<pair<int, int>> cable[MAX];
int result = -1;
int dist[MAX];
int m;

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		cable[q].push_back({ e, w });
		cable[w].push_back({ e, q });
		m = max(m, e);
	}
}

//x 이하로 구성된 경로가 구성 가능한지
bool dj(int x) {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int di = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < di) continue;

		for (int i = 0; i < cable[cur].size(); i++) {
			int next = cable[cur][i].second;
			int nextdis = di + (cable[cur][i].first > x);
			
			if (nextdis < dist[next]) {
				dist[next] = nextdis;
				pq.push({ nextdis, next });
			}
		}
	}
	return dist[N] <= K;
}

void bs() {
	int lo = 0;
	int hi = m;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;		

		if (dj(mid)) {
			result = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();

	cout << result;

	return 0;
}