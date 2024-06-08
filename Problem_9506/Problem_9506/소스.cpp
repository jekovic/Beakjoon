/*
	[완전수]
	약수 중 자기 자신을 제외한 모든 수를 더했을 때,
	원래 수와 같은 수
	ex> 6 = 1 + 2 + 3

*/
#include <iostream>
#define MAX 10000
using namespace std;
int cnt = 0; // 약수의 개수
static int a[MAX] = { 0, };

int PerfectNum_RetSum(int k) {

	int sum = 0;
	for (int i = 1; i < k; i++) {
		if (k % i == 0) {
			sum += i;
		}
	}
	return sum;
}

void PerfectNum_RetArr(int k) {

	cnt = 0;
	for (int i = 1; i < k; i++) {
		if (k % i == 0) {
			a[cnt] = i;
			cnt++;
		}
	}
}



int main() {

	while (1)
	{
		int N;
		cin >> N;
		if (N == -1) {
			break;
		}
		else {
			int k = PerfectNum_RetSum(N);
			if (k == N)
			{
				PerfectNum_RetArr(N);
				cout << N << " = ";
				for (int i = 0; i < cnt;i++) {
			
					if (i < cnt - 1) {
						cout << a[i] << " + ";
					}
					else {
						cout << a[i];
					}
				}
				
			}
			else {
				cout << N << " is NOT perfect.";
			}
			
		}
		cout << endl;
	}

	return 0;
} 