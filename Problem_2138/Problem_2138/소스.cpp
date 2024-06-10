/*
	REF) https://staticvoidlife.tistory.com/143
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
string start;
string finish;
int result = 1e9;
bool flag = true;

void input() {
	cin >> N;
	cin >> start >> finish;
}

void change_num(string& S, int idx) {

	for (int i = idx - 1; i <= idx + 1; i++) {
		if (i >= 0 and i < N) {
			if (S[i] == '0') {
				S[i] = '1';
			}
			else if (S[i] == '1') {
				S[i] = '0';
			}
		}
	}	
}

void solve() {
	//0번 스위치 누르지 않았을 때
	string temp = start;
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		if (temp[i-1] != finish[i-1]){
			change_num(temp, i);
			cnt++;
		}
	}
	if (temp.compare(finish) == 0) {
		result = min(result, cnt);
		flag = false;
	}

	//0번 스위치 누르고 시작
	temp = start;
	change_num(temp, 0);
	cnt = 1;
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != finish[i - 1]) {
			change_num(temp, i);
			cnt++;
		}
	}
	if (temp.compare(finish) == 0) {
		result = min(result, cnt);
		flag = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	if (flag) {
		cout << -1;
	}
	else {
		cout << result;
	}
	
	return 0;
}