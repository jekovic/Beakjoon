#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 51

using namespace std;

class fireball {
public:
	int x, y;
	int m, s, d;
	fireball() {}
	fireball(int q, int w, int e, int r, int t) {
		this->x = q;
		this->y = w;
		this->m = e;
		this->s = r;
		this->d = t;
	}
};
vector<fireball> f;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int N, M, K;

vector<fireball> map[MAX][MAX];

int count_ball() {
	int res = 0;
	for (int i = 0; i != f.size(); i++) {
		res += f[i].m;
	}
	return res;
}

void fireball_move() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j].clear();
		}
	}
	
	for (int i = 0; i != f.size(); i++) {
		int cx = f[i].x;
		int cy = f[i].y;
		int cd = f[i].d;
		int cs = f[i].s % N;
		int cm = f[i].m;
		int nx = cx + dx[cd] * cs;
		int ny = cy + dy[cd] * cs;
		if (nx > N ) {
			nx -= N;
		}
		if (ny > N) {
			ny -= N;
		}
		if (nx < 1) {
			nx += N;
		}
		if (ny < 1) {
			ny += N;
		}
		map[nx][ny].push_back(fireball(nx, ny, cm, f[i].s, cd));
		f[i].x = nx;
		f[i].y = ny;
	}
}

void fireball_add() {
	vector<fireball> temp;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].size() == 0) continue;
			if (map[i][j].size() == 1)
			{
				temp.push_back(map[i][j][0]);
				continue;
			}

			int sz = map[i][j].size();
			int temp_m = 0;
			int temp_s = 0;
			
			bool odd = true;
			bool even = true;
			for (int t = 0; t != sz; t++) {
				temp_m += map[i][j][t].m;
				temp_s += map[i][j][t].s;
				if (map[i][j][t].d % 2 == 0) odd = false;
				else even = false;
			}

			temp_m /= 5;
			temp_s /= sz;
			if (temp_m == 0) continue;
			if (odd == true or even == true) {
				int td = 0;
				for (int t = 0; t < 4; t++) {
					temp.push_back(fireball(i, j, temp_m, temp_s, td));
					td += 2;
				}
			}
			else {
				int td = 1;
				for (int t = 0; t < 4; t++) {
					temp.push_back(fireball(i, j, temp_m, temp_s, td));
					td += 2;
				}
			}
		}
	}
	f = temp;
}

void move() {
	for (int i = 0; i < K; i++) {
		fireball_move();
		fireball_add();
	}
}


void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int q, w, e, r, t;
		cin >> q >> w >> e >> r >> t;
		map[q][w].push_back(fireball(q, w, e, r, t));
		f.push_back(fireball(q, w, e, r, t));
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	move();

	cout << count_ball();

	return 0;
}