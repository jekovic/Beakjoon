#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 21


using namespace std;
int A[MAX][MAX];		// 인구수 -> fixed
int elect[MAX][MAX];	// 선거구
int N;
int result = 987654321;
int d1 = 1;
int d2 = 1;

bool valid_check(int x, int y, int d1, int d2) {
	int x0 = x, y0 = y;
	int x1 = x + d1, y1 = y - d1;
	int x2 = x + d1 + d2, y2 = y - d1 + d2;
	int x3 = x + d2, y3 = y + d2;

	if (x1 > N || y1 < 1) return false;
	if (x2 > N || y2 > N) return false;
	if (x3 > N || y3 > N) return false;
	if (x3 > N || y3 < 1) return false;
	else return true;
}

void cal_human() {
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	vector<int> temp;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (elect[i][j] == 1) {
				one += A[i][j];
			}
			else if (elect[i][j] == 2) {
				two += A[i][j];
			}
			else if (elect[i][j] == 3) {
				three += A[i][j];
			}
			else if (elect[i][j] == 4) {
				four += A[i][j];
			}
			else if (elect[i][j] == 5) {
				five += A[i][j];
			}
		}
	}

	temp.push_back(one);
	temp.push_back(two);
	temp.push_back(three);
	temp.push_back(four);
	temp.push_back(five);
	sort(temp.begin(), temp.end());
	int res = temp[4] - temp[0];

	result = min(res, result);
}

void make_elect_district(int x, int y, int d1, int d2) {

	int x0 = x, y0 = y;
	int x1 = x + d1, y1 = y - d1;
	int x2 = x + d1 + d2, y2 = y - d1 + d2;
	int x3 = x + d2, y3 = y + d2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {				
			elect[i][j] = 5;
		}
	}

	//1
	int end = y0;
	for (int i = 1; i < x1; i++) {
		if (i >= x0) end--;
		for (int j = 1; j <= end; j++) {
			elect[i][j] = 1;
		}
	}

	//2
	int start = y0 + 1;
	for (int i = 1; i <= x3; i++) {
		if (i > x0) start++;
		for (int j = start; j <= N; j++) {
			elect[i][j] = 2;
		}
	}

	//3
	end = y1 - 1;
	for (int i = x1; i <= N; i++) {
		for (int j = 1; j <= end; j++) {
			elect[i][j] = 3;
		}
		if (end < y2 - 1) {
			end++;
		}
	}

	//4
	start = y3;
	for (int i = x3 + 1; i <= N; i++) {
		for (int j = start; j <= N; j++) {
			elect[i][j] = 4;
		}
		if (start > y2) {
			start--;
		}
	}

	return;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (valid_check(i, j, d1, d2)) {
						make_elect_district(i, j, d1, d2);
						cal_human();
					}
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	solve();

	cout << result;

	return 0;
}