#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	string s;
	int N;
	cin >> s >> N;
	
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

	long long int res = 0;
	int k = 0;
	for (int i = (int)s.size()-1;i > -1;i--) {
		for (int j = 0; j < 36;j++) {
			if (num[j] == s.at(i)) {
				res += j * pow(N, k);
				break;
			}
		}
		k++;
	}
	cout << res;
	return 0;
}