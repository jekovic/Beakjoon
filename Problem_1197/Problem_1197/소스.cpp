#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int>& parent, int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = getParent(parent, parent[a]);
}

void unionParent(vector<int> &parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	else return 0;
}

class Edge {
public :
	int node[2];
	int distance;
	Edge(int a, int b, int d) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = d;
	}

	bool operator <(Edge& e) {
		return this->distance < e.distance;
	}

};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<Edge> n;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		n.push_back(Edge(a, b, c));
	}

	sort(n.begin(), n.end());
	
	vector<int> check(v);
	for (int i = 0; i < v; i++) {
		check[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		if (!findParent(check, n[i].node[0]-1, n[i].node[1]-1)) {
			unionParent(check, n[i].node[0]-1, n[i].node[1]-1);
			sum += n[i].distance;
		}
	}

	cout << sum;

	return 0;
}