#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


vector <int> count_lottery(vector <pair<int,char>> comb, vector <int> points) {
    unordered_map<int,int> point_counts;
    
    for(int x: points) {
        point_counts[x] = 0;
    }
    int count_l = 0;
    for(int i = 0 ; i < comb.size(); i++) {
        if(comb[i].second == 'l')
            count_l++;
        else if (comb[i].second == 'p') {
            if(point_counts[comb[i].first] == 0)
                point_counts[comb[i].first] += count_l;
        }
        else if (comb[i].second == 'r')
            count_l--;
        
    }   
    vector <int> cnt(points.size());
    //cout << "points_size" << points.size() << endl;
    for(int i = 0; i < cnt.size(); i++) {
       cnt[i] = point_counts[points[i]];
    }
    return cnt;
}


int main() {
    int s, p;
    cin >> s >> p;
    vector <pair<int,char>> comb;
    vector <int> points(p);
    for(int i = 0; i < s; i++) {
        int x,y;
        cin >> x >> y;
        comb.push_back(make_pair(x,'l'));
        comb.push_back(make_pair(y,'r'));
    }

    for(int i = 0 ; i < p; i++) {
        cin >> points[i];
        comb.push_back(make_pair(points[i],'p'));
    }

    sort(comb.begin(), comb.end());

    vector <int> count = count_lottery(comb,points);
    for(int x : count) 
        cout << x << " ";

}
