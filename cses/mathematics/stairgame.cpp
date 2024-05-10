#include <bits/stdc++.h>
using namespace std;

// consider every other pile and proceed as Nim
// if p2 takes from pile k where k is even,
// p1 takes same amt from k-1

int main() {
	int t;cin>>t;
	while (t --> 0) {
		int n,inp,x=0;cin>>n;
		for (int i=0;i<n;i++) {
			cin>>inp;
			if (i%2) x ^= inp;
		}
		cout << (x?"first\n":"second\n");
	}
	return 0;
}