#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 2001
#define INF 987654321

using namespace std;

vector<pair<int, int>> a[MAX];
int d[MAX];
bool visited[MAX];
int g, h;
int check;

/*
	최단경로로 갔을 때, g와 h를 거쳐갔으면 맞음
*/

void dj(int start) {
	fill(d, d + MAX, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < dis) continue;
		for (int i = 0; i != a[cur].size(); i++) {
			int nextdis = a[cur][i].first + dis;
			int next = a[cur][i].second;

			if (d[next] > nextdis) {
				d[next] = nextdis;
				pq.push({ nextdis, next });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> result;

	int testcase;
	cin >> testcase;

	for (int b = 0; b < testcase; b++) {
		//초기화 루틴
		result.clear();
		for (int y = 0; y < MAX; y++) {
			a[y].clear();
		}

		int n, m, t;	//교차로 -- 도로 -- 목적지 후보의 갯수 
		cin >> n >> m >> t;

		int s, g, h;
		cin >> s >> g >> h; //출발지 -- g,h 사이에 있는 도로는 무조건 지나감

		for (int j = 0; j < m; j++) {
			int q, w, e;
			cin >> q >> w >> e;
			a[q].push_back({ e, w });
			a[w].push_back({ e, q });
		}

		for (int j = 0; j < t; j++) {	//목적지 후보 --> 결과 출력

			int des;
			cin >> des;

			int res1 = 0;
			int res2 = 0;

			dj(s);

			int s_g = d[g];
			int s_h = d[h];
			int s_des = d[des];

			dj(g);
			int g_h = d[h];
			int g_des = d[des];

			dj(h);
			int h_g = d[g];
			int h_des = d[des];

			res1 = min(INF, s_g + g_h + h_des);
			res2 = min(INF, s_h + h_g + g_des);

			if (res2 < INF && res1 < INF) {
				if (res1 == s_des || res2 == s_des)
					//cout << des << '\n';
					result.push_back(des);
			}
		}
		sort(result.begin(), result.end());
		for (int r = 0;r != result.size(); r++) {
			cout << result[r] << ' ';
		}
		cout << '\n';
	}

	return 0;
}