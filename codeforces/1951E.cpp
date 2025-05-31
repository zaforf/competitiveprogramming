#include <bits/stdc++.h>
using namespace std;


vector<int> prefix_function(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
	string s; cin>>s;
	string rev = s;
	reverse(rev.begin(), rev.end());
	string k = rev + '$' + s;
	vector<int> pi = prefix_function(k);
	for (int x : pi) cout << x << " ";
		cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}