#include<iostream>
#include<vector>
using namespace std;

//Naive algorithm
int findFib(int n) {
if(n <= 1)
	return n;
else
	return findFib(n-1) + findFib(n-2);
}


//fast Algorithm
int findFibFast(int n) {
	//vector <int> a(n + 1,0);
	int p1 = 0;
	int p2 = 1;
	int c = 1;
	
	for(int i = 3; i <= n; i++) {
		p1 = p2;
		p2 = c;
		c = (p1 + p2) % 10;
	}
	return c;	
}


int main() {
	int n;
	cin >> n;
	cout << findFibFast(n);
}
