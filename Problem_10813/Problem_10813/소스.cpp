#include <iostream>

using namespace std;

unsigned short basket[100];

void swap(unsigned short* a, unsigned short* b) {
	unsigned short temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	unsigned short N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		basket[i] = i;
	}

	for (int i = 0; i < M; i++) {
		unsigned short a, b = 0;
		cin >> a >> b;
		swap(basket[a], basket[b]);
	}

	for (int i = 1; i <= N; i++) {
		cout << basket[i] << " ";
	}
	

	return 0;
}