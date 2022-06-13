#include <bits/stdc++.h>
#include <vector>

#define ll long long
const ll M = 1e9 + 7;

using namespace std;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, time; 
    cin >> n >> time;
    int ans=0, l=0, r=0, book, curr = 0;
    vi books(n);
    while (n--) {
        cin >> books[books.size()-n-1];
    }
    for (;l<books.size();l++){
        while (r<books.size() && curr+books.at(r)<=time) {
            curr+=books.at(r);ans=max(r-l+1,ans);r++;
        }
        curr-=books.at(l);
    }
    cout << ans;
    return 0;
}

