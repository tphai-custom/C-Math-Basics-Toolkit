#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


using namespace std;

int tonguoc(long long x) {
	int tonguoc; tonguoc = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			tonguoc += i;
		}
	}
	return tonguoc;
}

int main() {
	/* Vui long hai so khac nhau */
	long long a; cin >> a;
	long long b; cin >> b;
	long long sumtonga;
	long long sumtongb;
	if (a == b) {
		cout << "Hai so bang nhau nen du lieu ko hop le";
	}
	else {
		sumtonga = tonguoc(a);
		sumtongb = tonguoc(b);
	}
	if (sumtonga == sumtongb) {
		cout << "Hai so nay la cap so ban be" << endl;
	}
	else {
		cout << "Hai so nay khong phai la cap so ban be" << endl;
	}
	cout << "Tong so uoc cua a " << sumtonga << endl;
	cout << "Tong so uoc cua b " << sumtongb;
	return 0;
}