#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100001;
int succ[MAX_N];
bool vis[MAX_N];
int N;

int findloop(int i) {
    if (i==succ[i]) {
        vis[i] = true;
        return 1;
    }
    int a = succ[i];
    int b = succ[succ[i]];
    while (a!=b) {
        a = succ[a];
        b = succ[succ[b]];
    }
    if (vis[a])
        return 0;
    a = succ[a];
    vis[a] = true;
    int ans = 1;
    while (a!=b) {
        ans++;
        a=succ[a];
        vis[a]=true;
    }
    return ans;
}

int main() {
    // freopen("shuffle.in", "r", stdin);
    // freopen("shuffle.out", "w", stdout);
    cin>>N;
    for (int i=1;i<N+1;i++) {
        cin>>succ[i]>>succ[i];
    }
    int ans=0;
    for (int i=1;i<N+1;i++)
        if (!vis[i])
            ans+=findloop(i);
    cout<<ans;
    return 0;
}