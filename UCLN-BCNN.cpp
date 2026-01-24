#include <iostream>
using namespace std;

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

int main() {
    long long a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    long long g = ucln(a, b);
    cout << "Uoc chung lon nhat cua hai so la " << g << "\n";
    cout << "Boi chung nho nhat cua hai so la " << bcnn(a, b) << "\n";
    return 0;
}