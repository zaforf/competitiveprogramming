#include <bits/stdc++.h>
using namespace std;

char match(int p) {
	if (p == 0) return '1';
	if (p == 1) return '5';
	if (p == 2) return '4';
	if (p == 3) return '3';
	return '0';
}

int tx, ty, bx, by;
int nx, ny;

bool check() {
	if (nx < tx || nx > bx || ny < ty || ny > by) return true;
	return false;
}

void solve() {
	int n, m; cin>>n>>m;
	vector<string> carp(n);
	for (string& s : carp) cin>>s;
	tx = 0, ty = 0, bx = n-1, by = m-1;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int d = 0;
	int p = 0, ans = 0;
	while (tx < bx && ty < by) {
		int cx = tx, cy = ty, t = 0;
		d = 0, p = 0;
		do {

			if (carp[cx][cy] == match(p)) p++;
			else {
				p = 0;
				if (!t && carp[cx][cy] == match(p)) p++;
			}
			if (p == 4) {
				ans++;	
				p = 0;
			}
			nx = cx + dx[d], ny = cy + dy[d];
			if (check()) {
				d = (d + 1) % 4;
				nx = cx + dx[d], ny = cy + dy[d];
			}
			cx = nx, cy = ny;
			if (cx == tx && cy == ty) t=1;
		} while (!t || p);
		tx++, ty++, bx--, by--;
	}
	cout << ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}