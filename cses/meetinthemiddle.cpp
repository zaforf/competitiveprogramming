#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
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
    unordered_map<long long,long long,custom_hash> fhalfcnt;
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