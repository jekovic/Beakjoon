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
	-�ڿ� ��ȣ���� �� -�� �ٲ㼭 ����ϱ� 
	(��ȣ�� ���� ȿ��)
*/

void solve() {
	string n = "";
	bool flag = false; // '-' �� ������ true

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