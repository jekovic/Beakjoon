#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> stu;
int main_t, sub_t;
long long int result = 0;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		stu.push_back(t);
	}

	cin >> main_t >> sub_t;

	for (int i = 0; i != stu.size(); i++) {
		int student_num = stu[i];
		if (student_num <= main_t)
		{
			result++;
		}
		else {
			student_num -= main_t;
			result++;
			if (student_num % sub_t == 0) {
				result += (student_num / sub_t);
			}
			else {
				result += (student_num / sub_t) + 1;
			}
		}
	}

	cout << result;

	return 0;
}