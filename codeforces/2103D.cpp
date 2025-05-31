#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), p(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mx = max(0, *max_element(a.begin(), a.end())) + 1;
        for (int i = 0; i < n; i++) if (a[i] == -1) a[i] = mx;
 
        int l = 1, r = n;
        for (int k = 1; k <= mx; k++)
        {
            int mr = n - 1;
            while (mr >= 0 && a[mr] <= k) mr--;
            for (int i = 0; i < mr; i++)
            {
                if (a[i] == k)
                {
                    p[i] = ((k & 1) ? r-- : l++);
                }
            }
            for (int i = n - 1; i > mr; i--)
            {
                if (a[i] == k)
                {
                    p[i] = ((k & 1) ? r-- : l++);
                }
            }
        }
        for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
    }
    return 0;
}
