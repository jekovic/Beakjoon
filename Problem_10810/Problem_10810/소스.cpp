#include <iostream>

using namespace std;

int main() {

	unsigned short N, M;
	cin >> N >> M;

	unsigned short arr[100] = { 0, };

	for (int a = 0; a < M; a++) { //바구니에 넣기
		unsigned short i, j, k;
		cin >> i >> j >> k;

		for (int b = i; b <= j;b++) {
			arr[b] = k;
		}

	}

	for (int i = 1; i <= N; i++) {	//출력

		cout << arr[i] << " ";
	}

	return 0;
}