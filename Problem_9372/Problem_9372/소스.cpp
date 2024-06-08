#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

int n, m;
vector<int> a[MAX];
int p[MAX];
int sum = 0;

int getparent(int a)
{
	if (p[a] == a)
		return a;
	return p[a] = getparent(p[a]);
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

void kruskal() {
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i != a[j].size(); i++) {
			if (!findparent(j, a[j][i])) {
				sum++;
				unionparent(j, a[j][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int testcase;
	cin >> testcase;

	while (testcase--) {
		cin >> n >> m;

		for (int i = 0; i <= n; i++) {
			a[i].clear();
			p[i] = i;
		}
		sum = 0;

		for (int i = 0; i < m; i++) {
			int q, w;
			cin >> q >> w;
			a[q].push_back(w);
			a[w].push_back(q);
		}

		kruskal();

		cout << sum << '\n';
	}
	

	return 0;
}