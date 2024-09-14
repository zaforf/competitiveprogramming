#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second

int dp[200001];
pair<int, int> dq[200001];
int top = 0, pos = 0;

void add(int x, int y) {
	while (top>1 && (y-dq[top].y)*(dq[top-1].x-dq[top].x) >
					(dq[top].y-dq[top-1].y)*(dq[top].x-x))
		top--;
	dq[++top] = {x,y};
}

int32_t main() {
	int n,c; cin>>n>>c;
	int h[n]; for (int& i : h) cin>>i;
	add(h[0],h[0]*h[0]);
	for (int i=1;i<n;i++) {
		while (pos<top && dq[pos+1].x*(-2*h[i]) + dq[pos+1].y < 
						  dq[pos].x*(-2*h[i]) + dq[pos].y)
			pos++;
		dp[i] = h[i]*h[i] + dq[pos].x*(-2*h[i]) + dq[pos].y + c;
		add(h[i],dp[i] + h[i]*h[i]);
	}
	cout << dp[n-1];
	return 0;
}