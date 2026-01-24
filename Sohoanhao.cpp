#include <iostream>
using namespace std;

long long tongUocRieng(long long a) {
    if (a <= 1) return 0;
    long long sum = 1;

    for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            sum += i;
            long long j = a / i;
            if (j != i) sum += j;
        }
    }
    return sum;
}

int main() {
    long long a;
    cout << "Nhap so a: ";
    cin >> a;

    if (a <= 0) {
        cout << "Du lieu khong hop le (a phai > 0).\n";
        return 0;
    }

    long long sum = tongUocRieng(a);

    if (sum == a && a != 0) {
        cout << a << " la so hoan hao.\n";
    } else {
        cout << a << " khong phai la so hoan hao.\n";
    }
    cout << "Tong uoc rieng cua a = " << sum << "\n";
    return 0;
}