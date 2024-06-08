#include <iostream>
#include <string>

using namespace std;

int main() {

	char word[5][15];
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 15;j++) {
			word[i][j] = '@';
		}
	}
	int max_ = -9999;

	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;

		if (max_ < (int)s.size()) {
			max_ = (int)s.size();
		}
		
		for (int j = 0; j < s.size();j++) {
			word[i][j] = s[j];
		}
	}

	string res = "";

	for (int i = 0; i < max_; i++) {
		for (int j = 0; j < 5;j++) {
			if (word[j][i] != '@') {
				res.append((string(1, word[j][i])));
			}
			else {

			}
			
		}
	}
	cout << res;
	return 0;
}
