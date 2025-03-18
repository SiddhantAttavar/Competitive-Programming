#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

struct SegTree {
	vector<pair<vector<int>, vector<int>>> a;

	SegTree(int n, vector<pair<int, int>> &p) {
		a = vector<pair<vector<int>, vector<int>>>(4 * n);
		build(0, n - 1, 0, p);
	}

	pair<vector<int>, vector<int>> combine(pair<vector<int>, vector<int>> &a, pair<vector<int>, vector<int>> &b) {
		pair<vector<int>, vector<int>> res = {vector<int>(a.first.size() + b.first.size()), vector<int>(a.second.size() + b.second.size())};
		merge(a.first.begin(), a.first.end(), b.first.begin(), b.first.end(), res.first.begin());
		merge(a.second.begin(), a.second.end(), b.second.begin(), b.second.end(), res.second.begin());
		return res;
	}

	void build(int s, int e, int curr, vector<pair<int, int>> &p) {
		if (s == e) {
			a[curr].first.push_back(p[s].first);
			a[curr].second.push_back(p[s].second);
			// a[curr] = {{p[s].second}, {p[s].second}};
			return;
		}

		int mid = (s + e) / 2;
		build(s, mid, 2 * curr + 1, p);
		build(mid + 1, e, 2 * curr + 2, p);
		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
	}

	int answer(pair<vector<int>, vector<int>> &v, int k) {
		// for (pair<int, int> p : v.first) {
		// 	cout << p.first << ' ';
		// }
		// cout << endl;
		// print(v.first.order_of_key(make_pair(k, 1e9)), v.second.order_of_key(make_pair(k, -1)));
		int x = upper_bound(v.first.begin(), v.first.end(), k) - v.first.begin();
		int y = lower_bound(v.second.begin(), v.second.end(), k) - v.second.begin();
		return x - y;
	}

	int query(int l, int r, int s, int e, int u, int k) {
		if (l > e || r < s) {
			return 0;
		}

		if (l <= s && r >= e) {
			return answer(a[u], k);
		}

		int mid = (s + e) / 2;
		return (
			query(l, r, s, mid, 2 * u + 1, k) +
			query(l, r, mid + 1, e, 2 * u + 2, k)
		);
	}

	void modify(pair<vector<int>, vector<int>> &a, char c, int d, int i, vector<pair<int, int>> &p) {
		// print(c, d, i);
		// cout.flush();
		// for (pair<int, int> p : a.first) {
		// 	cout << p.first << ' ';
		// }
		// cout << endl;
		// cout.flush();
		if (c == 'a') {
			if (d == 1) {
				int j = upper_bound(a.first.begin(), a.first.end(), p[i].first) - a.first.begin() - 1;
				a.first[j]++;
			}
			else {
				int j = lower_bound(a.first.begin(), a.first.end(), p[i].first) - a.first.begin();
				a.first[j]--;
			}
		}
		else {
			if (d == 1) {
				int j = upper_bound(a.second.begin(), a.second.end(), p[i].second) - a.second.begin() - 1;
				a.second[j]++;
			}
			else {
				int j = lower_bound(a.second.begin(), a.second.end(), p[i].second) - a.second.begin();
				a.second[j]--;
			}
		}
	}

	void update(int u, int s, int e, int i, char c, int d, vector<pair<int, int>> &p) {
		if (e < i or s > i) {
			return;
		}

		modify(a[u], c, d, i, p);
		if (s == e) {
			return;
		}

		int m = (s + e) / 2;
		update(2 * u + 1, s, m, i, c, d, p);
		update(2 * u + 2, m + 1, e, i, c, d, p);
	}
};

void dfs(int u, int w, vector<vector<int>> &graph, vector<int> &l, vector<int> &p, vector<int> &q) {
	l.push_back(u);
	p[u] = l.size() - 1;
	for (int v : graph[u]) {
		if (v != w) {
			dfs(v, u, graph, l, p, q);
		}
	}
	q[u] = l.size() - 1;
}

int32_t main() {
	setup();
	int n;
	input(n);

	vector<int> a(n), b(n);
	arrput(a);
	arrput(b);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> l;
	vector<int> p(n), q(n);
	dfs(0, -1, graph, l, p, q);

	vector<int> k(n);
	rep(i, 0, n) {
		k[l[i]] = i;
	}

	vector<pair<int, int>> w(n);
	rep(i, 0, n) {
		w[i] = {a[l[i]], b[l[i]]};
	}
	SegTree s(n, w);

	int m;
	input(m);
	while (m--) {
		int o, u;
		input(o, u);

		u--;
		if (o == 1) {
			int d;
			char c;
			input(c, d);
			s.update(0, 0, n - 1, k[u], c, d, w);
			if (c == 'a') {
				w[k[u]].first += d;
			}
			else {
				w[k[u]].second += d;
			}
		}
		else {
			int x;
			input(x);
			print(s.query(p[u], q[u], 0, n - 1, 0, x));
		}
	}
}
