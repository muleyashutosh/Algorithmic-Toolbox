#include<iostream>
#include<vector>
using namespace std;

//Naive algorithm
long long findFib(int n) {
if(n <= 1)
	return n;
else
	return findFib(n-1) + findFib(n-2);
}


//fast Algorithm
long long findFibFast(int n) {
	//vector <long long> a(n + 1,0);
	if(n <= 1){
		return n;
	}
	long long p1 = 0;
	long long p2 = 1;
	long long c = 1;
	
	for(int i = 3; i <= n; i++) {
		p1 = p2;
		p2 = c;
		c = p1 + p2;
	}
	return c;	
}


int main() {
	int n;
	cin >> n;
	cout << findFibFast(n);
}
