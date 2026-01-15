#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;


int main() {
	long long a; cin >> a;
 	long long soluonguoc; soluonguoc = 0;
 	for(long long i = 1; i <= a; i++) {
     if(a % i == 0) {
        soluonguoc += 1;
	}
	}
	if (soluonguoc == 2) {
    cout << "A la so nguyen to" << endl;
	} 
	else if (soluonguoc > 2) {
    cout << "A khong phai la so nguyen to" << endl;
	}
	else {
    cout << "Error" << endl;
	}
	cout << "So luong uoc cua" << " " << a << " la " << soluonguoc;
	
	
	return 0;
}