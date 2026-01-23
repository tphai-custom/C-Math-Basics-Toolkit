#include <iostream>
using namespace std;

bool laSoNguyenTo(long long a) {
    if (a < 2) return false;
    if (a == 2 || a == 3) return true;
    if (a % 2 == 0) return false;
    for (long long i = 3; i * i <= a; i += 2) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    long long a;
    cout << "Nhap so a: ";
    cin >> a;

    if (a < 0) {
        cout << "Du lieu khong hop le (a phai >= 0).\n";
        return 0;
    }

    if (laSoNguyenTo(a)) {
        cout << a << " la so nguyen to.\n";
    } else {
        cout << a << " khong phai la so nguyen to.\n";
    }

    return 0;
}