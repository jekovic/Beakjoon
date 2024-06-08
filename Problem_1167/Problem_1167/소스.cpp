//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <vector>
//#define MAX 100001
//#define INF 987654321
//
//using namespace std;
//int n;
//
//bool visited[MAX];
//int d[MAX];
//vector<pair<int, int>> a[MAX];
//int cnt;
//
//
//
//void dj(int start) {
//
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
//	d[start] = 0;
//	pq.push({ 0, start });
//
//	while (!pq.empty()) {
//		int dist = pq.top().first;
//		int cur = pq.top().second;
//		pq.pop();
//
//		if (d[cur] < dist) continue;
//		for (int i = 0; i != a[cur].size(); i++) {
//			int next = a[cur][i].second;
//			int nextdis = a[cur][i].first + dist;
//
//			if (d[next] > nextdis) {
//				d[next] = nextdis;
//				cnt++;
//				pq.push({ nextdis, next });
//			}
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int q;
//		cin >> q;
//
//		while (1) {
//			int w, e;
//			cin >> w;
//			if (w == -1) {
//				break;
//			}
//			cin >> e;
//			a[q].push_back({ e, w });	
//		}
//	}
//
//	vector<int> res;
//
//	for (int i = 1; i <= n; i++) {
//		//fill(visited, visited + n + 1, false);
//		fill(d, d + n + 1, INF);
//		cnt = 0;
//		dj(i);
//		sort(d, d + n + 1);
//		res.push_back(d[cnt]);
//	}
//
//	sort(res.rbegin(), res.rend());
//	cout << res[0];
//
//	return 0;
//}

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 100001
#define INF 987654321

using namespace std;
int n;

bool visited[MAX];
vector<pair<int, int>> a[MAX];

int leaf;
int dist;

void dfs(int start,int cnt) {

	if (dist < cnt) {
		leaf = start;
		dist = cnt;
	}
	
	//visited[start] = true;

	for (int i = 0; i != a[start].size(); i++) {
		int y = a[start][i].second;
		if (!visited[y]) {
			visited[y] = true;
			dfs(y, cnt+ a[start][i].first);
			visited[y] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;

		while (1) {
			int w, e;
			cin >> w;
			if (w == -1) {
				break;
			}
			cin >> e;
			a[q].push_back({ e, w });
		}
	}
	visited[1] = true;
	dfs(1, 0);

	fill(visited, visited + n + 1, false);
	dist = 0;

	visited[leaf] = true;
	dfs(leaf, 0);
	
	cout << dist;
	
	
	return 0;
}