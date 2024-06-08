#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 32001

using namespace std;

int isDegree[MAX];
int n;

vector<int> a[MAX];

void topology_sort()
{
	int res[MAX];
	
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (isDegree[i] == 0) {
			pq.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pq.empty()) {
			return;
		}
		
		int x = pq.top();
		pq.pop();
		res[i] = x;

		for (int j = 0; j != a[x].size(); j++) {
			int y = a[x][j];
			if (--isDegree[y] == 0) {
				pq.push(y);
			}
		}
	}

	for (int i = 1; i <= n;i++) {
		cout << res[i] << ' ';
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> n >> k;

	for (int t = 0; t < k; t++) {
		int z, c;
		cin >> z >> c;
		a[z].push_back(c);
		isDegree[c]++;
	}
	
	topology_sort();


	return 0;
}