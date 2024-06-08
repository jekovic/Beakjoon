///*
//	별 표 찍기
//	c++는 문자열의 곱셈이 되지 않음을 주의
//*/
//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	unsigned short N;
//	cin >> N;
//	int a = N;
//	int b = N;
//
//	for (int i = 0; i < N; i++) {
//		
//		for (int j = a - 1; j > 0; j--) {
//			cout << "\0";
//		}
//		for (int k = 0; k < b; k++) {
//			cout << "*" << endl;
//		}
//	}
//	
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N;

int main()
{
	scanf("%d", &N);
	N = N * 2 - 1;
	int o = N / 2;
	for (int i = -o; i <= o; i++) {
		int k = 0;
		for (int j = 0; j < N - abs(i); j++) {
			printf(k < abs(i) ? " " : "*");
			k++;
		}
		printf("\n");
	}
}