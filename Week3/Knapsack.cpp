#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


double findMaxVal(vector <int> v, vector <int> w, int W) {
    double V = 0;
    while( W > 0 ) {
        int max = v.size() - 1;
        int a = min(w[max], W);
        V += a *((double) v[max] / w[max]);
        W -= a;
        v.pop_back();
		w.pop_back();   
    }
	
	return V;
}


void pairsort(vector <double> r, vector <int> &z) {
	int n = z.size();
	pair <double, int> x[n];
	for(int i = 0;i < n; i++){
		x[i] = make_pair(r[i],z[i]);
	}
	sort(x, x + n);
	for(int i = 0;i < n; i++){
		r[i] = x[i].first;
		z[i] = x[i].second;
	}
}

int main() {
    int n , W;
    cin >> n >> W; 
    vector <int> v(n),w(n);
    vector <double> r(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
		r[i] =(double) v[i] / w[i];
    }
	pairsort(r,v);
	pairsort(r,w);	
    r.clear();
    cout << fixed << setprecision(3) << findMaxVal(v, w, W);
    return 0;
}
