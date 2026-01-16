#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<set<int>> mems;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        set<int> current_mem;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            current_mem.insert(x);
        }

        if (current_mem.count(1)) {
            set<int> complement;
            for (int j = 1; j <= n; j++) {
                if (!current_mem.count(j)) complement.insert(j);
            }
            mems.push_back(complement);
        } else {
            mems.push_back(current_mem);
        }
    }

    sort(mems.begin(), mems.end(), [](const set<int>& a, const set<int>& b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        return a < b;
    });
    
    // Remove duplicate memories
    mems.erase(unique(mems.begin(), mems.end()), mems.end());
    
    int unique_mems_count = mems.size();
    vector<int> group(n + 1, 0);
    int gc = 1;
    bool good = true;

    for (const auto& mem : mems) {
        int g = group[*mem.begin()];
        for (auto v : mem) {
            if (group[v] != g) {
                good = false;
                break;
            }
        }
        if (!good) break;

        for (auto v : mem) {
            group[v] = gc;
        }
        gc++;
    }

    if (good) {
        set<int> final_groups;
        for (int i = 1; i <= n; i++) {
            final_groups.insert(group[i]);
        }
        // The number of final partitions must equal 1 (for the root) + the number of unique zones.
        if (final_groups.size() != unique_mems_count + 1) {
            good = false;
        }
    }

    cout << (good ? 1 : 0) << endl;

    return 0;
}