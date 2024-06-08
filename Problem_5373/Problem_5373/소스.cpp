#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//위 아래 앞 뒤 왼 오
char cube[6][3][3];
char c_cube[6][3][3];

void copy_cube() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				c_cube[i][j][k] = cube[i][j][k];
			}
		}
	}
}

void rotate_cube(char pos, char di) {
	
	if (pos == 'U') {
		//copy_cube();
		
		if (di == '+') {	// 시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[0][0][i] = c_cube[0][2 - i][0];
				cube[0][2][i] = c_cube[0][2 - i][2];
				cube[0][i][0] = c_cube[0][2][i];
				cube[0][i][2] = c_cube[0][0][i];
			}

			for (int i = 0; i < 3; i++) {
				cube[3][0][i] = c_cube[4][2-i][0];
				cube[5][i][2] = c_cube[3][0][i];
				cube[2][2][i] = c_cube[5][2-i][2];
				cube[4][i][0] = c_cube[2][2][i];
			}
		}
		else if (di == '-') {
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[0][0][i] = c_cube[0][i][2];
				cube[0][2][i] = c_cube[0][i][0];
				cube[0][i][0] = c_cube[0][2][2-i];
				cube[0][i][2] = c_cube[0][0][2-i];
			}

			for (int i = 0; i < 3; i++) {
				cube[3][0][i] = c_cube[5][i][2];
				cube[5][i][2] = c_cube[2][2][2-i];
				cube[2][2][i] = c_cube[4][i][0];
				cube[4][i][0] = c_cube[3][0][2-i];
			}
		}
	}//
	else if (pos == 'D') {
		if (di == '+') {	// 시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[1][0][i] = c_cube[1][2 - i][0];
				cube[1][2][i] = c_cube[1][2 - i][2];
				cube[1][i][0] = c_cube[1][2][i];
				cube[1][i][2] = c_cube[1][0][i];
			}

			for (int i = 0; i < 3; i++) {
				cube[3][2][i] = c_cube[5][i][0];
				cube[5][i][0] = c_cube[2][0][2-i];
				cube[2][0][i] = c_cube[4][i][2];
				cube[4][i][2] = c_cube[3][2][2-i];
			}
		}
		else if (di == '-') {
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[1][0][i] = c_cube[1][i][2];
				cube[1][2][i] = c_cube[1][i][0];
				cube[1][i][0] = c_cube[1][2][2 - i];
				cube[1][i][2] = c_cube[1][0][2 - i];
			}

			for (int i = 0; i < 3; i++) {
				cube[3][2][i] = c_cube[4][2-i][2];
				cube[5][i][0] = c_cube[3][2][i];
				cube[2][0][i] = c_cube[5][2-i][0];//
				cube[4][i][2] = c_cube[2][0][i];
			}
		}
	}///
	else if (pos == 'F') {
		if (di == '+') {	// 시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[2][0][i] = c_cube[2][2 - i][0];
				cube[2][2][i] = c_cube[2][2 - i][2];
				cube[2][i][0] = c_cube[2][2][i];
				cube[2][i][2] = c_cube[2][0][i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][0][i] = c_cube[4][2][2-i];
				cube[5][2][i] = c_cube[0][0][2-i];
				cube[1][2][i] = c_cube[5][2][i];
				cube[4][2][i] = c_cube[1][2][i];
			}
		}
		else if (di == '-') {
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[2][0][i] = c_cube[2][i][2];
				cube[2][2][i] = c_cube[2][i][0];
				cube[2][i][0] = c_cube[2][2][2 - i];
				cube[2][i][2] = c_cube[2][0][2 - i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][0][i] = c_cube[5][2][i];
				cube[5][2][i] = c_cube[1][2][2-i];
				cube[1][2][i] = c_cube[4][2][i];
				cube[4][2][i] = c_cube[0][0][2-i];
			}
		}
	}// 
	else if (pos == 'B') {
		if (di == '-') {	// 반시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[3][0][i] = c_cube[3][i][2];
				cube[3][2][i] = c_cube[3][i][0];
				cube[3][i][0] = c_cube[3][2][2 - i];
				cube[3][i][2] = c_cube[3][0][2 - i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][2][i] = c_cube[4][0][2-i];
				cube[5][0][i] = c_cube[0][2][i];
				cube[1][0][i] = c_cube[5][0][i];
				cube[4][0][i] = c_cube[1][0][2-i];
			}
		}
		else if (di == '+') {	// 시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[3][0][i] = c_cube[3][2 - i][0];
				cube[3][2][i] = c_cube[3][2 - i][2];
				cube[3][i][0] = c_cube[3][2][i];
				cube[3][i][2] = c_cube[3][0][i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][2][i] = c_cube[5][0][2-i];
				cube[5][0][i] = c_cube[1][0][i];
				cube[1][0][i] = c_cube[4][0][i];
				cube[4][0][i] = c_cube[0][2][2-i];
			}
		}
	}//
	else if (pos == 'L') {
		if (di == '+') {	// 시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[4][0][i] = c_cube[4][2 - i][0];
				cube[4][2][i] = c_cube[4][2 - i][2];
				cube[4][i][0] = c_cube[4][2][i];
				cube[4][i][2] = c_cube[4][0][i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][i][0] = c_cube[3][i][0];
				cube[2][i][0] = c_cube[0][i][0];
				cube[1][i][0] = c_cube[2][i][0];
				cube[3][i][0] = c_cube[1][i][0];
			}
		}
		else if (di == '-') {
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[4][0][i] = c_cube[4][i][2];
				cube[4][2][i] = c_cube[4][i][0];
				cube[4][i][0] = c_cube[4][2][2 - i];
				cube[4][i][2] = c_cube[4][0][2 - i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][i][0] = c_cube[2][i][0];
				cube[2][i][0] = c_cube[1][i][0];
				cube[1][i][0] = c_cube[3][i][0];
				cube[3][i][0] = c_cube[0][i][0];
			}
		}
	}
	else if (pos == 'R') {
		if (di == '+') {	// 시계
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[5][0][i] = c_cube[5][2 - i][0];
				cube[5][2][i] = c_cube[5][2 - i][2];
				cube[5][i][0] = c_cube[5][2][i];
				cube[5][i][2] = c_cube[5][0][i];
			}
			
			for (int i = 0; i < 3; i++) {
				cube[0][i][2] = c_cube[2][i][2];
				cube[2][i][2] = c_cube[1][i][2];
				cube[1][i][2] = c_cube[3][i][2];
				cube[3][i][2] = c_cube[0][i][2];
			}
		}
		else if (di == '-') {
			copy_cube();
			for (int i = 0; i < 3; i++) {
				cube[5][0][i] = c_cube[5][i][2];
				cube[5][2][i] = c_cube[5][i][0];
				cube[5][i][0] = c_cube[5][2][2 - i];
				cube[5][i][2] = c_cube[5][0][2 - i];
			}

			for (int i = 0; i < 3; i++) {
				cube[0][i][2] = c_cube[3][i][2];
				cube[2][i][2] = c_cube[0][i][2];
				cube[1][i][2] = c_cube[2][i][2];
				cube[3][i][2] = c_cube[1][i][2];
			}
		}
	}
}

