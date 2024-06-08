#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 51

using namespace std;

int N, M, T;
vector<int> circle[MAX];
int result;
class rot {
public:
	int x, d, k;
	rot(int q, int w, int k) {
		this->x = q;
		this->d = w;
		this->k = k;
	}
};
vector<rot> r;

void count_res() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != 0)
				result += circle[i][j];
		}
	}
}

void rotate_circle_cw(int x, int k) {
	for (int i = x-1; i < N; i += x) {
		vector<int> temp;
		
		for (int j = 0; j < k; j++) {
			temp.push_back(circle[i].back());
			circle[i].pop_back();
		}
		for (int j = 0; j < k; j++) {
			circle[i].insert(circle[i].begin(), temp[j]);
		}
	}
}

void rotate_circle_ccw(int x, int k) {
	for (int i = x-1; i < N; i += x) {
		vector<int> temp;
		for (int j = 0; j < k; j++) {
			temp.push_back(circle[i].front());
			circle[i].erase(circle[i].begin());
		}
		for (int j = 0; j < k; j++) {
			circle[i].push_back(temp[j]);
		}
	}
}

vector<pair<int, int>> adjacent_point;

double cal_avg() {
	double s = 0;
	double cnt = 0.0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != 0) {
				s += circle[i][j];
				cnt += 1.0;
			}
		}
	}
	s /= cnt;

	return s;
}

void find_ad_point(int i, int j){
	//1
	if (circle[i][0] != 0) {
		if (circle[i][0] == circle[i][1]) {
			adjacent_point.push_back({ i, 0 });
			adjacent_point.push_back({ i, 1 });
		}
		else if (circle[i][0] == circle[i][M-1]) {
			adjacent_point.push_back({ i, 0 });
			adjacent_point.push_back({ i, M-1 });
		}
	}
	//2
	if (circle[i][M-1] != 0) {
		if (circle[i][M-1] == circle[i][M-2]) {
			adjacent_point.push_back({ i, M-1 });
			adjacent_point.push_back({ i, M-2 });
		}
		else if (circle[i][M - 1] == circle[i][0]) {
			adjacent_point.push_back({ i, M - 1 });
			adjacent_point.push_back({ i, 0 });
		}
	}
	//3 
	if (j >=2 and j<=M-2 and circle[i][j] != 0) {
		if (circle[i][j - 1] == circle[i][j]) {
			adjacent_point.push_back({ i, j});
			adjacent_point.push_back({ i, j - 1 });
		}
		else if (circle[i][j - 1] == circle[i][j]) {
			adjacent_point.push_back({ i, j });
			adjacent_point.push_back({ i, j + 1 });
		}
	}
	//4
	if (circle[0][j] != 0) {
		if (circle[0][j] == circle[1][j]) {
			adjacent_point.push_back({ 0, j});
			adjacent_point.push_back({ 1, j});
		}
	}
	//5
	if (circle[N-1][j] != 0) {
		if (circle[N-1][j] == circle[N-2][j]) {
			adjacent_point.push_back({ N-2, j });
			adjacent_point.push_back({ N-1, j });
		}
	}
	//6
	if (i >= 2 and i <= N - 2 and circle[i][j] != 0) {
		if (circle[i][j] == circle[i-1][j]) {
			adjacent_point.push_back({ i, j });
			adjacent_point.push_back({ i-1, j});
		}
		else if (circle[i][j] == circle[i+1][j]) {
			adjacent_point.push_back({ i, j });
			adjacent_point.push_back({ i+1, j});
		}
	}
}

// 수 지우기
void remove_num() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			find_ad_point(i, j);
		}
	}

	if (adjacent_point.size() != 0) { // 수 지우기
		for (int i = 0; i != adjacent_point.size(); i++) {
			int cx = adjacent_point[i].first;
			int cy = adjacent_point[i].second;
			circle[cx][cy] = 0;
		}
	}
	else {	// 평균 구해서 더하고 빼기 
		double avg = cal_avg();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] != 0) {
					if (circle[i][j] > avg) {
						circle[i][j]--;
					}
					else if (circle[i][j] < avg){
						circle[i][j]++;
					}
				}
				
			}
		}
	}
}

void move() {
	for (int i = 0; i != r.size(); i++) {
		int di = r[i].d;
		int k = r[i].k;
		int x = r[i].x;
		if (di == 0) rotate_circle_cw(x, k);
		if (di == 1) rotate_circle_ccw(x, k);

		remove_num();

		adjacent_point.clear();
	}
}

void input() {
	cin >> N >> M >> T;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int t;
			cin >> t;
			circle[i].push_back(t);
		}
	}
	
	for (int i = 0; i < T; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		r.push_back(rot(q, w, e));
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	move();

	count_res();

	cout << result;

	return 0;
}