#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pair<int, int>> lamps;
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      lamps.push_back({a, -b});
    }
    sort(lamps.begin(), lamps.end());

    long long ans = 0, x = 0, sz = 0;
    while (x < N) {
      while (x < N && sz < lamps[x].first) {
        ans += lamps[x].second;
        sz++;
        x++;
        if (x < N && lamps[x].first != lamps[x - 1].first) {
          break;
        }
      }
      while (x < N && lamps[x].first == sz) {
        x++;
      }
      sz = 0;
    }
    cout << -ans << endl;
  }
  return 0;
}