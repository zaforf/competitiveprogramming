#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

struct Event
{
    int start,end,index;
};

bool cmp(const Event& a, const Event& b) {return a.start<b.start;}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> final(n);
    vector<Event> ordered;
    for (int i=0;i<n;i++) {
        ordered.push_back(Event());
        cin >> ordered[i].start >> ordered[i].end;
        ordered[i].index = i;
    }
    sort(ordered.begin(),ordered.end(),cmp);
    multiset<pair<int,int>> endtimes;
    int most=0;
    for (int i=0;i<n;i++) {
        if (endtimes.size()==0) {
            endtimes.insert(make_pair(ordered[i].end,1));
            final[ordered[i].index] = 1;
        }
        else {
            if (ordered[i].start<=(*endtimes.begin()).first) {
                final[ordered[i].index] = endtimes.size()+1;
                endtimes.insert(make_pair(ordered[i].end,endtimes.size()+1));
            }
            else {
                final[ordered[i].index] = (*endtimes.begin()).second;
                endtimes.insert(make_pair(ordered[i].end,(*endtimes.begin()).second));
                endtimes.erase(endtimes.begin());
            }
        }

    }
    for (int i=0;i<n;i++) {
        most = max(most,final[i]);
    }
    cout << most << "\n";
    for (int i=0;i<n;i++) {
        cout << final[i] << " ";
    }
}