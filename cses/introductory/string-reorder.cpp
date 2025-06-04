#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    int freq[26] = {0};
    for (char c : s) freq[c - 'A']++;
    if (*max_element(freq, freq + 26) > (s.length() + 1) / 2) {
        cout << "-1";
        return 0;
    }
    int l = s.length();
    char last = -1;
    while (true) {
        char add = -1;
        for (int i = 0; i < 26; i++) {
            if ((l&1) && freq[i] > (l-1)/2) {
                add = i;
                break;
            } else if (freq[i] && (last != i) && (add == -1)) {
                add = i;
            }
        }
        if (add == -1) break;
        cout << (char)(add + 'A');
        freq[add]--; l--;
        last = add;
    }
    return 0;
}