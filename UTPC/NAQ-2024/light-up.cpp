#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

vector<string> grid;
int n;

int light(int i, int j) {
	if (i<0 || i>=n || j<0 || j>=n) return 0;
	if (grid[i][j]=='?') return 1;
	return 0;
}

bool in(int i, int j) {
	if (i<0 || i>=n || j<0 || j>=n) return 0;
	return 1;
}

void solve() {
	cin>>n;
	grid.resize(n);
	for (string& r : grid)
		cin>>r;
	queue<pair<pii,int>> bfs;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (grid[i][j]>='0' && grid[i][j]<='4') {
				int gol = grid[i][j]-'0';
				int cnt = 0;
				cnt += light(i-1,j);
				cnt += light(i+1,j);
				cnt += light(i,j-1);
				cnt += light(i,j+1);
				if (cnt != gol) {
					cout << 0;
					return;
				}
			}
			if (grid[i][j]=='?') {
				bfs.push({{i+1,j},0});
				bfs.push({{i-1,j},1});
				bfs.push({{i,j+1},2});
				bfs.push({{i,j-1},3});
			}
		}
	}
	vector<vector<bool>> lit(n,vector<bool>(n));
	while (bfs.size()) {
		pii c = bfs.front().f;
		int d = bfs.front().s;
		bfs.pop();
		if (!in(c.f,c.s)) continue;
		lit[c.f][c.s] = 1;
		char p = grid[c.f][c.s];
		if (p == '?') {
			cout << 0;
			return;
		} else if (p == 'X' || (p>='0' && p<='4')) continue;
		if (d==0) bfs.push({{c.f+1,c.s},d});
		if (d==1) bfs.push({{c.f-1,c.s},d});
		if (d==2) bfs.push({{c.f,c.s+1},d});
		if (d==3) bfs.push({{c.f,c.s-1},d});
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (grid[i][j]=='.' && !lit[i][j]) {
				cout << 0;
				return;
			}
	cout << 1;
}

int main() {
	solve();
	return 0;
}