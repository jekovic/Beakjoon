#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

//N극은 0 -- S극은 1
int wheel[5][8];
int result;

void clock_wise(int c) {

	int temp[8] = { 0, };
	temp[0] = wheel[c][7];
	for (int i = 0; i < 7; i++) {
		temp[i + 1] = wheel[c][i];
	}
	for (int i = 0; i < 8; i++) {
		wheel[c][i] = temp[i];
	}
}

void counter_clock_wise(int c) {

	int temp[8] = { 0, };
	temp[7] = wheel[c][0];
	for (int i = 0; i < 7; i++) {
		temp[i] = wheel[c][i+1];
	}
	for (int i = 0; i < 8; i++) {
		wheel[c][i] = temp[i];
	}

}
bool t1, t2, t3;
void rotate_wheel(int c, int direction) {
	if (direction == 1) {
		if (c == 1) {
			t1= t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6] ) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			clock_wise(1);

			if (t1 == true) {
				counter_clock_wise(2);
				if (t2 == true) {
					clock_wise(3);
					if (t3 == true) {
						counter_clock_wise(4);
					}
				}
			}
		}
		else if (c == 2) {
			t1 = t2 = t3 = false;
			
			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}
			clock_wise(2);
			if (t1 == true) {
				counter_clock_wise(1);
			}
			if (t2 == true) {
				counter_clock_wise(3);
				if (t3 == true) {
					clock_wise(4);
				}
			}
		}
		else if (c == 3) {
			t1 = t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			clock_wise(3);
			if (t3 == true) {
				counter_clock_wise(4);
			}
			if (t2 == true) {
				counter_clock_wise(2);
				if (t1 == true) {
					clock_wise(1);
				}
			}
		}
		else if (c == 4) {
			t1 = t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			clock_wise(4);
			if (t3 == true) {
				counter_clock_wise(3);
				if (t2 == true) {
					clock_wise(2);
					if (t1 == true) {
						counter_clock_wise(1);
					}
				}
			}
			
		}
	}
	else if (direction == -1) {
		if (c == 1) {
			t1 = t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			counter_clock_wise(1);

			if (t1 == true) {
				clock_wise(2);
				if (t2 == true) {
					counter_clock_wise(3);
					if (t3 == true) {
						clock_wise(4);
					}
				}
			}
		}
		else if (c == 2) {
			t1 = t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			counter_clock_wise(2);
			if (t1 == true) {
				clock_wise(1);
			}
			if (t2 == true) {
				clock_wise(3);
				if (t3 == true) {
					counter_clock_wise(4);
				}
			}
		}
		else if (c == 3) {
			t1 = t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			counter_clock_wise(3);
			if (t3 == true) {
				clock_wise(4);
			}
			if (t2 == true) {
				clock_wise(2);
				if (t1 == true) {
					counter_clock_wise(1);
				}
			}
		}
		else if (c == 4) {
			t1 = t2 = t3 = false;

			if (wheel[1][2] != wheel[2][6]) {
				t1 = true;
			}
			if (wheel[2][2] != wheel[3][6]) {
				t2 = true;
			}
			if (wheel[3][2] != wheel[4][6]) {
				t3 = true;
			}

			counter_clock_wise(4);
			if (t3 == true) {
				clock_wise(3);
				if (t2 == true) {
					counter_clock_wise(2);
					if (t1 == true) {
						clock_wise(1);
					}
				}
			}

		}
	}
}

//void rotate_wheel(int c, int direction) {
//	if (direction == 1) { //시계
//		if (c == 1) {
//			clock_wise(1);
//			if (wheel[1][2] != wheel[2][6]) // 1번이랑 2번이랑 다름
//			{
//				counter_clock_wise(2);
//				if (wheel[2][2] != wheel[3][6]) {
//					clock_wise(3);
//					if (wheel[3][2] != wheel[4][6]) {
//						counter_clock_wise(4);
//					}
//				}
//			}
//		}
//		else if (c == 2) {
//			clock_wise(2);
//			if (wheel[1][2] != wheel[2][6]) // 1번이랑 2번이랑 다름
//			{
//				counter_clock_wise(1);
//			}
//			if (wheel[2][2] != wheel[3][6]) {
//				counter_clock_wise(3);
//				if (wheel[3][2] != wheel[4][6]) {
//					clock_wise(4);
//				}
//			}
//		}
//		else if (c == 3) {
//			clock_wise(3);
//			if (wheel[3][6] != wheel[2][2]) // 1번이랑 2번이랑 다름
//			{
//				counter_clock_wise(2);
//				if(wheel[2][6] != wheel[1][2]){
//					clock_wise(1);
//				}
//			}
//			if (wheel[3][2] != wheel[4][6]) {
//				counter_clock_wise(4);
//			}
//		}
//		else if (c == 4) {
//			clock_wise(4);
//			if (wheel[3][2] != wheel[4][6]) {
//				counter_clock_wise(3);
//				if (wheel[3][6] != wheel[2][2]) // 1번이랑 2번이랑 다름
//				{
//					clock_wise(2);
//					if (wheel[2][6] != wheel[1][2]) {
//						counter_clock_wise(1);
//					}
//				}
//			}
//		}
//	}
//	else if (direction == -1) {	// 반시계
//		if (c == 1) {
//			counter_clock_wise(1);
//			if (wheel[1][2] != wheel[2][6]) // 1번이랑 2번이랑 다름
//			{
//				clock_wise(2);
//				if (wheel[2][2] != wheel[3][6]) {
//					counter_clock_wise(3);
//					if (wheel[3][2] != wheel[4][6]) {
//						clock_wise(4);
//					}
//				}
//			}
//		}
//		else if (c == 2) {
//			counter_clock_wise(2);
//			if (wheel[1][2] != wheel[2][6]) 
//			{
//				clock_wise(1);
//			}
//			if (wheel[2][2] != wheel[3][6]) {
//				clock_wise(3);
//				if (wheel[3][2] != wheel[4][6]) {
//					counter_clock_wise(4);
//				}
//			}
//		}
//		else if (c == 3) {
//			counter_clock_wise(3);
//			if (wheel[3][6] != wheel[2][2]) 
//			{
//				clock_wise(2);
//				if (wheel[2][6] != wheel[1][2]) {
//					counter_clock_wise(1);
//				}
//			}
//			if (wheel[3][2] != wheel[4][6]) {
//				clock_wise(4);
//			}
//		}
//		else if (c == 4) {
//			counter_clock_wise(4);
//			if (wheel[3][2] != wheel[4][6]) {
//				clock_wise(3);
//				if (wheel[3][6] != wheel[2][2]) 
//				{
//					counter_clock_wise(2);
//					if (wheel[2][6] != wheel[1][2]) {
//						clock_wise(1);
//					}
//				}
//			}
//		}
//	}
//}

void cal_res() {
	//점수 계산
	for (int i = 1; i <= 4; i++) {
		result += wheel[i][0] * pow(2, i - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1;i <= 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			int t = s[j] - '0';
			wheel[i][j] = t;
		}
	}
	
	int rotate;
	cin >> rotate;
	
	while (rotate--) {
		int q, w;
		cin >> q >> w;

		//회전하는 함수
		rotate_wheel(q, w);
	}

	//점수 계산하는 함수
	cal_res();

	cout << result;

	return 0;
}