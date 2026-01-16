#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, l;
  float bus_speed, walk_speed;
  cin >> n >> m >> l >> bus_speed >> walk_speed;
  vector<array<int,3>> events;
  unordered_map<int, int, custom_hash> bus_map;
  for (int i=0;i<n;i++) {
    int s, e; cin >> s >> e;
    bus_map[s] = max(bus_map[s], e);
  }
  for (auto &[s, e] : bus_map)
    events.push_back({s, -1, e});
  vector<float> ans(m);
  for (int i=0;i<m;i++) {
    int t; cin >> t;
    events.push_back({t, 0, i});
  }
  sort(events.begin(), events.end());
  int best_start = -1, best_end = -1;
  float best_time = 1e18;
  for (auto &[start, type, end] : events) {
    if (type == -1) { // new bus
        float bus_time = (float)(end - start) / bus_speed + (float)(l - end) / walk_speed;
        if (bus_time < best_time)  {
            best_start = start;
            best_end = end;
            best_time = bus_time;
        }
    } else {
        int idx = end;
        if (best_start == -1 || start > best_end) {
            ans[idx] = (float)(l - start) / walk_speed;
        } else {
            float walk_time = (float)(l-start) / walk_speed;
            float bus_time = (float)(best_end - best_start) / bus_speed + (float)(l - best_end) / walk_speed;
            ans[idx] = min(walk_time, bus_time);
        }
    }
  }
  for (auto &a : ans) {
    cout << fixed << setprecision(10) << a << endl;
  }
  return 0;
}