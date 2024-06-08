#include <iostream>

using namespace std;

int arr[10000] = { 0, };


int main()
{
	int N, k;	//N is num & k is th_num
	cin >> N >> k;
	int num = 1;
	int res = 0;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			arr[num] = i;
			num++;
		}
	}

	if (arr[k] == 0) {
		cout << "0" << endl;
	}
	else {
		cout << arr[k];
	}


	return 0;
}