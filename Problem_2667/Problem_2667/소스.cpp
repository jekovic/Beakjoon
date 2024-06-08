#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 26

using namespace std;

int a[MAX][MAX];
bool visited[MAX][MAX];
int n;
int cnt;
int dx[4] = { 1, -1, 0, 0}; 
int dy[4] = { 0, 0, 1, -1};
vector < pair<int, int> > point;
vector<int> res;

void dfs(int q, int w) {

	for (int i = 0; i < 4; i++) {
		int x = q + dx[i];
		int y = w + dy[i];
		if (a[x][y] == 1 && x >= 1 && y >= 1 && visited[x][y] == false && x <= n && y <= n) {
			visited[x][y] = true;
			cnt++;
			dfs(x, y);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j-1] - 48;
		}
	}


	for (int f = 1; f <= n; f++) {
		for (int g = 1; g <= n; g++) {
			if (visited[f][g] == false && a[f][g] == 1) {
				cnt = 1;
				visited[f][g] = true;
				dfs(f, g);
				res.push_back(cnt);
			}
		}
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (int i = 0; i != res.size(); i++) {
		cout << res[i] << '\n';
	}

	return 0;
}