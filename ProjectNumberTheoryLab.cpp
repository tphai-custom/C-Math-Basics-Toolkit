
#include <stdio.h>
#include <string.h>

void printMenu() {
    printf("NUMBER THEORY LAB\n");
    printf("Chon 1 chuc nang:\n\n");

    printf("1) PRIME LAB (So nguyen to)\n");
    printf("   1.1 Kiem tra 1 so co phai nguyen to khong\n");
    printf("   1.2 Liet ke cac so nguyen to trong [1..N]\n");
    printf("   1.3 Dem so luong so nguyen to trong [1..N]\n\n");

    printf("2) DIVISOR LAB (Uoc so)\n");
    printf("   2.1 Dem so uoc cua n\n");
    printf("   2.2 Liet ke cac uoc cua n\n");
    printf("   2.3 Tinh tong uoc cua n\n");
    printf("   2.4 Tinh tong uoc rieng (khong tinh chinh no)\n\n");

    printf("3) GCD/LCM LAB (UCLN/BCNN)\n");
    printf("   3.1 UCLN\n");
    printf("   3.2 BCNN (dua tren UCLN)\n");
    printf("   3.3 Kiem tra 2 so cung nhau nguyen to\n\n");

    printf("Nhap lua chon (vd: 1.2 hay 3.1): ");
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
    char choice[16];
    if (scanf("%15s", choice) != 1) return 0;

    if (strcmp(choice, "1.1") == 0) {
        long long a;
        printf("Nhap so a: ");
        scanf("%lld", &a);
        if (snt(a)) printf("%lld la so nguyen to\n", a);
        else printf("%lld khong phai la so nguyen to\n", a);
    }

    else if (strcmp(choice, "1.2") == 0) {
        long long N;
        printf("Nhap N: ");
        scanf("%lld", &N);
        if (N < 2) {
            printf("Khong co so nguyen to trong [1..%lld]\n", N);
        } else {
            printf("Cac so nguyen to trong [1..%lld]:\n", N);
            for (long long i = 2; i <= N; i++) {
                if (snt(i)) printf("%lld ", i);
            }
            printf("\n");
        }
    }

    else if (strcmp(choice, "1.3") == 0) {
        long long N;
        printf("Nhap N: ");
        scanf("%lld", &N);
        long long cnt = 0;
        for (long long i = 2; i <= N; i++) if (snt(i)) cnt++;
        printf("So luong so nguyen to trong [1..%lld] la %lld\n", N, cnt);
    }

    else if (strcmp(choice, "2.1") == 0) {
        long long a;
        printf("Nhap n: ");
        scanf("%lld", &a);
        if (a == 0) {
            printf("n = 0 khong hop le de dem uoc theo cach thong thuong.\n");
        } else {
            printf("So uoc cua %lld la %lld\n", a, demUoc(a));
        }
    }

    else if (strcmp(choice, "2.2") == 0) {
        long long a;
        printf("Nhap n: ");
        scanf("%lld", &a);
        if (a == 0) {
            printf("n = 0 khong hop le.\n");
        } else {
            if (a < 0) a = -a;
            printf("Cac uoc cua n la:\n");
            for (long long i = 1; i * i <= a; i++) {
                if (a % i == 0) {
                    printf("%lld ", i);
                    long long j = a / i;
                    if (j != i) printf("%lld ", j);
                }
            }
            printf("\n");
        }
    }

    else if (strcmp(choice, "2.3") == 0) {
        long long a;
        printf("Nhap n: ");
        scanf("%lld", &a);
        if (a == 0) printf("n = 0 khong hop le.\n");
        else printf("Tong cac uoc cua n la %lld\n", tongUoc(a));
    }

    else if (strcmp(choice, "2.4") == 0) {
        long long a;
        printf("Nhap n: ");
        scanf("%lld", &a);
        printf("Tong uoc rieng (khong tinh chinh no) la %lld\n", tongUocRieng(a));
    }

    else if (strcmp(choice, "3.1") == 0) {
        long long a, b;
        printf("Nhap a: ");
        scanf("%lld", &a);
        printf("Nhap b: ");
        scanf("%lld", &b);
        printf("Uoc chung lon nhat la %lld\n", ucln(a, b));
    }

    else if (strcmp(choice, "3.2") == 0) {
        long long a, b;
        printf("Nhap a: ");
        scanf("%lld", &a);
        printf("Nhap b: ");
        scanf("%lld", &b);
        printf("Boi chung nho nhat la %lld\n", bcnn(a, b));
    }

    else if (strcmp(choice, "3.3") == 0) {
        long long a, b;
        printf("Nhap a: ");
        scanf("%lld", &a);
        printf("Nhap b: ");
        scanf("%lld", &b);
        if (ucln(a, b) == 1) printf("Hai so cung nhau nguyen to.\n");
        else printf("Hai so KHONG cung nhau nguyen to.\n");
    }

    else {
        printf("Du lieu khong hop le.\n");
    }

    return 0;
}
