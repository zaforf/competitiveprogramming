#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b; cin>>n>>a>>b;
	vector<int> v(n-1);
	for (int& i : v) cin>>i;
	int minw = *min_element(v.begin(),v.end());
	int maxw = *max_element(v.begin(),v.end());
	if (minw < a || maxw > b || (minw != a && maxw != b))
		cout << -1;
	else {
		if (minw != a)
			cout << a << endl;
		else if (maxw != b)
			cout << b << endl;
		else 
			for (int i=a;i<=b;i++)
				cout << i << endl;
	}
	return 0;
}