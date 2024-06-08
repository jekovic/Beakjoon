
/*
	https://www.acmicpc.net/problem/1516
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 501

int n, isDegree[MAX], result[MAX], run[MAX];
vector<int> a[MAX];

void topology_sort() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (isDegree[i] == 0) {
			result[i] = run[i];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) return;
		int x = q.front();
		q.pop();
		
		for (int j = 0;j < a[x].size(); j++) {
			int y = a[x][j];
			result[y] = max(result[y], result[x] + run[y]);
			if (--isDegree[y] == 0) {
				q.push(y);
			}
		}		
	}
	for (int k = 1; k <= n; k++) {
		cout << result[k] << '\n';
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int v;
		cin >> v;
		run[i] = v;
		while (1) {
			int k = 0;
			cin >> k;
			if (k == -1) {
				break;
			}
			isDegree[i]++;
			a[k].push_back(i);
		}
	}

	topology_sort();
	
	return 0;
}