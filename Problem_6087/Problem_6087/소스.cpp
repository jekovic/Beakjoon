#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 100
const int INF = 1e9;

using namespace std;

//H 가 가로->x
//W 가 세로 ->y 
int W, H;
vector<vector<char>> map;
vector<vector<vector<int>>> visited;
vector<vector<vector<int>>> v;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> laser;
int result = INF;

void input() {
	cin >> W >> H;
	map.assign(H, vector<char>(W, '0'));
	visited.assign(H, vector<vector<int>>(W, vector<int>(4, INF)));
	v.assign(H, vector<vector<int>>(W, vector<int>(4, 0)));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				laser.push_back({ i, j });
			}
			//visited[i][j] = 987654321;
		}
	}
}

void bfs() {
	//memset(visited, 0x3f, sizeof(visited));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int i = 0; i < 4; i++) {
		q.push({ { laser[0].first, laser[0].second }, {i, 0} });
		visited[laser[0].first][laser[0].second][i] = 0;
		v[laser[0].first][laser[0].second][i] = 1;
	}

	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int di = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int ncnt = cnt;

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;		
			if (map[nx][ny] == '*') continue;
			if (di != i) ncnt = ncnt + 1;
			if (visited[nx][ny][i] > ncnt) {
				v[nx][ny][i] = 1;
				visited[nx][ny][i] = ncnt;
				q.push({ { nx, ny }, {i, ncnt} });
			};
		}
	}

	for (int i = 0; i < 4;i++) {
		if(visited[laser[1].first][laser[1].second][i])
			result = min(result, visited[laser[1].first][laser[1].second][i]);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bfs();
	
	cout << result;

	return 0;
}