#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int visited[MAX];
int cnt;
vector<int> a[MAX];

void dfs(int start) {
	if (visited[start]) return;
	visited[start] = true;
	cnt++;

	for (int i = 0; i < a[start].size(); i++) {
		int y = a[start][i];
		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int k; 
	cin >> k;

	for (int i = 0; i < k; i++) {
		int q, w;
		cin >> q >> w;
		a[q].push_back(w);
		a[w].push_back(q);
	}

	dfs(1);

	cout << cnt - 1;

	return 0;
}