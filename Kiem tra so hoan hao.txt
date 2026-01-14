#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	long long a; cin >> a;
	long long tonguoc; tonguoc = 0;
	for(int i = 1; i < a; i++) {
		if (a % i == 0) {
			tonguoc += i;
		}
	}
	if (tonguoc == a)
		cout << "A la so hoan hao";
	else
		cout << "A khong phai la so hoan hao";
	
	
	
	return 0;
}