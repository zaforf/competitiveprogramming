#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, MOD;
  cin >> N >> MOD;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if (N>MOD) {
    cout<<"YES";return 0;
  }

  vector<vector<int>> dp(N+1, vector<int>(MOD, 0));
  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < MOD; j++) {
      if (dp[i][j]) {
          dp[i + 1][(j + A[i]) % MOD]++;dp[i+1][j]+=dp[i][j];
      }
    }
  }

  cout << (dp[N][0] > 1 ? "YES" : "NO") << endl;
  return 0;
}
