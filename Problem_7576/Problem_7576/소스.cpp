#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;
int N, M;

int tomato[MAX][MAX];
int result = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<pair<int, int>> t;

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i != t.size(); i++) {
		q.push({ t[i].first, t[i].second });
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];


			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (tomato[nx][ny] == -1 || tomato[nx][ny] >= 1) continue;
			tomato[nx][ny] =  tomato[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}
}

int max_num = 0;

int count_tmt() {
	int cnt = 0;
	
	for (int i = 0; i < M;i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 0) {
				cnt++;
			}
			max_num = max(max_num, tomato[i][j]);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M;i++) {
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				t.push_back({ i,j });
			}
		}
	}

	if (count_tmt() == 0) {
		cout << 0;
		return 0;
	}

	bfs();

	if (count_tmt() == 0) {
		cout << max_num - 1;
		return 0;
	}
	else {//가장 큰 숫자 표시
		cout << -1;
	}

	return 0;
}