#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	int trash;
	cout << "digit" << endl; cin>>trash;
	cout << "digit" << endl; cin>>trash;
	cout << "add -8" << endl; cin>>trash;
	cout << "add -4" << endl; cin>>trash;
	//1,2,3,4
	int div2;
	cout << "div 2" << endl;
	cin>>div2;
	if (div2) {
		// 1, 2
		cout << "div 2" << endl;
		cin>>trash;
		cout << "add " << n - 1 << endl;
		cin>>trash;
		cout <<"!" <<endl;
		cin>>trash;
		if (trash == -1) exit(0);
	} else {
		cout << "div 3" << endl;
		cin>>trash;
		cout << "add " << n - 1 << endl;
		cin>>trash;
		cout <<"!" <<endl;
		cin>>trash;
		if (trash == -1) exit(0);
	}

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}