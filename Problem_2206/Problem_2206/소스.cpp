#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 1001

using namespace std;
/*
	1. 그냥 이동하는 것의 경로
	2. 벽 중 하나를 선택해 그것을 부시고 갔을 때의 경로
*/
int N, M;
int map[MAX][MAX];
vector<pair<int, int>> wall;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int walk = 0;

vector<int> result;

void break_wall() {
	for (int i = 0; i != wall.size(); i++) {
		int temp[MAX][MAX];
		
		for (int q = 0; q < N; q++) {
			for (int w = 0; w < M; w++) {
				temp[q][w] = map[q][w];
			}
		}
		int cx = wall[i].first;
		int cy = wall[i].second;
		temp[cx][cy] = 0;

		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		temp[0][0] = 1;

		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (temp[nx][ny] == -1) continue;
				temp[nx][ny] = temp[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
		walk = min(walk,temp[N - 1][M - 1]);
	}
}

void bfs() {
	int temp[MAX][MAX];
	for (int q = 0; q < N; q++) {
		for (int w = 0; w < M; w++) {
			temp[q][w] = map[q][w];
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	temp[0][0] = 1;
	

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (temp[nx][ny] == -1) continue;
			temp[nx][ny] = temp[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}
	if (temp[N - 1][M - 1] == 0) {
		walk = -1;
		return;
	}
	walk = temp[N - 1][M - 1];
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			int t = s[j] - '0';
			map[i][j] = t;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				wall.push_back({ i, j });
				map[i][j] = -1;
			}
		}
	}


	bfs();

	if (walk != -1) {
		break_wall();
	}

	cout << walk;

	return 0;
}