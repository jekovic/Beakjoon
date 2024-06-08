#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1001

using namespace std;

class Edge {
public:
	int x;
	int y;
	long double dis;
	Edge(int a, int b, long double d) {
		this->x = a;
		this->y = b;
		this->dis = d;
	}
	bool operator < (Edge& e) {
		return this->dis < e.dis;
	}
};

long double cal_dis(int x1, int y1, int x2, int y2) {
	double dx = pow(x1 - x2, 2);
	double dy = pow(y1 - y2, 2);
	long double d = sqrt(dx + dy);
	return d;
}

vector<Edge> e;
int p[MAX];
vector<pair<int, int>> a;
vector<pair<int,int>> m_point;

int getparent(int x)
{
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

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < n; i++) {
		int q, w;
		cin >> q >> w;
		a.push_back({ q, w });
	}

	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		m_point.push_back({ q,w });
	}

	for (int i = 0; i != a.size() - 1;i++) {
		for (int j = i + 1; j != a.size(); j++) {
			e.push_back(Edge(i + 1, j + 1, cal_dis(a[i].first, a[i].second, a[j].first, a[j].second)));
		}
	}

	sort(e.begin(), e.end());

	for (int i = 0; i < m; i++) {
		unionparent(m_point[i].first, m_point[i].second);
	}

	long double sum = 0.0f;

	for (int i = 0; i != e.size(); i++) {
		if (!findparent(e[i].x, e[i].y)) {
			sum += e[i].dis;
			unionparent(e[i].x, e[i].y);
		}
	}

	//printf("%.2f", sum);

	cout << fixed;
	cout.precision(2);
	cout << sum;

	return 0;
}