#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

string s;
int res;

/*
	-뒤에 기호들은 다 -로 바꿔서 계산하기 
	(괄호로 묶는 효과)
*/

void solve() {
	string n = "";
	bool flag = false; // '-' 를 만나면 true

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (flag) {
				res -= stoi(n);
				n = "";
			}
			else {
				res += stoi(n);
				n = "";
			}
		}
		else n += s[i];

		if (s[i] == '-') flag = true;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	solve();

	cout << res;
	
	return 0;
}