#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10

using namespace std;

int n, m;
int a[MAX][MAX];
bool visited[MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int p[MAX];

class Edge {
public:
	int start;
	int end;
	int distance;
	Edge(int x, int y, int z) {
		this->start = x;
		this->end = y;
		this->distance = z;
	}
	bool operator < (Edge& e) {
		return this->distance < e.distance;
	}
};

vector<Edge> v;

void bfs(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	a[x][y] = num;

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (a[nx][ny] == -1) {
					a[nx][ny] = num;
					q.push({ nx, ny });
				}
				
			}
		}
	}
}

void move(int x, int y, int di) {
	int sum = 0;
	int value = a[x][y];
	int nx = x;
	int ny = y;

	while (1) {
		nx += dx[di];
		ny += dy[di];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == value) {
			return;
		} 

		if (a[nx][ny] == 0) {
			sum++;
		}
		else {
			if (sum >= 2) {
				v.push_back(Edge(value, a[nx][ny], sum));
			}
			return;
		}
		
	}
}

int getparent(int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = getparent(p[x]);
}

void unionparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);

	if (a < b) p[b] = a;
	else if (a > b) p[a] = b;
}

int findparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);

	if (a == b)return 1;
	else return 0;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				a[i][j] = -1;
			}
		}
	}

	int num = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1) {
				bfs(i, j, num);
				num++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			for (int k = 0; k < 4; k++) {
				if (a[i][j] != 0) {
					move(i, j, k);
				}
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < MAX; i++) {
		p[i] = i;
	}

	int sum = 0;
	for (int i = 0; i != v.size(); i++) {
		if (!findparent(v[i].start, v[i].end)) {
			sum += v[i].distance;
			unionparent(v[i].start, v[i].end);
		}
	}

	int pi = getparent(1);

	for (int i = 2; i < num; i++) {
		if (pi != getparent(i)) {
			sum = 0;
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum;
	}

	return 0;
}