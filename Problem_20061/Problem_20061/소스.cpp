#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int N;
class block {
public:
	int t, x, y;
	block(int q, int w, int e) {
		this->t = q;
		this->x = w;
		this->y = e;
	}
};
vector<block> B;

int score;
int cnt;

int blue[4][6];
int green[6][4];

void cal_cnt() {
	//count blue
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blue[i][j] != 0) {
				cnt++;
			}
		}
	}
	//count green
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] != 0) {
				cnt++;
			}
		}
	}
}

//특별칸처리
void special_blue() {
	int c = 0;
	for (int i = 0; i < 2; i++) {
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] != 0) {
				flag = false;
			}
		}
		if (flag == false)
			c++;
	}
	//c만큼 오른쪽으로 땡기기
	for (int t = 0; t < c; t++) {
		for (int k = 5; k >= 1; k--) {
			for (int j = 0; j < 4; j++) {
				blue[j][k] = blue[j][k - 1];
			}
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < 4; j++) {
			blue[j][i] = 0;
		}
	}
}

void special_green() {
	int c = 0;
	for (int i = 0; i < 2; i++) {
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (green[i][j] != 0) {
				flag = false;
			}
		}
		if (flag == false) c++;
	}

	for (int t = 0; t < c; t++) {
		for (int k = 5; k >= 1; k--) {
			for (int j = 0; j < 4; j++) {
				green[k][j] = green[k-1][j];
			}
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < 4; j++) {
			green[i][j] = 0;
		}
	}
}

//행이나 열에 꽉차있으면 지우고 점수 +1 , 각각 땡기기
void remove_blue() {
	for (int i = 0; i < 6; i++) {
		int c = 0;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 1)
				c++;
		}
		if (c == 4) {
			score++;
			for (int k = i; k >= 1; k--) {
				for (int j = 0; j < 4; j++) {
					blue[j][k] = blue[j][k - 1];
				}
			}
			for (int t = 0; t < 4; t++) {
				blue[t][0] = 0;
			}
		}
		
	}
}

void remove_green() {
	for (int i = 0; i < 6; i++) {
		int c = 0;
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 1)
				c++;
		}
		if (c == 4) {
			score++;
			for (int k = i; k >= 1; k--) {
				for (int j = 0; j < 4; j++) {
					green[k][j] = green[k-1][j];
				}
			}
			for (int t = 0; t < 4; t++) {
				green[0][t] = 0;
			}
		}
		
	}
}

void make_blue(int t, int x, int y) {
	int bx1 = x;
	int by1 = y;
	int bx2 = y+1;
	int by2 = x+1;

	if (t == 1) {
		bx1 = x;
		by1 = 0;
		while (1) {
			if( blue[bx1][by1] != 0) {
				by1--;
				break;
			}
			else if (by1 == 5)  break;
			by1++;
		}
		blue[bx1][by1] = 1;
	}
	else if (t == 2) {
		bx1 = x;
		bx2 = x;
		by1 = 0;
		by2 = 1;
		while (1) {
			if(blue[bx1][by2] != 0) {
				by1--;
				by2--;
				break;
			}
			else if (by2 == 5) break;
			by1++;
			by2++;
		}
		blue[bx1][by1] = 1;
		blue[bx1][by2] = 1;
	}
	else if (t == 3) {
		bx1 = x;
		bx2 = x + 1;
		by1 = 0;
		by2 = 0;
		while (1) {
			if( blue[bx1][by1] != 0 or blue[bx2][by2] != 0) {
				by1--;
				by2--;
				break;
			}
			else if (by1 == 5 or by2 == 5) break;
			by1++;
			by2++;
		}
		blue[bx1][by1] = 1;
		blue[bx2][by2] = 1;
	}
}

void make_green(int t, int x, int y) {
	int bx1 = x;
	int by1 = y;
	int bx2 = y + 1;
	int by2 = x + 1;

	if (t == 1) {
		bx1 = 0;
		by1 = y;
		while (1) {			
			if (green[bx1][by1] != 0) {
				bx1--;
				break;
			}
			else if (bx1 == 5) break;
			bx1++;
		}
		green[bx1][by1] = 1;
	}
	else if (t == 2) {
		bx1 = 0;
		by1 = y;
		bx2 = 0;
		by2 = y + 1;
		while (1) {
			//
			if(green[bx1][by2] != 0 or green[bx1][by1] != 0) {
				bx1--;
				break;
			}
			else if (bx1 == 5) break;
			bx1++;
		}
		green[bx1][by1] = 1;
		green[bx1][by2] = 1;
	}
	else if (t == 3) {
		bx1 = 0;
		bx2 = 1;
		by1 = y;
		by2 = y;
		while (1) {			
			if(green[bx1][by1] != 0 or green[bx2][by2] != 0) {
				bx1--;
				bx2--;
				break;
			}
			else if (bx1 == 5 or bx2 == 5) break;
			bx1++;
			bx2++;
		}
		green[bx1][by1] = 1;
		green[bx2][by2] = 1;
	}
}

void move() {
	for (int i = 0; i != B.size(); i++) {
		int t = B[i].t;
		int x = B[i].x;
		int y = B[i].y;
		
		make_blue(t, x, y);
		remove_blue();
		special_blue();

		make_green(t, x, y);
		remove_green();
		special_green();
	}
}

void input()
{
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		B.push_back(block(q, w, e));
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	move();

	cal_cnt();

	cout << score << '\n' << cnt;

	return 0;
}