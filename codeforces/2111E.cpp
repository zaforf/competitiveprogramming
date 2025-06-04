#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;

		array<array<pair<int, set<int>>, 3>, 3> to;  // to[x][y] = {count, set of query indices}
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				to[i][j] = {0, {}};

		for (int i = 0; i < q; ++i) {
			char x, y;
			cin >> x >> y;
			int xi = x - 'a';
			int yi = y - 'a';
			if (xi == yi) continue;
			to[xi][yi].first++;
			to[xi][yi].second.insert(i);
		}

		array<array<int, 3>, 3> used = {};

		for (int idx = 0; idx < n; ++idx) {
			int c = s[idx] - 'a';
			for (int j = 0; j < 3; ++j) {
				if (j >= c) continue;

				int other = 3 - c - j;

				// direct replacement
				if (to[c][j].first > 0) {
					to[c][j].first--;
					used[c][j]++;
					s[idx] = j + 'a';
					break;
				}
				// two-step replacement
				else {
					if ((int)to[c][other].second.size() > used[c][other] &&
						(int)to[other][j].second.size() > used[other][j]) {

						auto& set1 = to[c][other].second;
						auto& set2 = to[other][j].second;

						int right = *set2.rbegin();  // max in set2
						auto it = set1.lower_bound(right); // first >= right

						if (it != set1.begin()) {
							--it;
							int left_val = *it;

							set1.erase(it);
							set2.erase(right);

							to[c][other].first--;
							to[other][j].first--;

							s[idx] = j + 'a';
							break;
						}
					}
				}
			}
		}
		cout << s << '\n';
	}
	return 0;
}
