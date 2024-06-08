#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	long long int ten;
	int N;
	cin >> ten >> N;

	char num[36] = { '\0', };
	char a = '0';
	char temp = 'A';
	for (int i = 0; i < 10; i++) {
		num[i] = a;
		a++;
	}
	for (int i = 10; i < 36;i++) {
		num[i] = temp;
		temp++;
	}

	string res;
	int k = 0;

	while (1) {
		int remain = ten % N;
		for (int j = 0; j < 36;j++) {
			if (j == remain) {
				res.append(string(1, num[j]));
			}
		}
		ten = ten / N;
		if (ten == 0) {
			break;
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}