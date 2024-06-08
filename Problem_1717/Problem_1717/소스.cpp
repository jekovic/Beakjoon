#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

int p[MAX];

int getparent(int* parent, int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = getparent(parent, parent[a]);
}

void unionparent(int* parent, int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findparent(int* parent, int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);

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

	while (m--) {
		int q, w, e;
		cin >> q >> w >> e;
		if (q == 0) {
			unionparent(p, w, e);
		}
		else if (q == 1) {
			int res = findparent(p, w, e);
			if (res == 1) {
				cout << "YES" << '\n';
			}
			else if (res == 0) {
				cout << "NO" << '\n';
			}
		}
	}

	
	return 0;

}