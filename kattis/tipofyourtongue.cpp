#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

struct TrieNode {
    int cnt = 0;
    int next[26] = {0};
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // shift+combine to avoid simple XOR issues
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};

vector<TrieNode> pre(1), suf(1);
unordered_map<pair<int,int>, int, pair_hash> aand;

int main() {
    int n, q; cin >> n >> q;
    for (int i=0;i<n;i++) {
        string s; cin>>s;
        // update pre and suf at the same time, at each pair (i,j) add to aand
        int curpre = 0, cursuf = 0;
        for (int j=0;j<(int)s.size();j++) {
            int cpre = s[j]-'a';
            if (!pre[curpre].next[cpre]) {
                pre[curpre].next[cpre] = pre.size();
                pre.emplace_back();
            }
            curpre = pre[curpre].next[cpre];
            pre[curpre].cnt++;

            int csuf = s[(int)s.size()-1-j]-'a';
            if (!suf[cursuf].next[csuf]) {
                suf[cursuf].next[csuf] = suf.size();
                suf.emplace_back();
            }
            cursuf = suf[cursuf].next[csuf];
            suf[cursuf].cnt++;

            aand[{curpre, cursuf}]++;
        }
    }

    for (int i=0;i<q;i++) {
        string type, p, s; cin >> type >> p >> s;
        int curpre = 0, cursuf = 0;
        for (auto c : p) {
            int cpre = c-'a';
            if (!pre[curpre].next[cpre]) {
                curpre = -1;
                break;
            }
            curpre = pre[curpre].next[cpre];
        }
        reverse(s.begin(), s.end());
        for (auto c : s) {
            int csuf = c-'a';
            if (!suf[cursuf].next[csuf]) {
                cursuf = -1;
                break;
            }
            cursuf = suf[cursuf].next[csuf];
        }
        if (type == "OR") {
            if (curpre == -1 && cursuf == -1) {
                cout << 0 << endl;
            } else if (curpre == -1) {
                cout << suf[cursuf].cnt << endl;
            } else if (cursuf == -1) {
                cout << pre[curpre].cnt << endl;
            } else {
                cout << pre[curpre].cnt + suf[cursuf].cnt - aand[{curpre, cursuf}] << endl;
            }
        } else if (type == "AND") {
            if (curpre == -1 || cursuf == -1) {
                cout << 0 << endl;
            } else {
                cout << aand[{curpre, cursuf}] << endl;
            }
        } else if (type == "XOR") {
            if (curpre == -1 && cursuf == -1) {
                cout << 0 << endl;
            } else if (curpre == -1) {
                cout << suf[cursuf].cnt << endl;
            } else if (cursuf == -1) {
                cout << pre[curpre].cnt << endl;
            } else {
                cout << pre[curpre].cnt + suf[cursuf].cnt - 2*aand[{curpre, cursuf}] << endl;
            }
        }
    }
    return 0;
}