#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;
int T, W;
vector<int> tree;
vector<vector<vector<int>>> d;
int result;

void input() {
	cin >> T >> W;
	// 현재 위치 -- 남은 이동횟수 -- 현재 시간
	d.assign(3, vector<vector<int>>(W+1, vector<int>(T+1, -1)));
	tree.assign(T + 1, 0);

	for (int i = 1; i <= T; i++) {
		cin >> tree[i];
	}
}

void dp() {
	d[1][W][0] = 0;

	for (int time = 0; time < T; time++) {
		for (int cnt = 0; cnt <= W; cnt++) {
			for (int pos = 1; pos <= 2; pos++) {
				if (d[pos][cnt][time] >= 0) {
					int nextpos = tree[time + 1]; // 떨어지는 위치 

					if (pos == nextpos) { // 현재위치 
						d[pos][cnt][time + 1] = d[pos][cnt][time] + 1;
					}
					else {
						if (cnt != 0) { // 이동할 경우
							d[nextpos][cnt - 1][time + 1] = max(d[pos][cnt][time] + 1, d[nextpos][cnt - 1][time + 1]);
						}
						d[pos][cnt][time + 1] = d[pos][cnt][time];
					}
				}
			} 
		}
	}


	int ret = 0;
	for (int pos = 1; pos <= 2; pos++) {
		for (int time = 1; time <= T; time++) {
			ret = max(ret, d[pos][0][time]);
		}
		for (int i = 0; i <= W; i++) {
			ret = max(ret, d[pos][i][T]);
		}
	}
	result = ret;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dp();

	cout << result;

	return 0;
}