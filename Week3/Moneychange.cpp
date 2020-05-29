#include<iostream>
using namespace std;

int main() {
	int m;
	int coins = 0;
	//int count = 0;
	cin >> m;
	while(m > 0) {
		if(m >= 10) {
			coins += (m / 10);
			m = m % 10;
		}
		else if (m >= 5) {
			coins += (m / 5);
			m = m % 5;
		}
		else {
			coins += m;
			m = 0;
		}
	}
	cout << coins;
}
