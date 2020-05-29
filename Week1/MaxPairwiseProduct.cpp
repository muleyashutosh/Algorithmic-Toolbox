#include <iostream>
#include<cstdlib>
#include<vector>

using namespace std;

long long int MaxPairwiseProduct(vector<int> num) {
	long long int result = 0;
	int n = num.size();
	for(int i = 0 ; i < n - 1; i++ ) {
		for(int j = i + 1; j < n; j++) {
			if(((long long)num[i] * num[j]) > result) {
				result = (long long)num[i] * num[j];
			}
		}
	}
	return result;
}

long long MaxPairwiseProduct2(vector<int> num) {
	long long int result = 0;
	int maxindex1 = -1, maxindex2 = -1;
	int max1 = 0, max2 = 0;
	int  n = num.size();
	for(int i = 0; i < n; i++) {
		if(max1 < num[i]) {
			max1 = num[i];
			maxindex1 = i;
		}
	}
	for(int i = 0; i < n; i++) {
		if(i != maxindex1 && max2 < num[i]) {
			max2 = num[i];
			maxindex2 = i;
		}
	}
	//cout << endl << max1 << " " << max2;
	result = (long long)max1 * max2;
	return result;
}

int main() {
	int n;
	cin >> n;
//	while(true) {
//		n = rand() % 1000;
//		cout << n << endl;
 		vector<int> num(n);
		for(int i = 0; i < n; i++) {
//			long int x = rand() % 10000;
//			num.push_back(x);
//			cout << x << " ";
			cin >> num[i];
		}
		
//		long long int res1 = MaxPairwiseProduct(num);
		long long int result = MaxPairwiseProduct2(num);
//		if(res1 != res2){
//			cout << endl << res1 << " " << res2 << endl;
//			break;
//		}
//		else{
//			cout << endl << "____________OK____________" << endl;
//		}
//	}
	cout << result;

}

