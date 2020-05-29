#include<iostream>
#include<algorithm>

using namespace std;


//long long lcm (int a, int b) {
//int x = min(a, b);
//int y = max(a, b);
////cout << x << " " << y;
//for(long long i = x; i; i = i + x) {
//	//cout << i << " ";	
//	if(!(i % y))
//		return i;	
//}
//return -1;
//}

int gcdFast(int a, int b) {
	if(b == 0) {
		return a;
	}
	else {
		a = a % b;
		return gcdFast(b,a);	
	}
	
}


long long lcmFast(int a, int b){	
	return ((long long)a * b) / (gcdFast(a, b));
}









int main() {
int a, b;
cin >> a >> b;
cout << endl <<lcmFast(a,b);

}
