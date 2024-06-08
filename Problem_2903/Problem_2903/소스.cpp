#include <iostream>
#include <cmath>
using namespace std;

/*	
	0 -> 4 		2 
	1 -> 9 		3
	2 -> 25 	5
	3 -> 81  	9
	4 -> 		17	 	
	5 -> 		33
*/

int main() {

	unsigned short N;

	cin >> N;

	unsigned long long int res = 0;

	int arr[16] = { 0, };
	arr[0] = 2;
	arr[1] = 3;
	int k = 1;
	for (int i = 1; i < 16; i++) {
		arr[i] = arr[i - 1] + k;
		k *= 2;
	}
	res = pow(arr[N], 2);
	cout << res;

	return 0;
}