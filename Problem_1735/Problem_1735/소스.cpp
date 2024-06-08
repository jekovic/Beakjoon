/*
	분수 합
	서로 다른 두 분수가 주어졌을 때, 
	기약분수로 만들기

	==> 분수를 합한 뒤, 분자 분모의 최대공약수로 나눈다.
	
*/

#include <iostream>

using namespace std;

unsigned int Max(unsigned int a, unsigned int b)
{
	unsigned int ret = (a > b) ? a : b;
	return ret;
}

unsigned int Min(unsigned int a, unsigned int b)
{
	unsigned int ret = (a < b) ? a : b;
	return ret;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int ret = 1;
	
	unsigned int x = Max(a,b);
	unsigned int y = Min(a, b);

	while (ret > 0) {
		ret = x % y;
		x = y;
		y = ret;
	}
	return x;

}

int main()
{
	unsigned int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	unsigned int x = 1;//x가 분모
	unsigned int y = 1;//y가 분자
	
	x = b * d;
	y = a * d + b * c;
	unsigned int g = gcd(x, y);
	//cout << gcd(x, y)<< endl;

	x /= g;
	y /= g;

	cout << y << ' ' << x;

	return 0;
}