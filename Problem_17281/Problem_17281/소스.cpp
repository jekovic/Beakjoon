#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 9

using namespace std;

int N;
vector<vector<int>> player;
int result;
int visited[MAX];
vector<int> p;

void input() {
	cin >> N;
	player.assign(N, vector<int>(9, 0));
	p.assign(9, 0);
	//p[3] = 0; // 4번타자는 1번 
	visited[3] = true;
	p[3] = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < 9; j++) {
			cin >> player[i][j];
		}
	}
}

//1번타자는 4번으로 타순 고정
// 타순을 먼저 정해놓고 아웃카운트를 세며 이닝 차감
//각 이닝에서의 최대가 모여서 최대점수가 된다.

void cal_res() {
	int score = 0;
	int hitter = 0;
	int idx = 0;
	for (int inning = 0; inning < N; inning++)
	{	
		bool base[3] = { 0, 0, 0 };
		int out = 0;
		while (out < 3) {
			int hitter = p[idx];
			int now = player[inning][hitter];
		
			if (now == 0) {
				out++;
			}
			else if (now == 1) {
				for (int t = 2; t >= 0; t--) {
					if (base[t]) {
						if (t == 2) {
							score++;
							base[t] = false;
						}
						else {
							base[t + 1] = true;
							base[t] = false;
						}
					}
				}
				base[0] = true;
			}
			else if (now == 2) {
				for (int t = 2; t >= 0; t--) {
					if (base[t]) {
						if (t >= 1) {
							score++;
							base[t] = false;
						}
						else {
							base[t + 2] = true;
							base[t] = false;
						}
					}
				}
				base[1] = true;
			}
			else if (now == 3) {
				for (int t = 2; t >= 0; t--) {
					if (base[t]) {
						score++;
						base[t] = false;
					}
				}
				base[2] = true;
			}
			else if (now == 4) {
				for (int t = 2; t >= 0; t--) {
					if (base[t]) {
						score++;
						base[t] = false;
					}
				}
				score++;
			}
			idx++;
			idx = idx % 9;
		} // end of while
	}
	result = max(result, score);
}

void make_play(int cnt) {
	if (cnt == 9) {
		cal_res();
		return;
	}
	
	for (int i = 0; i < 9; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		p[i] = cnt;
		make_play(cnt + 1);
		visited[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	make_play(1);

	cout << result;

	return 0;
}