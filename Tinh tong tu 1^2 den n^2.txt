#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int cong(int a, int b) {
	return a + b;
}

int main() {
	long long n;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		sum += pow((i + 1), 2);
	}
	cout << sum;
	return 0;
}