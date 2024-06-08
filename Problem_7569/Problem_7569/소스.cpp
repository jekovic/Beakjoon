#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101

using namespace std;

//z, x, y
int d[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
int N, M, H;
//N이 x , M이 y

//z // x// y
//int map[MAX][MAX][MAX];
class point {
public:
	int z;
	int x;
	int y;
	point(int q, int w, int e) {
		this->z = q;
		this->x = w;
		this->y = e;
	}
};
int day = 0;
vector<point> tomato;

bool count_tomato(vector<vector<vector<int>>>& map) {
	int ret = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == -2) {
					ret++;
				}
			}
		}
	}

	if (ret == 0) { // 더 익을 토마토 없음;
		return false;
	}
	else {
		return true;
	}

}

int bfs(vector<vector<vector<int>>>& map) {
	queue<point> q;
	for (int i = 0; i != tomato.size(); i++) {
		q.push(point(tomato[i].z, tomato[i].x, tomato[i].y));
	}
	
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = cz + d[i][0];
			int nx = cx + d[i][1];
			int ny = cy + d[i][2];

			if ( nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (map[nz][nx][ny] == -1 || map[nz][nx][ny] >= 1) continue;
			if (map[nz][nx][ny] == -2) {
				map[nz][nx][ny] = map[cz][cx][cy] + 1;
				day = max(day, map[nz][nx][ny]);
				q.push(point(nz, nx, ny));
			}
		}
	}
	
	if (count_tomato(map) != 0) {
		return -1;
	}
	else {
		return day;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;

	vector<vector<vector<int>>> map(H, vector<vector<int>>(N, vector<int>(M, 0)));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int t;
				cin >> t;
				if (t == 0) {
					t = -2;
				}
				else if (t == 1) {
					tomato.push_back(point(i, j, k));
					t = 0;

				}
				map[i][j][k] = t;
			}
		}
	}

	if (!count_tomato(map)) {
		cout << 0;
		return 0;
	}
	else {
		cout << bfs(map);
	}


	return 0;
}