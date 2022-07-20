#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

struct gap {
    int size,num;
    bool isend;
};
struct compare {
    bool operator()(const gap& a,const gap& b) const {
        int aval=0,bval=0;
        if (a.isend) {aval=a.size-1;}
        else {aval=(a.size-(a.num+1))/(a.num+2);}
        if (b.isend) {bval=b.size-1;}
        else {bval=(b.size-(b.num+1))/(b.num+2);}
        return aval<bval;
    }
};

int main() {
    freopen("socdist1.in", "r", stdin);
	freopen("socdist1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<gap,compare> gaps;
    int n,curr=0; cin>>n;
    string str; cin>>str;
    bool first = true;
    if (str.find("1") != -1) {
        for (int i=0;i<n;i++) {
            if (str[i]=='0') {curr++;}
            else if (first && curr>0) {gaps.insert({curr,0,true});curr=0;first=false;}
            else if (curr>0) {gaps.insert({curr,0,false});curr=0;}
            else {first = false;}
        }
        if (curr>0) {gaps.insert({curr,0,true});}
        for (int i=0;i<2;i++) {
            gap best = *(--gaps.end());
            gaps.erase(gaps.find(best));
            if (best.isend) {
                gaps.insert({best.size-1,0,false});    
            }
            else {
                gaps.insert({best.size,best.num+1,false});
            }
        }
        int ans = n;
        for (auto& a : gaps) {
            if (!a.isend) {ans = min(ans,((a.size-(a.num))/(a.num+1))+1);}
        }
        cout<<ans;
    }
    else {cout<<n-1;}
}