#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int R, C, K;
int A[100][100];
int garo, sero;

void R_Cal() {	// 가로
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	int max_col = 0;

	for (int i = 0; i != sero; i++) {
		vector<int> cnt(101, 0);
		for (int j = 0; j != garo; j++) {
			cnt[A[i][j]]++;
			A[i][j] = 0;
		}
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] != 0) {
				pq.push({ cnt[i], i });
			}
		}
		
		vector<int> tmp;
		while (!pq.empty()) {
			int num = pq.top().second;
			int count = pq.top().first;
			pq.pop();

			tmp.push_back(num);
			tmp.push_back(count);
		}

		for (int j = 0; j != tmp.size(); j++) {
			A[i][j] = tmp[j];
		}

		int t = tmp.size();
		max_col = max(max_col, t);
	}
	garo = max_col;
}

void C_Cal() {	//세로

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	int max_col = 0;

	for (int i = 0; i != garo; i++) {
		vector<int> cnt(101, 0);
		for (int j = 0; j != sero; j++) {
			cnt[A[j][i]]++;
			A[j][i] = 0;
		}
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] != 0) {
				pq.push({ cnt[i], i });
			}
		}
		//열 초기화
		vector<int> tmp;
		while (!pq.empty()) {
			int num = pq.top().second;
			int count = pq.top().first;
			pq.pop();

			tmp.push_back(num);
			tmp.push_back(count);
		}

		for (int j = 0; j != tmp.size(); j++) {
			A[j][i] = tmp[j];
		}

		int t = tmp.size();
		max_col = max(max_col, t);
	}
	sero = max_col;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> K;
	R--; C--;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	garo = 3;
	sero = 3;

	int time = 0;
	while (1) {
		if (A[R][C] == K) {
			cout << time;
			return 0;
		}
		if (time == 100) break;


		if (garo <= sero) {
			R_Cal();
		}
		else {
			C_Cal();
		}
		time++;
	}
	
	if (A[R][C] != K) {
		cout << -1;
	}
	else {
		cout << time;
	}

	return 0;
}