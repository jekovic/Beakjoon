#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 101

using namespace std;


class Edge {
public:
	float x;
	float y;
	Edge(float a, float b) {
		this->x = a;
		this->y = b;
	}
};

class Dis {
public:
	int start;
	int end;
	float dis;
	Dis(int a, int b, float d) {
		this->start = a;
		this->end = b;
		this->dis = d;
	}

	bool operator < (Dis& d) {
		return this->dis < d.dis;
	}
};

float cal_dis(Edge a, Edge b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int p[MAX];
vector<Edge> v;
vector<Dis> a;

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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		p[i] = i;
	}

	while (n--) {
		float q, w;
		cin >> q >> w;
		v.push_back(Edge(q, w));
	}

	for (int i = 0; i != v.size() - 1; i++) {
		for (int j = i + 1; j != v.size(); j++)
		{
			a.push_back(Dis(i,j,cal_dis(v[i],v[j])));
		}
	}

	sort(a.begin(), a.end());

	float sum = 0.0;

	for (int i = 0; i != a.size(); i++) {
		if (!findparent(a[i].start, a[i].end)) {
			sum += a[i].dis;
			unionparent(a[i].start, a[i].end);
		}
	}
	
	printf("%.2f", sum);

	return 0;
}