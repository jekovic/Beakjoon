#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

string S, T;
int d;
int visited[50];
int arr[2] = { 0, 1 };
bool flag = true;
/*
	d = S와 T의 길이 차이
	pow(2,d)의 연산을 하면서 같은게 한번이라도 나오면 true / 아니면 false
*/

void input() {
	cin >> S >> T;
	d = T.size() - S.size();
}

// 1
void add_A(string& temp) {
	temp.push_back('A');
}

// 2
void add_B_and_rev(string& temp) {
	temp.push_back('B');
	reverse(temp.begin(), temp.end());
}

void zero(string& temp) {
	temp.pop_back();
}

void one(string& temp) {
	reverse(temp.begin(), temp.end());
	temp.pop_back();
}

//void dfs(string temp, string res, int cnt) {
//	if (cnt == d) {
//		for (int t = 0; t < d; t++) {
//			if (visited[t] == 0) {
//				add_A(temp);
//			}
//			else if (visited[t] == 1) {
//				add_B_and_rev(temp);
//			}
//		}
//		if (temp.compare(res) == 0) {
//			flag = false;
//		}
//		return;
//	}
//
//	for (int i = 0; i < 2; i++) {
//		visited[cnt] = i;
//		dfs(temp, res, cnt + 1);
//	}
//}

void dfs(string temp, string res, int cnt) {
	if (cnt == d) {
		for (int t = 0; t < d; t++) {
			if (visited[t] == 0) {
				zero(res);
			}
			else if (visited[t] == 1) {
				one(res);
			}
		}
		if (temp.compare(res) == 0) {
			flag = false;
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		visited[cnt] = i;
		dfs(temp, res, cnt + 1);
	}
}

string temp;
void solve(string s, string t)
{
	if (s == t) {
		cout << 1;
		exit(0);
	}
	if (s.size() >= t.size()) {
		return;
	}
	if (t[t.size() - 1] == 'A') {
		temp = t;
		temp.erase(temp.size() -1);
		solve(s, temp);
	}
	if (t[0] == 'B') {
		temp = t;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		solve(s, temp);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve(S, T);

	cout << 0;
	
	return 0;
}