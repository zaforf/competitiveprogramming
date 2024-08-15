#include <bits/stdc++.h>
using namespace std;

bool shareLetter(string a, string b) {
	for (char c : a) {
		if (b.find(c) != string::npos) {
			return true;
		}
	}
	return false;
}

void solve() {
	int n,m; cin>>n>>m;
	vector<int> BG,BR,BY,GR,GY,RY;
	vector<string> ps;
	for (int i=0;i<n;i++) {
		string s; cin>>s;
		ps.push_back(s);
		if (s=="BG") BG.push_back(i);
		else if (s=="BR") BR.push_back(i);
		else if (s=="BY") BY.push_back(i);
		else if (s=="GR") GR.push_back(i);
		else if (s=="GY") GY.push_back(i);
		else if (s=="RY") RY.push_back(i);
	}
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		if (b<a) swap(a,b);
		a--;b--;

		if (shareLetter(ps[a],ps[b])) {
			cout << b-a << '\n';
			continue;
		}

		int ans = 1e9;
		bool blue1 = ps[a].find('B') != string::npos; 
		bool green1 = ps[a].find('G') != string::npos;
		bool red1 = ps[a].find('R') != string::npos;
		bool yellow1 = ps[a].find('Y') != string::npos;
		bool blue2 = ps[b].find('B') != string::npos;
		bool green2 = ps[b].find('G') != string::npos;
		bool red2 = ps[b].find('R') != string::npos;
		bool yellow2 = ps[b].find('Y') != string::npos;

		if (blue1 && green2 || green1 && blue2) {
			auto it = lower_bound(BG.begin(),BG.end(),a);
			if (it!=BG.end()) ans = min(ans,abs(b-*it) + abs(*it-a));
			if (it!=BG.begin()) {
				it = prev(it);
				ans = min(ans,abs(b-*it) + abs(*it-a));
			}
		}

		if (blue1 && red2 || red1 && blue2) {
		    auto it = lower_bound(BR.begin(), BR.end(), a);
		    if (it != BR.end()) ans = min(ans, abs(b - *it) + abs(*it - a));
		    if (it != BR.begin()) {
			    it = prev(it);
			    ans = min(ans, abs(b - *it) + abs(*it - a));
			}
		}

		if (blue1 && yellow2 || yellow1 && blue2) {
		    auto it = lower_bound(BY.begin(), BY.end(), a);
		    if (it != BY.end()) ans = min(ans, abs(b - *it) + abs(*it - a));
		    if (it != BY.begin()) {
			    it = prev(it);
			    ans = min(ans, abs(b - *it) + abs(*it - a));
			}
		}

		if (green1 && red2 || red1 && green2) {
		    auto it = lower_bound(GR.begin(), GR.end(), a);
		    if (it != GR.end()) ans = min(ans, abs(b - *it) + abs(*it - a));
		    if (it != GR.begin()) {
			    it = prev(it);
			    ans = min(ans, abs(b - *it) + abs(*it - a));
			}
		}

		if (green1 && yellow2 || yellow1 && green2) {
		    auto it = lower_bound(GY.begin(), GY.end(), a);
		    if (it != GY.end()) ans = min(ans, abs(b - *it) + abs(*it - a));
		    if (it != GY.begin()) {
			    it = prev(it);
			    ans = min(ans, abs(b - *it) + abs(*it - a));
			}
		}

		if (red1 && yellow2 || yellow1 && red2) {
		    auto it = lower_bound(RY.begin(), RY.end(), a);
		    if (it != RY.end()) ans = min(ans, abs(b - *it) + abs(*it - a));
		    if (it != RY.begin()) {
			    it = prev(it);
			    ans = min(ans, abs(b - *it) + abs(*it - a));
			}
		}
		if (ans==1e9) cout << -1 << '\n';
		else cout << ans << '\n';
	}

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}