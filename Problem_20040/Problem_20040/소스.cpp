#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int getparent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = getparent(parent[x]);
}

void unionparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);

	if (a > b) {
		parent[b] = a;
	}
	else if (a < b)
	{
		parent[a] = b;
	} 
}

int findparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);

	if (a == b) return 1;
	else return 0;
}

void init(int n) {
	parent.assign(n, 0);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	init(n);

	for (int i = 1; i <= m;i++) {
		int q, w;
		cin >> q >> w;

		if (findparent(q, w)) {
			cout << i;
			return 0;
		}

		unionparent(q, w);

	}
	cout << 0;
	return 0;
}