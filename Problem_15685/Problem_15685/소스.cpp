#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 101

using namespace std;
/*
	1. 좌표가 주어지면 드래곤 커브를 그림
	2. 맵에서 드래곤 커브인 좌표인 경우 시계방향으로 돌면서 
		모든 좌표가 드래곤 커브라면 결과++
*/

int map[102][102];
int result;
// right -- up -- left -- down
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

/*
	[좌표 회전 방법]
	1. 일단 회전 후 끝점끼리 같아지는 수 찾기
	2. 모든 좌표 그 수 더하기
*/
void clock_wise(vector<pair<int, int>>& v) {	//끝점 제외 좌표 회전해서 붙이기
	vector<pair<int, int>> temp;
	for (int i = 0; i != v.size(); i++) {
		int cy = v[i].first;
		int cx = v[i].second;
		
		temp.push_back({ cx, -cy });
	}
	
	int a = v.back().first - temp.back().first;
	int b = v.back().second - temp.back().second;
	
	for (int i = 0; i != temp.size(); i++) {
		temp[i].first += a;
		temp[i].second += b;
	}
	for (int i = temp.size() - 2; i >= 0; i--) {
		v.push_back({ temp[i].first, temp[i].second });
	}
}

//드래곤 커브 그리기
void draw_dragon(int y, int x, int d, int g) {
	vector<pair<int, int>> dr;
	dr.push_back({ y, x });

	dr.push_back({ y + dy[d], x + dx[d]});
	
	if (g > 0) {
		for (int i = 0; i < g; i++) {
			clock_wise(dr);
		}
	}
	
	//좌표에 표시
	for (int i = 0; i < dr.size(); i++) {
		int ny = dr[i].first;
		int nx = dr[i].second;
		if( nx >=0 and nx<=100 and ny >=0 and ny<= 100)
			map[dr[i].first][dr[i].second] = 1;	
	}
}

//map을 시계방향으로 돌면서 결과 카운트
void count_res() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 and map[i + 1][j] == 1 and map[i][j + 1] == 1 and map[i + 1][j + 1] == 1)
				result++;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		draw_dragon(y, x, d, g);
	}
	
	count_res();

	cout << result;

	return 0;
}