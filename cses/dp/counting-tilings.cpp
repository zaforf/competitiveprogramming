#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD=1e9+7;
int n,m;
ll mem[1001][1<<10];
bool valid[1<<10] = {0};

int count(int rows, int above) {
	if (mem[rows][above]!=-1) return mem[rows][above];
	ll ret=0;
	if (rows>1) {
		for (int i=0;i<(1<<n);i++)
			if (!(i&above) && valid[i|above])
				ret = (ret+count(rows-1,i))%MOD;
		mem[rows][above] = ret;
		return ret;
	} else if (valid[above])
		return 1;
	return 0;
}

int main() {
	cin>>n>>m;
	for (int i=0;i<(1<<n);i++) {
		if ((n-__builtin_popcount(i))%2) continue;
		bool ok = true;
		for (int j=0;j<n-1;j++)
			if (!(i&(1<<j)) && (i&(1<<(j+1)))) {ok=false;break;}
			else if (!(i&(1<<j))) j++;
		valid[i]=ok;
	}
	memset(mem,-1,sizeof(mem));
	cout<<count(m,0);
	return 0;
}