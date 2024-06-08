/*
	ref) https://js1jj2sk3.tistory.com/3
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define INF 1e9
#define MAX 501

using namespace std;

int T, K;
vector<int> chapter;
vector<vector<int>> d;

void input() {
	cin >> K;
	chapter.assign(K+1, 0);
	d.assign(K+1, vector<int>(K+1, 0));	//i부터 j 까지 더하는 최소 값 저장

	for (int i = 1; i <= K; i++) {
		int q;
		cin >> q;
		
		chapter[i] = chapter[i - 1] + q;
	}
}

void init() {
	chapter.clear();
	for (int i = 0; i <= K; i++) {
		d[i].clear();
	}
	d.clear();
}

void dp() {
	for (int i = 1; i < K; i++) {
		for (int t = 1; t + i <= K; t++) {
			int y = t + i;
			d[t][y] = 1e9;
			for (int mid = t; mid < y; mid++) {
				d[t][y] = min(d[t][y], d[t][mid] + d[mid + 1][y] + chapter[y] - chapter[t - 1]);
			}
		}
	}
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {

		input();

		dp();

		cout << d[1][K] << '\n';

		init();
	}

	return 0;
}