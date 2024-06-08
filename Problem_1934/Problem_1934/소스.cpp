/*
	최소공배수
	-> 두 수의 곱을 최대 공약수로 나눈 것'

	유클리드 호제법 이용
	최대공약수 ->  최소공배수
	
*/
#include <iostream>

using namespace std;

unsigned short Max(unsigned short a, unsigned short b)
{
	int k = (a > b) ? a : b;
	return k;
}
unsigned short Min(unsigned short a, unsigned short b)
{
	int k = (a < b) ? a : b;
	return k;
}
unsigned short gcd(unsigned short x, unsigned short y)
{
	// 최대공약수 구하는 방법
	unsigned short ret = 1;
	unsigned short n = Max(x, y);
	unsigned short m = Min(x, y);
	
	while (ret > 0)
	{
		ret = n % m;
		n = m;
		m = ret;
	}
	
	
	return n;

}

unsigned long lcm(unsigned short a, unsigned short b) {

	return (unsigned long)(a * b) / gcd(a, b);
}

int main()
{
	unsigned short T, k  = 0;
	cin >> T;
	int arr[1000] = { 0, };
	
	while (k < T)
	{
		unsigned short A, B = 0;
		cin >> A >> B;
		arr[k] = lcm(A, B);

		k++;
	}

	for (int i = 0; i < T; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}