#include <bits/stdc++.h>
using namespace std;

vector<string> grid(8);
int ans;
bool col[8],dl[15],dr[15];

void chess(int r) {
	if (r==8) {
		ans++;
		return;
	}
	for (int c=0;c<8;c++) {
		if (!(grid[r][c]=='*') && !col[c] && !dl[8+r-c] && !dr[r+c]) {
			col[c]=true;dl[8+r-c]=true;dr[r+c]=true;
			chess(r+1);
			col[c]=false;dl[8+r-c]=false;dr[r+c]=false;
		}
	}
}


int main() {
	for (int i=0;i<8;i++) cin>>grid[i];
	chess(0);
	cout<<ans;
	return 0;
}