#include<iostream>
using namespace std;

int gcd(int a, int b) {
	
	int gcd = 0;
	for(int i = 1; i <= a + b; i++) {
		if(!(a % i) && !(b % i))
			gcd = i;
	}		
	return gcd;
}

int gcdFast(int a, int b) {
	if(b == 0) {
		return a;
	}
	else {
		a = a % b;
		return gcdFast(b,a);	
	}
	
}


int main() {
	int a, b;
	cin >> a >> b;
	cout << gcdFast(a, b);
}
