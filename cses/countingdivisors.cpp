#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	for (int i=0;i<T;i++) {
		int N;cin>>N;
		unordered_map<int,int> divs;
		for (int i=2;i*i<=N;i++) {
			while (N%i==0) {
				divs[i]++;
				N/=i;
			}
		}
		if (N>1) divs[N]++;
		int ans = 1;
		for (auto pair : divs)
			ans *= pair.second + 1;
		cout<<ans<<endl;
	}
	return 0;
}