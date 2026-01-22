#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
int min(int d,int j) {
	if (d >= j) {
		return j;
	}
	else {
		return d;
	}
}
int ucln(int x, int y) {
	int uocchung = 0;
	for (int i = 1; i <= min(x, y); i++) {
		if (x% i == 0 && y % i == 0) {
			if (i > uocchung) {
				uocchung = i;
			}

		}
	}
	return uocchung;
}

int main() {
	int a; cin >> a;
	int b; cin >> b;
	long long bcnn;
	cout << "Uoc chung lon nhat cua hai so la " << ucln(a, b) << endl;
	bcnn = a * b / ucln(a, b);
	cout << "Boi chung nho nhat cua hai so la " << bcnn;
	return 0;
}