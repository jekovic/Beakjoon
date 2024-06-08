#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX 1001

using namespace std;

int N, M;
int map[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct t {
	int d, x, y;
};

int bfs(vector<vector<vector<int>>>& v) {
	queue <t> q;
	t temp;
	temp.x = temp.y = temp.d = 0;
	q.push(temp);

	while (!q.empty()) {
		int di = q.front().d;
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int distance = v[di][cx][cy] + 1;

			if (nx == N - 1 and ny == M - 1) {
				return distance + 1;
			}

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == 1 and di == 0 and v[1][nx][ny] == -1) {//벽일때, 
				t tmp;
				tmp.x = nx;
				tmp.y = ny;
				tmp.d = 1;
				q.push(tmp);
				v[1][nx][ny] = distance;
			}
			if (map[nx][ny] == 0 and v[di][nx][ny] == -1) { //벽이 아닐 때
				t tmp;
				tmp.x = nx;
				tmp.y = ny;
				tmp.d = di;
				q.push(tmp);
				v[di][nx][ny] = distance;
			}
		}
	}
	return -1;
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
	vector<vector<vector<int>>> v(2, vector<vector<int>>(N, vector<int>(M, -1)));
	v[0][0][0] = 0;
	if (N == 1 and M == 1) cout << 1;
	else cout << bfs(v);
	
	return 0;
}