#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
int c[86];
string s;
bool vis[49];
int ans=0;

bool poss(int x, int y) {
	if (x<0 || x>=7 || y<0 || y>=7 || vis[7*x+y]) return false;
	return true; 
}

void dfs(int x, int y, int d) {
	if (x==6 && y==0) {
		if (d==48) ans++;
		return;
	}
	vis[7*x+y]=true;
	for (int i=0;i<4;i++) {
		if (s[d]=='?' || c[s[d]]==i) {
			// check if path splits grid into two unvisited parts
			if (i%2 && !poss(x,y+2*dy[i]) && poss(x+dx[(i+1)%4],y+dy[i]) && poss(x+dx[(i+3)%4],y+dy[i])) continue;
			if (!(i%2) && !poss(x+2*dx[i],y) && poss(x+dx[i],y+dy[(i+1)%4]) && poss(x+dx[i],y+dy[(i+3)%4])) continue;
			if (poss(x+dx[i],y+dy[i]+1) && poss(x+dx[i]+1,y+dy[i]) && !poss(x+dx[i]+1,y+dy[i]+1)) continue;
			if (poss(x+dx[i],y+dy[i]-1) && poss(x+dx[i]-1,y+dy[i]) && !poss(x+dx[i]-1,y+dy[i]-1)) continue;
			if (poss(x+dx[i],y+dy[i]+1) && poss(x+dx[i]-1,y+dy[i]) && !poss(x+dx[i]-1,y+dy[i]+1)) continue;
			if (poss(x+dx[i],y+dy[i]-1) && poss(x+dx[i]+1,y+dy[i]) && !poss(x+dx[i]+1,y+dy[i]-1)) continue;
			
			if (!poss(x+dx[i],y+dy[i])) continue;
			dfs(x+dx[i],y+dy[i],d+1);
		}
	}
	vis[7*x+y]=false;
}

int main() {
	cin >> s;
	c['U'] = 0;c['R'] = 1;c['D'] = 2;c['L'] = 3;
	dfs(0,0,0);
	cout << ans;
	return 0;
}