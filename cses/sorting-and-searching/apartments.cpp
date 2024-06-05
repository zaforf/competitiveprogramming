#include <bits/stdc++.h>
using namespace std;

template<class T> using V = vector<T>;
#define all(x) (x).begin(),(x).end()

int main() {
    // freopen("std.in", "r", stdin);
	// freopen("std.out", "w", stdout);
    int np,na,range;cin>>np>>na>>range;
    V<int> temp(np);
    for (int& a:temp){cin>>a;}
    sort(all(temp),greater<int>());
    stack<int> ppl;
    for (int &a:temp){ppl.push(a);}
    temp.clear();temp.resize(na);
    for (int& a:temp){cin>>a;}
    sort(all(temp),greater<int>());
    stack<int> aps;
    for (int &a:temp){aps.push(a);}
    int ans=0;
    while (!ppl.empty()&&!aps.empty()){
        if (abs(ppl.top()-aps.top())<=range) {
            ppl.pop();
            aps.pop();
            ans++;
        } else if (ppl.top()>aps.top()) {
            aps.pop();
        }
        else {
            ppl.pop();
        }
    }
    cout<<ans;
    return 0;
}