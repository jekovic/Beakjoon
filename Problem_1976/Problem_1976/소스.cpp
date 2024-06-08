#include <iostream>
#include <vector>
#define MAX 201
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				unionparent(p, i, j);
			}
		}
	}

	bool ok = true;
	int k;
	cin >> k;
	for (int i = 1; i < m; i++) {
		int t;
		cin >> t;
		int res = findparent(p, k, t);
		if (res == 0) ok = false;
		k = t;
	}

	if (ok == true) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}