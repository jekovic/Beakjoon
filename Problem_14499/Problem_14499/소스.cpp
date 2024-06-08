#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;
int n, m;

//동쪽 1  - 서쪽 2 - 북쪽 3 - 남쪽 4
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int map[MAX][MAX];
vector<int> com;
int dice[4][3];
int x, y;
int upper;

/*
	바닥에 있는 숫자 넣고 upper 고쳐주기
*/
void dice_status(int d) {
	if (d == 1) //  동쪽
	{
		x += dx[0];
		y += dy[0];
		if (y >= m) {
			y -= dy[0];
			return;
		}
		int a, b, c, d;
		a = dice[1][0];
		b = dice[1][1];
		c = dice[1][2];
		d = dice[3][1];
		dice[1][0] = d;
		dice[1][1] = a;
		dice[1][2] = b;
		dice[3][1] = c;

		if (map[x][y] == 0) {
			map[x][y] = dice[3][1];
		}
		else {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}

	}
	else if (d == 2) { //  서쪽
		x += dx[1];
		y += dy[1];
		if (y < 0) {
			y -= dy[1];
			return;
		}
		int a, b, c, d;
		a = dice[1][0];
		b = dice[1][1];
		c = dice[1][2];
		d = dice[3][1];
		dice[1][0] = b;
		dice[1][1] = c;
		dice[1][2] = d;
		dice[3][1] = a;
		if (map[x][y] == 0) {
			map[x][y] = dice[3][1];
		}
		else {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}

	}
	else if (d == 3) {// 북
		x += dx[2];
		y += dy[2];
		if (x < 0 ) {
			x -= dx[2];
			return;
		}
		
		int a, b, c, d;
		a = dice[0][1];
		b = dice[1][1];
		c = dice[2][1];
		d = dice[3][1];
		dice[0][1] = b;
		dice[1][1] = c;
		dice[2][1] = d;
		dice[3][1] = a;
		if (map[x][y] == 0) {
			map[x][y] = dice[3][1];
		}
		else {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (d == 4) {	//남
		x += dx[3];
		y += dy[3];
		if (x >= n){
			x -= dx[3];
			return;
		}
		
		int a, b, c, d;
		a = dice[0][1];
		b = dice[1][1];
		c = dice[2][1];
		d = dice[3][1];
		dice[0][1] = d;
		dice[1][1] = a;
		dice[2][1] = b;
		dice[3][1] = c;
		if (map[x][y] == 0) {
			map[x][y] = dice[3][1];
		}
		else {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}
	}
	upper = dice[1][1];
	cout << upper << '\n';
	return;
}

//주사위 굴리기
void roll()
{
	for (int i = 0; i != com.size(); i++) {
		dice_status(com[i]);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int command;
	
	cin >> n >> m >> x >> y >> command;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (command--) {
		int c;
		cin >> c;
		com.push_back(c);
	}

	roll();

	return 0;
}