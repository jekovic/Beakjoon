#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 9

using namespace std;


vector<int> a[MAX];
int n, m;
bool visited[MAX];
int result[MAX];
void dfs( int cnt) {

	if (cnt == m) {
		//cout << '\n';
		
		
		for (int i = 0; i < m; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == true) {
			continue;
		}
		
		visited[i] = true;
		result[cnt] = i;
		dfs(cnt + 1);
		visited[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//int n, m;
	cin >> n >> m;

	dfs(0);

	return 0;
}