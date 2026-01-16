#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Binary Indexed Tree (Fenwick Tree)
struct BIT {
    vector<long long> tree;
    int n;

    BIT(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    // Gets the sum of [l, r] (1-based)
    long long query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

long long solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; // p[i] is 1-based
    }

    // 1. Calculate initial inversion count
    long long inv_count = 0;
    BIT bit_inv(n);
    for (int i = 0; i < n; ++i) {
        inv_count += bit_inv.query(p[i] + 1, n);
        bit_inv.update(p[i], 1);
    }

    // 2. Calculate L_k (inversions to the left)
    vector<long long> L(n);
    BIT bit_left(n);
    for (int k = 0; k < n; ++k) {
        L[k] = bit_left.query(p[k] + 1, n);
        bit_left.update(p[k], 1);
    }

    // 3. Calculate R_k (non-inversions to the right)
    vector<long long> R(n);
    BIT bit_right(n);
    for (int k = n - 1; k >= 0; --k) {
        // [p_k < p_j] is a non-inversion
        // We query for elements GREATER than p_k
        R[k] = bit_right.query(p[k] + 1, n); 
        bit_right.update(p[k], 1);
    }

    // 4. Calculate final minimum cost
    long long min_cost = inv_count;
    for (int k = 0; k < n; ++k) {
        long long coeff = R[k] - L[k];
        min_cost += min(0LL, coeff);
    }

    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}