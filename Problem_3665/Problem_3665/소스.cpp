#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;

int n, isDegree[MAX];
vector<int> a[MAX];
int ranking[MAX];
int res[MAX];
int cnt[MAX];
vector<int> te;

int find_idx(int k) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (res[i] == k) {
			ret = i;
			break;
		}
	}
	return ret;
}

void topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (isDegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "IMPOSSIBLE" << '\n';
			return;
		}
		else if (q.size() > 1) {
			cout << '?' << '\n';
			return;
		}

		int x = q.front();
		q.pop();
		res[i] = x;
		for (int j = 0; j != a[x].size(); j++) {
			int y = a[x][j];
			if (--isDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> n;
		//√ ±‚»≠
		for (int i = 1; i <= n; i++) {
			isDegree[i] = 0;
			cnt[i] = 0;
			a[i].clear();
			ranking[i] = 0;
		}
		te.clear();

		for (int i = 1; i <= n; i++) {
			cin >> ranking[i];
		}


		int f = n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= f - 1; j++) {
				a[ranking[i]].push_back(ranking[i + j]);
				isDegree[ranking[i + j]]++;
			}
			f--;
		}

		int change;
		cin >> change;
		if (change == 0) {
			for (int i = 1;i <= n; i++) {
				cout << ranking[i] << ' ';
			}
			cout << '\n';
			continue;
		}

		for (int i = 0; i < change; i++) {
			int q, w;
			cin >> q >> w;
			bool ok = false;
			for (int j = 0; j < a[q].size(); j++) {
				if (a[q][j] == w) {
					ok = true;
				}
			}
			if (ok == true) {
				for (int j = 0; j < a[q].size(); j++) {
					if (a[q][j] == w) {
						a[q].erase(a[q].begin() + j);
					}
				}
				a[w].push_back(q);
				isDegree[q]++;
				isDegree[w]--;
			}
			else {
				for (int j = 0; j < a[w].size(); j++) {
					if (a[w][j] == q) {
						a[w].erase(a[w].begin() + j);
					}
				}
				a[q].push_back(w);
				isDegree[q]--;
				isDegree[w]++;
			}
		}

		topology_sort();

	}

	return 0;
}