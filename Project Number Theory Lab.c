
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
void printMenu() {
	cout << "NUMBER THEORY LAB\n";
	cout << "Chon 1 chuc nang:\n\n";

	cout << "1) PRIME LAB (So nguyen to)\n";
	cout << "   1.1 Kiem tra 1 so co phai nguyen to khong\n";
	cout << "   1.2 Liet ke cac so nguyen to trong [1..N]\n";
	cout << "   1.3 Dem so luong so nguyen to trong [1..N]\n";

	cout << "2) DIVISOR LAB (Uoc so)\n";
	cout << "   2.1 Dem so uoc cua n\n";
	cout << "   2.2 Liet ke cac uoc cua n\n";
	cout << "   2.3 Tinh tong uoc cua n\n";
	cout << "   2.4 Tinh tong uoc rieng (khong tinh chinh no)\n\n";

	cout << "3) GCD/LCM LAB (UCLN/BCNN)\n";
	cout << "   3.1 UCLN \n";
	cout << "   3.2 BCNN (dua tren UCLN)\n";
	cout << "   3.3 Kiem tra 2 so cung nhau nguyen to\n\n";
	cout << "Nhap lua chon (vd: 1.2 hay 3.1): ";
}
int min(int d, int j) {
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
		if (x % i == 0 && y % i == 0) {
			if (i > uocchung) {
				uocchung = i;
			}

		}
	}
	return uocchung;
}
int uc(int c) {
	int sluc = 0;
	for (int i = 1; i <= c; i++) {
		if (c % i == 0) {
			sluc += 1;
		}
	}
	return sluc;
}
bool snt(int a) {
	long long soluonguoc; soluonguoc = 0;
	for (long long i = 1; i <= a; i++) {
		if (a % i == 0) {
			soluonguoc += 1;
		}
	}
	if (soluonguoc == 2) {
		return true;
	}
	return false;
}

int main() {
	printMenu();
	double n; cin >> n;
	if (n == 1.1) {
		int a; cin >> a;
		if (snt(a) == true) {
			cout <<  a << " la so nguyen to" << endl;
		}
		else {
			cout << a << " khong phai la so nguyen to" << endl;
		}
	}
	else if (n == 1.2) {
		int a; cin >> a;
		for (int i = 2; i <= a; i++) {
			if (snt(i) == true) {
				cout << "Cac so nguyen to trong pham vi " << a << " la " << i << endl;
			}
		}

	}
	else if (n == 1.3) {
		int a; cin >> a;
		int sluoc = 0;
		for (int i = 2; i <= a; i++) {
			if (snt(i) == true) {
				sluoc += 1;
			}
		}
		cout << "So luong so nguyen to trong pham vi " << a <<  " la " << sluoc << endl;

	}
	else if (n == 2.1) {
		int a; cin >> a;
		cout << "So uoc cua " << a << " la " << uc(a) << endl;;

	}
	else if (n == 2.2) {
		int a; cin >> a;
		for (int i = 1; i <= a; i++) {
			if (a % i == 0) {
				cout << "Cac uoc cua " << a << " la " << i << endl;
			}
		}

	}
	else if (n == 2.3) {
		int a; cin >> a;
		int sum = 0;
		for (int i = 1; i <= a; i++) {
			if (a % i == 0) {
				sum += i;
			}
		}
		cout << "Tong cac uoc cua a " << a << " la " << sum << endl;
	}

	else if (n == 2.4) {
		int a; cin >> a;
		int sum = 0;
		for (int i = 1; i < a; i++) {
			if (a % i == 0) {
				sum += i;
			}
		}
		cout << "Tong cac uoc that su cua a " << a << " la " << sum << endl;

	}

	else if (n == 3.1) {
		int a; cin >> a;
		int b; cin >> b;
		cout << "Uoc chung lon nhat cua hai so la " << ucln(a, b) << endl;
	}

	else if (n == 3.2) {
		int a; cin >> a;
		int b; cin >> b;
		long long bcnn;
		bcnn = a * b / ucln(a, b);
		cout << "Boi chung nho nhat cua hai so la " << bcnn;
	}
	else if (n == 3.3) {
		int a; cin >> a;
		int b; cin >> b;
		int uocchung = 0;
		for (int i = 1; i <= min(a, b); i++) {
			if (a % i == 0 && b % i == 0) {
				uocchung += 1;

			}
		}
		if (uocchung == 0) {
			cout << "Hai so nhap vao nguyen to cung nhau" << endl;
		}
		else {
			cout << "Hai so nhap vao khong nguyen to cung nhau" << endl;
		}

	}
	else {
		cout << "Du lieu ko hop le" << endl;
	}
}