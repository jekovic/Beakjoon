#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 32001

int n, isDegree[MAX];
vector<int> a[MAX];


void topology_sort() {
	queue<int> q;
	int res[MAX];

	for (int i = 1; i <= n; i++) {
		if (isDegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) return;

		int x = q.front();
		q.pop();
		res[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--isDegree[y] == 0) {
				q.push(y);
			}
		}	
	}
	
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int d, f;
		cin >> d >> f;
		a[d].push_back(f);
		isDegree[f]++;
	}

	topology_sort();

	return 0;
}