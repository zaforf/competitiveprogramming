#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;
 
using namespace std;
 
struct Event {
    l time;
    bool starting;
};
 
bool compare (Event& a,Event& b){
    return a.time < b.time;
}
 
int main() {
    l n; cin >> n;
    vector<Event> events;
    for (int i=0;i<n;i++) {
        l a,b; cin >> a >> b;
        events.push_back({a,true});
        events.push_back({b,false});
    }
    sort(events.begin(),events.end(),compare);
    l ans=0,ppl=0;
    for (auto ev : events) {
        if (ev.starting)
            ppl+=1;
        else
            ppl-=1;
        ans=max(ans,ppl);
    }
    cout << ans << "\n";
}