void init() {
	//up -> white
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[0][i][j] = 'w';
		}
	}
	//down -> yellow
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[1][i][j] = 'y';
		}
	}
	//front -> red
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[2][i][j] = 'r';
		}
	}
	//back -> orange
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[3][i][j] = 'o';
		}
	}
	//left -> green
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[4][i][j] = 'g';
		}
	}
	//right -> blue
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[5][i][j] = 'b';
		}
	}
}

/*
	정면으로 보았울때 가정한 출력
*/
void print_all() {
	cout << "--up(0)--" << '\n';
	for (int i = 2; i >= 0;i--) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << '\n';
	}


	cout << "--down(1)--" << '\n';
	for (int i = 0; i <3 ;i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[1][i][j];
		}
		cout << '\n';
	}


	cout << "--front(2)--" << '\n';
	for (int i = 2; i >= 0;i--) {
		for (int j = 0; j < 3; j++) {
			cout << cube[2][i][j];
		}
		cout << '\n';
	}


	cout << "--back(3)--" << '\n';
	for (int i = 0; i <3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[3][i][j];
		}
		cout << '\n';
	}


	cout << "--left(4)--" << '\n';
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j<3; j++) {
			cout << cube[4][j][i];
		}
		cout << '\n';
	}


	cout << "--right(5)--" << '\n';
	for (int i = 2; i >=0; i--) {
		for (int j = 2; j >=0 ; j--) {
			cout << cube[5][j][i];
		}
		cout << '\n';
	}
	cout << "----------------------------------\n";
}

void print_res() {
	for (int i = 2; i >=0 ;i--) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << '\n';
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		int n;
		cin >> n;
		// 큐브 초기화
		init();

		while (n--) {
			string s;
			cin >> s;
		
			rotate_cube(s[0], s[1]);

			//print_all();
		}
		//출력
		print_res();
		//cout << '\n';
	}

	return 0;
}