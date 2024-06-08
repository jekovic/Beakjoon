#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>
#include <cstring>
#define MAX 17

using namespace std;

int N, M, D;
int map[MAX][MAX];
int c_map[MAX][MAX];
int result;
bool visited[MAX];
int killed;

void input() {
	cin >> N >> M >> D;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

// 궁수 위치 배치
// D 이하인 거리에 있는 적 제외
// 턴 종료 후 적 아래로 내림
// 위 과정 반복
//반복시) 맵 복사하는 것, 

void copy_map() {
	for (int i = 1; i <= N+1; i++) {
		for (int j = 1; j <= M; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}

void cattle_down() {
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= M; j++) {
			if (i == N) {
				if (c_map[i][j] == 1) {
				}
				c_map[i][j] = 0;
			}
			else if (c_map[i][j] == 1) {
				c_map[i + 1][j] = c_map[i][j];
				c_map[i][j] = 0;
			}
		}
	}
}

int count_vic() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (c_map[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}

//거리 계산하기 -> 가장 거리가 가까운 자표 찾기
void find_dis() {
	set<pair<int, int>> s;

	for (int q = 1; q <= M; q++) {
		if (c_map[N + 1][q] != -1) continue;
		int d = 1e9;
		int sx = N;
		int sy = M;
		bool check = true;

		for (int i = N; i >= 1; i--) {
			for (int j = 1; j <= M; j++) {
				if (c_map[i][j] == 1) {
					int dis = abs(N + 1 - i) + abs(q - j);
					if (dis <= D) {
						if (dis < d) {
							d = dis;
							sx = i;
							sy = j;
							check = false;
						}
						else if (dis == d) {
							if (sy > j) {
								sx = i;
								sy = j;
							}
							check = false;
						}
					}
				}
			}
		}
		if (check == false) {
			s.insert({ sx, sy });
			//c_map[sx][sy] = 0;
		}		
	}
	for (const auto& e : s) {
		c_map[e.first][e.second] = 0;
	}
	killed += s.size();
}

void fix_archer(int cnt) {
	//1부터 M중의 숫자 중 3개 뽑기
	if (cnt == 3) {

		copy_map();
		killed = 0;

		for (int i = 1; i <= M; i++) {
			if (visited[i]) {
				c_map[N + 1][i] = -1;
			}
		}

		while (1) {
			if (count_vic() <= 0)
				break;

			find_dis();

			cattle_down();
		}

		result = max(result, killed);

		return;
	}

	for (int i = 1; i <= M; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		fix_archer( cnt + 1);
		visited[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	fix_archer(0);

	cout << result;

	return 0;
}