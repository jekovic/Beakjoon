#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

vector<int> parent, friends;

int getparent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getparent(parent[x]);
}

void unionparent(int x, int y) {
	x = getparent(x);
	y = getparent(y);

	if (x < y) {
		parent[y] = x;
		friends[x] += friends[y];
	}
	else {
		parent[x] = y;
		friends[y] += friends[x];
	}
}

void initparent(int n) {
	parent.assign(n * 2 + 1, 0);
	friends.assign(n * 2 + 1, 1);

	for (int i = 0; i <= n * 2; i++) {
		parent[i] = i;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		m.clear();

		int n;
		cin >> n;
		initparent(n);
		
		int idx = 0;
		int f1, f2 = 0;

		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;

			if (m.count(s1) == 0) {
				m[s1] = ++idx;
				f1 = idx;
			}
			else {
				f1 = m[s1];
			}

			if (m.count(s2) == 0) {
				m[s2] = ++idx;
				f2 = idx;
			}
			else {
				f2 = m[s2];
			}

			unionparent(f1, f2);
			int res = getparent(f1);
			cout << friends[res] << '\n';
		}
	}

	return 0;
}