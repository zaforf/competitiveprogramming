#include <bits/stdc++.h>
using namespace std;

int numd(int i,int j) {
	if ((i==7 || i==0) && (j==7 || j==0)) return 2;
	if ((i==7 || i==0) || (j==7 || j==0)) return 3;
	return 4;
}

int main() {
	int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
	int k;cin>>k;
	double dp[64][k+1][8][8]; // dp[a][b][i][j]: probability that ath robot is at (i,j) after b steps
	for (int w=0;w<64;w++)
		for (int x=0;x<k+1;x++)
			for (int y=0;y<8;y++)
			for (int z=0;z<8;z++) dp[w][x][y][z]=0;
	for (int i=0;i<64;i++) dp[i][0][i/8][i%8] = 1;
	for (int p=0;p<64;p++)
		for (int l=1;l<k+1;l++)
			for (int i=0;i<8;i++)
				for (int j=0;j<8;j++)
					for (int d=0;d<4;d++) {
						int cx=i+dx[d],cy=j+dy[d];
						if (cx<0 || cx>=8 || cy<0 || cy>=8) continue;
						dp[p][l][i][j]+=dp[p][l-1][cx][cy]/numd(cx,cy);
					}
	double ans=0;
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++) {
			double prod=1;
			for (int p=0;p<64;p++)
				prod *= 1-dp[p][k][i][j];
			ans += prod;
		}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}