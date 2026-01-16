#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 2; i <= n; i++) {
        cout << "? 1 " << i << endl;
        cin >> a[i-1];
    }
    vector<int> nums; for (int i = 1; i <= n; i++) nums.push_back(i);
    vector<int> b(n);
    for (int i=n-1;i>=0;i--) {
        int added = a[i] - (i > 0 ? a[i-1] : 0);
        // find the (added+1)th biggest in nums
        int v = nums[i - added];
        // remove v from nums
        nums.erase(nums.begin() + (i - added));
        b[i] = v;
    }
    int ans = 0;
    // find length of longest increasing subsequence, n^2 works
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (b[j] < b[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << "! " << ans << endl;
    return 0;
}