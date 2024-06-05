#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	long long t[n];
	for (long long &i : t) cin>>i;
	cout << max(2 * *max_element(t,t+n),accumulate(t,t+n,0ll));
	return 0;
}