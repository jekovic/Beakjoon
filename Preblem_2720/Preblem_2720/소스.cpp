#include <iostream>

#define QUATER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {

		int k;
		cin >> k;
		int q , d , n , p = 0;
		
		
		q = k / QUATER;
		k %= QUATER;
		d = k / DIME;
		k %= DIME;
		n = k / NICKEL;
		k %=  NICKEL;
		p = k / PENNY;
		k %= PENNY;


		cout << q << " " << d << " " << n << " " << p << endl;
	}


	return 0;
}