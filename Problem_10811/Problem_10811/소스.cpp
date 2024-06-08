#include <iostream>

using namespace std;

unsigned short arr[100];
unsigned short tmp[100];

void swap(unsigned short* a, unsigned short* b) {
	unsigned short temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	unsigned short N, M;

	cin >> N >> M;

	for (int i = 1;i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < M; i++) {

		unsigned int a, b = 0;
		cin >> a >> b;
		unsigned int k = a;
		unsigned int d = b;
		if (a != b) {
			if (b - a == 1) {
				swap(arr[a], arr[b]);
			}
			else {
				
				for (int j = 0; j <= (b-a+1)/2; j++) {
					swap(arr[k], arr[d]);
					++k;
					--d;
				}
			}

		}
		//unsigned int k = a - b + 1;
		

	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}