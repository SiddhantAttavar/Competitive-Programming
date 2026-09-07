#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2015-02-18
 * License: CC0
 * Source: marian's (TC) code
 * Description: Aho-Corasick automaton, used for multiple pattern matching.
 * Initialize with AhoCorasick ac(patterns); the automaton start node will be at index 0.
 * find(word) returns for each position the index of the longest word that ends there, or -1 if none.
 * findAll($-$, word) finds all words (up to $N \sqrt N$ many if no duplicate patterns)
 * that start at each position (shortest first).
 * Duplicate patterns are allowed; empty patterns are not.
 * To find the longest words that start at each position, reverse all input.
 * For large alphabets, split each symbol into chunks, with sentinel bits for symbol boundaries.
 * Time: construction takes $O(26N)$, where $N =$ sum of length of patterns.
 * find(x) is $O(N)$, where N = length of x. findAll is $O(NM)$.
 * Status: stress-tested
 */
// #pragma once

const int N = 1e6;
const int alpha = 26, first = 'a'; // change this!

ll f[N];
string a[N];
int x[N];
ll g[N];
int backp[N];

struct Node {
	// (nmatches is optional)
	int back, next[alpha], start = -1, end = -1;
	Node(int v) { memset(next, v, sizeof(next)); }
	Node() {}
};

Node nodes[N];
int (*tree)[26] = (int(*)[26]) ((void *) nodes);

struct AhoCorasick {
	int z = 0;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = nodes[n].next[c - first];
			if (m == -1) { n = m = z; nodes[z++] = Node(-1); }
			else n = m;
		}
		if (nodes[n].end == -1) nodes[n].start = j;
		backp[j] = nodes[n].end;
		// backp.push_back(nodes[n].end);
		nodes[n].end = j;
		// nodes[n].nmatches++;
	}
	AhoCorasick(string pat[], int n) {
		nodes[z++] = Node(-1);
		rep(i,0,n) insert(pat[i], i);
		nodes[0].back = z;
		nodes[z++] = Node(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = nodes[n].back;
			rep(i,0,alpha) {
				int &ed = nodes[n].next[i], y = nodes[prev].next[i];
				if (ed == -1) ed = y;
				else {
					nodes[ed].back = y;
					(nodes[ed].end == -1 ? nodes[ed].end : backp[nodes[ed].start])
						= nodes[y].end;
					// nodes[ed].nmatches += nodes[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string &word) {
		int n = 0;
		vi res; // ll count = 0;
		for (char c : word) {
			n = nodes[n].next[c - first];
			res.push_back(nodes[n].end);
			// count += nodes[n].nmatches;
		}
		return res;
	}
	vector<vi> findAll(vector<string>& pat, string &word) {
		vi r = find(word);
		vector<vi> res(sz(word));
		rep(i,0,sz(word)) {
			int ind = r[i];
			while (ind != -1) {
				res[i - sz(pat[ind]) + 1].push_back(ind);
				ind = backp[ind];
			}
		}
		return res;
	}
};

int ins(string &s, int tree[][26], ll f[], int &z) {
	int u = 0;
	for (char c : s) {
		if (tree[u][c - 'a'] == -1) {
			tree[u][c - 'a'] = ++z;
			fill(tree[z], tree[z] + 26, -1);
			f[z] = 0;
		}
		u = tree[u][c - 'a'];
	}
	return u;
}

void dfs(int u, int tree[][26], ll f[]) {
	rep(i, 0, 26) {
		if (tree[u][i] != -1) {
			f[tree[u][i]] += f[u];
			dfs(tree[u][i], tree, f);
		}
	}
}

void get(string a[], int x[], ll g[], int n) {
	rep(i, 0, n) {
		reverse(all(a[i]));
	}
	
	fill(tree[0], tree[0] + 26, -1);
	f[0] = 0;
	
	int b[n];
	int z = 0;
	rep(i, 0, n) {
		b[i] = ins(a[i], tree, f, z);
		f[b[i]] += x[i];
	}
	dfs(0, tree, f);
	
	rep(i, 0, n) {
		reverse(all(a[i]));
	}
	rep(i, 0, n) {
		g[i] = f[b[i]];
	}
}

void solve() {
    int n, m;
	cin >> n >> m;

	rep(i, 0, n) {
		cin >> a[i] >> x[i];
	}
	rep(i, n, n + m) {
		cin >> a[i] >> x[i];
		x[i] = -x[i];
	}

	get(a, x, g, n + m);
	AhoCorasick s(a, n + m);

	int q;
	cin >> q;
	while (q--) {
		string t;
		cin >> t;

		ll res = 0;
		for (int j : s.find(t)) {
			if (j != -1) {
				res += g[j];
			}
		}
		
		if (res > 0) {
			cout << 1 << endl;
		}
		else if (res < 0) {
			cout << 2 << endl;
		}
		else {
			cout << "tie" << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
