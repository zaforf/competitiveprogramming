#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define all(x) (x).begin(),(x).end()

vector<long long> subsets(const vector<int> &inp) {
    vector<long long> v(1,0);
    for (int i=0;i<inp.size();i++) {
        v.resize(v.size()*2);
        for (int j=0;j<v.size()/2;j++) {
            v[j+v.size()/2]=inp[i]+v[j];
        }
    }
    sort(all(v));
    return v;
}

int main() {
    int N,SUM;cin>>N>>SUM;
    vector<int> nums(N);
    for (int& i:nums) cin>>i;
    long long ans=0;
    vector<long long> fhalf = subsets(vector<int>(nums.begin()+nums.size()/2,nums.end()));
    vector<long long> shalf = subsets(vector<int>(nums.begin(),nums.begin()+nums.size()/2));
    unordered_map<long long,long long> fhalfcnt;
    for (long long & a:fhalf) {
        if (fhalfcnt.count(a))
            fhalfcnt[a]=fhalfcnt[a]+1;
        else
            fhalfcnt[a]=1;
    }
    for (long long & a:shalf) {
        if (fhalfcnt.count(SUM-a))
            ans+=fhalfcnt[SUM-a];
    }
    cout<<ans;
    return 0;
}