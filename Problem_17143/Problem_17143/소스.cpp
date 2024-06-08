#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

int r, c, m;
int map[MAX][MAX];
int sz[MAX][MAX];
//	1:up -> 2: down -> 3: right -> 4: left 
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

class shark {
public:
	int x, y, speed, direct, size;
	shark(int q, int w, int e, int r, int t) {
		this->x = q;
		this->y = w;
		this->speed = e;
		this->direct = r;
		this->size = t;
	}
};
vector<shark> sh[MAX][MAX];

int result;


//상어 움직임 -> vector 만 수정 and 상어 크기고려해서 잡아먹기
//방향만 고려

int change_dir(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
}

bool judge_area(int x, int y) {
	return 0 < x and x <= r and y > 0 and y <= c;
}

void s_moving() {

	vector<shark> newsh[MAX][MAX];

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (sh[i][j].empty()) {
				continue;
			}
			shark cur = sh[i][j][0];
			sh[i][j].pop_back();

			int& cur_x = cur.x;
			int& cur_y = cur.y;
			int cur_speed = cur.speed;
			int& cur_d = cur.direct;

			while (cur_speed--) {
				int nx = cur_x + dx[cur_d];
				int ny = cur_y + dy[cur_d];
				if (!judge_area(nx, ny)) {
					cur_d = change_dir(cur_d);
				}
				cur_x += dx[cur_d];
				cur_y += dy[cur_d];
			}
			if (!newsh[cur_x][cur_y].empty()) {
				if (newsh[cur_x][cur_y][0].size < cur.size) {
					newsh[cur_x][cur_y].pop_back();
					newsh[cur_x][cur_y].push_back(cur);
				}
			}
			else {
				newsh[cur_x][cur_y].push_back(cur);
			}
		}
	}
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			sh[i][j] = newsh[i][j];
		}
	}
}

void pick() {
	for (int t = 1; t <= c; t++) {
		for (int i = 1; i <= r; i++) {
			if (!sh[i][t].empty())
			{
				result += sh[i][t][0].size;
				sh[i][t].pop_back();
				break;
			}
		}
		//상어 움직이기
		s_moving();
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> m;
	
	for (int i = 0; i < m; i++) {
		int q, w, e, y, t;
		cin >> q >> w >> e >> y >> t;
		if (y == 1 || y == 2) {
			e %= ((r - 1) * 2);
		}
		else if (y == 3 || y == 4) {
			e %= ((c - 1) * 2);
		}
		sh[q][w].push_back(shark(q, w, e, y, t));
	}

	pick();

	cout << result;

	return 0;
}