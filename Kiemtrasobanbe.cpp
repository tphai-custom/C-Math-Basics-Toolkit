#include <iostream>
using namespace std;

long long tongUocRieng(long long x) {
    if (x <= 1) return 0;
    long long sum = 1;

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i;
            long long j = x / i;
            if (j != i) sum += j;
        }
    }
    return sum;
}

int main() {
    long long a, b;

    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap so b: ";  
    cin >> b;

    if (a <= 0 || b <= 0) {
        cout << "Du lieu khong hop le (a, b phai > 0).\n";
        return 0;
    }
    if (a == b) {
        cout << "Hai so bang nhau nen khong the la cap so ban be.\n";
        cout << "Tong uoc rieng cua a = " << tongUocRieng(a) << "\n";
        cout << "Tong uoc rieng cua b = " << tongUocRieng(b) << "\n";
        return 0;
    }

    long long suma = tongUocRieng(a);
    long long sumb = tongUocRieng(b);

    if (suma == b && sumb == a) {
        cout << "Hai so nay la cap so ban be.\n";
    } else {
        cout << "Hai so nay khong phai la cap so ban be.\n";
    }

    cout << "Tong uoc rieng cua a = " << suma << "\n";
    cout << "Tong uoc rieng cua b = " << sumb << "\n";
    return 0;
}