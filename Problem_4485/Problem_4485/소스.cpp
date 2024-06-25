#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

const int INF = 1e9;
int N;
vector<vector<int>> map;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int res = 1e9;

void init() {
	map.assign(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void dj() {
	vector<vector<int>> d(N, vector<int>(N, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ map[0][0], { 0, 0 } });
	d[0][0] = map[0][0];

 	while (!pq.empty()) {
		int curdis = pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			int nextdis = curdis + map[nx][ny];
			if (d[nx][ny] > nextdis) {
				d[nx][ny] = nextdis;
				pq.push({ nextdis, { nx, ny } });
			}
			
		}
	}

	res = d[N - 1][N - 1];
}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}

		init();

		dj();

		cout << "Problem " << t << ": " << res << '\n';
		t++;
	}

	return 0;
}