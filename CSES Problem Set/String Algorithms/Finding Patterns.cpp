#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

struct AhoCorasick {
	enum {alpha = 26, first = 'a'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string word) {
		int n = 0;
		vi res; // ll count = 0;
		for (char c : word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			// count += N[n].nmatches;
		}
		return res;
	}
	vector<vi> findAll(vector<string>& pat, string word) {
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

void dfs1(int u, int c, vector<vi> &tree, vi &l, vector<vi> &graph) {
	if (l[u] != -1) {
		if (c != -1) {
			graph[l[u]].push_back(c);
		}
		c = l[u];
	}
	rep(i, 0, 26) {
		if (tree[u][i] != -1) {
			dfs1(tree[u][i], c, tree, l, graph);
		}
	}
}

void dfs2(int u, vector<vi> &graph, vi &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs2(v, graph, vis);
		}
	}
}

int32_t main() {
	setup();

	string s;
	input(s);

	int n;
	input(n);
	vector<string> v(n);
	arrput(v);

	vector<vi> graph(n);
	vector<vi> tree = {vi(26, -1)};
	vi l = {-1};
	rep(i, 0, n) {
		int u = 0;
		reverse(all(v[i]));
		for (char c : v[i]) {
			if (tree[u][c - 'a'] == -1) {
				tree[u][c - 'a'] = sz(tree);
				tree.push_back(vi(26, -1));
				l.push_back(-1);
			}
			u = tree[u][c - 'a'];
		}
		reverse(all(v[i]));
		if (l[u] != -1) {
			graph[i].push_back(l[u]);
		}
		l[u] = i;
	}

	dfs1(0, -1, tree, l, graph);

	vi vis(n, false);
	AhoCorasick a(v);
	vi z = a.find(s);
	rep(i, 0, sz(s)) {
		if (z[i] != -1 and !vis[z[i]]) {
			dfs2(z[i], graph, vis);
		}
	}
	rep(i, 0, n) {
		if (vis[i]) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
