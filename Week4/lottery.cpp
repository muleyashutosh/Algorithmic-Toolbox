#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int count_winnings(vector <pair<int, int>> segments, int l, int h, int key) {
    int count = 0;
    if(l <= h) {
        int mid = (l + h) / 2;
 
        if(key >= segments[mid].first && key <= segments[mid].second) {
            count++;
        }
        if(l == h) {
            return count;
        }
        
        if(key < segments[mid].first)
            count += count_winnings(segments, l, mid-1, key);
        else if (key > segments[mid].second)
            count += count_winnings(segments,mid+1 , h, key);
        

    }
    return count;
}



int main () {
    int s, p;
    cin >> s >> p;
    vector <pair<int, int>> segments(s);
    for(int i = 0 ; i < s; i++) {
        int start,end;
        cin >> start >> end;
        segments[i] = make_pair(start,end);
    }
    // cout << endl;
    // for(int i = 0; i < segments.size() ; i++) {
    //     cout << segments[i].first << " " << segments[i].second << endl;
    // }
    sort(segments.begin(), segments.end());
    // cout << "After sorting->>>>" << endl;
    // for(int i = 0; i < segments.size() ; i++) {
    //     cout << segments[i].first << " " << segments[i].second << endl;
    // }

    while(p--) {
        int key;
        cin >> key;
        cout << count_winnings(segments,0,s-1,key) << " ";
    }
}
