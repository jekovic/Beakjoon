#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 21

using namespace std;
int N, M, fuel;
int taxi_x, taxi_y;
int map[MAX][MAX];
int x[] = { 0, 0, 1, -1 };
int y[] = { 1, -1, 0, 0 };

class customer {
public:
	int sx, sy, dx, dy;
	int dis;
	bool completed;
	customer(int x_, int y_, int x__, int y__) {
		this->sx = x_;
		this->sy = y_;
		this->dx = x__;
		this->dy = y__;
		this->completed = false;
		this->dis = 0;
	}
};

vector<customer> c;
int visited[MAX][MAX];

bool compare(customer& a, customer& b) {
	if (a.dis == b.dis) {
		if (a.sx == b.sx) {
			return a.sy < b.sy;
		}
		else {
			return a.sx < b.sx;
		}
	}
	else {
		return a.dis < b.dis;
	}
}


void bfs(int sx, int sy) {

	for (int q = 0; q < N; q++) {
		for (int w = 0; w < N; w++) {
			visited[q][w] = map[q][w];
		}
	}

	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + x[i];
			int ny = cy + y[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] == -1) continue;
			if (visited[nx][ny] > 0) continue;
			visited[nx][ny] =  visited[cx][cy] + 1;
			q.push({ nx, ny });
		}
	}
} 

void cal_dis() {

	while (c.size() != 0) {
		bfs(taxi_x, taxi_y);

		for (int i = 0; i != c.size(); i++) {
			c[i].dis = --visited[c[i].sx][c[i].sy];
			if (c[i].dis <= -1) {
				fuel = -1;
				return;
			}			
		}
		sort(c.begin(), c.end(), compare);

		bfs(c[0].sx, c[0].sy);

		int dis = --visited[c[0].dx][c[0].dy];
		if (dis <= -1) {
			fuel = -1;
			return;
		}
		int sum_ = c[0].dis + dis;
		if (fuel - sum_ < 0) {
			fuel = -1;
			return;
		}
		else {
			taxi_x = c[0].dx;
			taxi_y = c[0].dy;
			fuel += dis * 2 - sum_;
			c.erase(c.begin());
		}
	}	
}

void input() {
	cin >> N >> M >> fuel;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}

	cin >> taxi_x >> taxi_y;
	taxi_x--; taxi_y--;

	for (int i = 0; i < M; i++) {
		int q, w, e, r;
		cin >> q >> w >> e >> r;
		q--; w--; e--; r--;
		c.push_back(customer(q, w, e, r));
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	cal_dis();

	if (fuel == -1) {
		cout << fuel;
	}
	else {
		cout << fuel;
	}
	
	return 0;
}