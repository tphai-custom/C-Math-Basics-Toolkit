
#include <iostream>
#include <string>
using namespace std;

void printMenu() {
    cout << "NUMBER THEORY LAB\n";
    cout << "Chon 1 chuc nang:\n\n";

    cout << "1) PRIME LAB (So nguyen to)\n";
    cout << "   1.1 Kiem tra 1 so co phai nguyen to khong\n";
    cout << "   1.2 Liet ke cac so nguyen to trong [1..N]\n";
    cout << "   1.3 Dem so luong so nguyen to trong [1..N]\n\n";

    cout << "2) DIVISOR LAB (Uoc so)\n";
    cout << "   2.1 Dem so uoc cua n\n";
    cout << "   2.2 Liet ke cac uoc cua n\n";
    cout << "   2.3 Tinh tong uoc cua n\n";
    cout << "   2.4 Tinh tong uoc rieng (khong tinh chinh no)\n\n";

    cout << "3) GCD/LCM LAB (UCLN/BCNN)\n";
    cout << "   3.1 UCLN\n";
    cout << "   3.2 BCNN (dua tren UCLN)\n";
    cout << "   3.3 Kiem tra 2 so cung nhau nguyen to\n\n";

    cout << "Nhap lua chon (vd: 1.2 hay 3.1): ";
}

long long ucln(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long bcnn(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    long long g = ucln(a, b);
    return (a / g) * b;
}

bool snt(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long demUoc(long long n) {
    if (n == 0) return 0;
    if (n < 0) n = -n;

    long long cnt = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            long long e = 0;
            while (n % p == 0) {
                n /= p;
                e++;
            }
            cnt *= (e + 1);
        }
    }
    if (n > 1) cnt *= 2;
    return cnt;
}

long long tongUoc(long long n) {
    if (n == 0) return 0;
    if (n < 0) n = -n;

    long long sum = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            long long term = 1;
            long long powp = 1;
            while (n % p == 0) {
                n /= p;
                powp *= p;
                term += powp;
            }
            sum *= term;
        }
    }
    if (n > 1) sum *= (1 + n);
    return sum;
}

long long tongUocRieng(long long n) {
    if (n <= 1) return 0;
    return tongUoc(n) - n;
}

int main() {
    printMenu();
    string choice;
    cin >> choice;

    if (choice == "1.1") {
        long long a;
        cout << "Nhap so a: ";
        cin >> a;
        if (snt(a)) cout << a << " la so nguyen to\n";
        else cout << a << " khong phai la so nguyen to\n";
    }

    else if (choice == "1.2") {
        long long N;
        cout << "Nhap N: ";
        cin >> N;
        if (N < 2) {
            cout << "Khong co so nguyen to trong [1.." << N << "]\n";
        } else {
            cout << "Cac so nguyen to trong [1.." << N << "]:\n";
            for (long long i = 2; i <= N; i++) {
                if (snt(i)) cout << i << " ";
            }
            cout << "\n";
        }
    }

    else if (choice == "1.3") {
        long long N;
        cout << "Nhap N: ";
        cin >> N;
        long long cnt = 0;
        for (long long i = 2; i <= N; i++) if (snt(i)) cnt++;
        cout << "So luong so nguyen to trong [1.." << N << "] la " << cnt << "\n";
    }

    else if (choice == "2.1") {
        long long a;
        cout << "Nhap n: ";
        cin >> a;
        if (a == 0) {
            cout << "n = 0 khong hop le de dem uoc theo cach thong thuong.\n";
        } else {
            cout << "So uoc cua " << a << " la " << demUoc(a) << "\n";
        }
    }

    else if (choice == "2.2") {
        long long a;
        cout << "Nhap n: ";
        cin >> a;
        if (a == 0) {
            cout << "n = 0 khong hop le.\n";
        } else {
            if (a < 0) a = -a;
            cout << "Cac uoc cua n la:\n";
            for (long long i = 1; i * i <= a; i++) {
                if (a % i == 0) {
                    cout << i << " ";
                    long long j = a / i;
                    if (j != i) cout << j << " ";
                }
            }
            cout << "\n";
        }
    }

    else if (choice == "2.3") {
        long long a;
        cout << "Nhap n: ";
        cin >> a;
        if (a == 0) cout << "n = 0 khong hop le.\n";
        else cout << "Tong cac uoc cua n la " << tongUoc(a) << "\n";
    }

    else if (choice == "2.4") {
        long long a;
        cout << "Nhap n: ";
        cin >> a;
        cout << "Tong uoc rieng (khong tinh chinh no) la " << tongUocRieng(a) << "\n";
    }

    else if (choice == "3.1") {
        long long a, b;
        cout << "Nhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        cout << "Uoc chung lon nhat la " << ucln(a, b) << "\n";
    }

    else if (choice == "3.2") {
        long long a, b;
        cout << "Nhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        cout << "Boi chung nho nhat la " << bcnn(a, b) << "\n";
    }

    else if (choice == "3.3") {
        long long a, b;
        cout << "Nhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        if (ucln(a, b) == 1) cout << "Hai so cung nhau nguyen to.\n";
        else cout << "Hai so KHONG cung nhau nguyen to.\n";
    }

    else {
        cout << "Du lieu khong hop le.\n";
    }

    return 0;
}