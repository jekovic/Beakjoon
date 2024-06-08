#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 16
using namespace std;

/*
	줄당 하나씩만 위치하게 하기
*/

/*
이 때, 같은 행과 열에 있는지 확인하는 방법은 매우 간단하지만, 
대각선에 위치해있는지를 찾는 방식이 다소 까다로울 수 있다. 

먼저 기본적으로 대각선에 존재하는 좌표일 경우,
(X, Y)의 대각선에 위치한 좌표 (A, B)에서 반드시 X-A = Y-B를 만족한다.

예를 들어 (0 , 1)을 기준으로 했을때, 
대각선에 있는 점들 (1, 2) (2, 3) 은 
반드시 (0 - 1) = (1 - 2) = -1, (0 - 2) = (1 - 3) = -2를 만족한다는 것이다.

따라서 우리가 정의한 col이라는 1차원 배열의 정의에 따라서 
X좌표와 Y좌표의 차이가 일정한 값을 가질 경우 해당 퀸과 대각선에 있다고 판단할 수 있다.

*/
int N;
int col[MAX];
int result;

bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] == col[level] or abs(col[level] - col[i]) == level - i)
			return false;
		//col[i]가 x 좌표, i가 y좌표이기에 차이가 일정하면 대각선에 있다고 생각하기 
	}
	return true;
}

void dfs(int cnt)
{
	if (cnt == N) {
		result++;
	}
	else {
		for (int i = 0; i < N; i++) {
			col[cnt] = i;
			if (check(cnt)) {
				dfs(cnt + 1);
			}
		}
	}
}

int main() {

	cin >> N;
	dfs(0);
	cout << result;

	return 0;
}