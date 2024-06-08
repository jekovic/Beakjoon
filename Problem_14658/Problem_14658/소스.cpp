#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

//x, y 역전 문제
using namespace std;

int N, M, L, K;
//vector<vector<int>> v;
int result;
vector<pair<int, int>> v;

void input() {
	for (int i = 0; i < K; i++) {
		int q, w;
		cin >> q >> w;
		//v[w][q] = 1;
		v[i] = { w,q };
	}
}

void count_star() {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int cnt = 0;
			int x = v[i].first;
			int y = v[j].second;
			for (int t = 0; t < K; t++) {
				int nx = v[t].first;
				int ny = v[t].second;
				if (x <= nx and x + L >= nx and y <= ny and y + L >= ny) cnt++;
			}
			result = max(result, cnt);
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> L >> K;
	
	//vector<vector<int>> temp(M + 1, vector<int>(N + 1, 0));
	vector<pair<int, int>> temp(K);
	v = temp;

	input();

	count_star();

	cout <<  K - result;


	return 0;
}