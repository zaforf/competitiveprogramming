#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* next[26];
	long long num;
	Node() {
		for (int i=0;i<26;i++) next[i] = nullptr;
		num = 0;
	}
};

void insert(string s, Node* root) {
	int n = s.size();
	Node* p = root;
	for (int i=0;i<n;i++) {
		if (p->next[s[i]-'a'] == NULL) {
			p->next[s[i]-'a'] = new Node();
		}
		p = p->next[s[i]-'a'];
		p->num++;
	}
}

long long cnt(string s, Node* root) {
	long long res = 0;
	int n = s.size();
	Node* p = root;
	for (int i=0;i<n;i++) {
		if (p->next[s[i]-'a'] == NULL) {
			p->next[s[i]-'a'] = new Node();
		}
		p = p->next[s[i]-'a'];
		res += p->num;
	}
	return res;
}

int main() {
	int n; cin >> n;
	vector<string> a(n);
	Node* root = new Node();
	int nodes = 1;
	for (string& s : a) cin >> s;
	for (int i=0;i<n;i++) {
		string rev = a[i];
		reverse(rev.begin(), rev.end());
		insert(rev, root);
	}
	long long ans = 0;
	for (string s : a) {
		ans += (long long) s.size() * n;
		ans -= cnt(s, root);
	}
	cout << 2*ans;
	return 0;
}