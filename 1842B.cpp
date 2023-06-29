#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N,X;cin>>N>>X;
	vector<vector<int>> stacks(3,vector<int>(N));
	for (int i=0;i<3;i++)
		for (int j=0;j<N;j++)
			cin>>stacks[i][j];
	int a = 0;
	for (int i=0;i<3;i++) {
		for (int j=0;j<N;j++) {
			if ((X|stacks[i][j])==X)
				a=a|stacks[i][j];
			else break;
			if (a==X)
				break;
		}
	}
	if (a==X)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}

int main() {
	int T;cin>>T;
	while (T--)
		solve();
	return 0;
}