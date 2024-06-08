#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001

using namespace std;

class Edge {
public:
	int x;
	int y;
	int dis;
	Edge(int a, int b, int d) {
		this->x = a;
		this->y = b;
		this->dis = d;
	}
	bool operator < (Edge& e) {
		return this->dis < e.dis;
	}
};

vector<Edge> v;

int p[MAX];

int getparent(int x) {
	if (p[x] == x)
		return x;
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

	if (a == b) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {

		int n, m;
		cin >> n >> m;
		
		if (n == 0 && m == 0) {
			break;
		}

		v.clear();
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}

		int ret = 0;

		for (int i = 0; i < m; i++) {
			int q, w, e;
			cin >> q >> w >> e;
			ret += e;
			v.push_back(Edge(q, w, e));
		}

		sort(v.begin(), v.end());

		int sum = 0;

		for (int i = 0; i != v.size(); i++) {
			if (!findparent(v[i].x, v[i].y)) {
				sum += v[i].dis;
				unionparent(v[i].x, v[i].y);
			}
		}

		cout << ret - sum << '\n';
	}
	
	return 0;
}