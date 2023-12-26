#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;cin>>N;
	vector<vector<int>> right,up;
	vector<int> stopped(N);
	vector<bool> found(N);
	for (int i=0;i<N;i++) {
		string c; cin>>c;
		int a,b;cin>>a>>b;
		if (c=="E")
			right.push_back({b,a,i});
		else
			up.push_back({a,b,i});
	}
	sort(right.begin(),right.end());
	sort(up.begin(),up.end());
	for (int i=0;i<up.size();i++) {
		for (int j=0;j<right.size();j++) {
			if (right[j][1]>up[i][0] or right[j][0]<up[i][1] or found[right[j][2]]) continue;
			int diffx = up[i][0]-right[j][1];
			int diffy = right[j][0]-up[i][1];
			if (diffx==diffy) continue;
			if (diffx>diffy) {
				// cout << right[j][2]+1<<" was stopped by "<<up[i][2]+1<<endl;
				found[right[j][2]]=true;
				stopped[up[i][2]] += stopped[right[j][2]]+1;
			} else {
				stopped[right[j][2]] += stopped[up[i][2]]+1;
				// cout << up[i][2]+1<<" was stopped by "<<right[j][2]+1<<endl;
				break;
			}
		}
	}
	for (auto a : stopped)
		cout<<a<<"\n";
	return 0;
}