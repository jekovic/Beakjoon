#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 9

using namespace std;


vector<int> a[MAX];
int n, m;
bool visited[MAX];

void dfs(int index, int cnt) {

	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == true) {
				cout << i << ' ';
			}
		}
		cout << '\n';
		return;
	}
	for (int i = index; i <= n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		dfs(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//int n, m;
	cin >> n >> m;

	dfs(1, 0);

	return 0;
}