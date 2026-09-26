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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */
// #pragma once

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void dfs1(int u, vector<vi> &graph, vi &p) {
	for (int v : graph[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs1(v, graph, p);
		}
	}
}

void dfs2(int u, vector<vi> &graph, vi &vis, set<pii> &s) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v] and !s.count({u, v}) and !s.count({v, u})) {
			dfs2(v, graph, vis, s);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<pii> e;
		vector<vi> graph(n);
		UF d(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			
			u--;
			v--;

			if (d.join(u, v)) {
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
			else {
				e.push_back({u, v});
			}
		}

		vi p(n, -1);
		dfs1(0, graph, p);

		for (auto [u, v] : e) {
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool flag = false;
		rep(i, 1, 1 << sz(e)) {
			set<pii> s;
			rep(j, 0, sz(e)) {
				auto [u, v] = e[j];
				if (!(i >> j & 1)) {
					continue;
				}

				s.insert({u, v});
				while (u) {
					if (s.count({u, p[u]})) {
						s.erase({u, p[u]});
					}
					else {
						s.insert({u, p[u]});
					}
					u = p[u];
				}
				while (v) {
					if (s.count({v, p[v]})) {
						s.erase({v, p[v]});
					}
					else {
						s.insert({v, p[v]});
					}
					v = p[v];
				}
			}

			vi vis(n, false);
			dfs2(0, graph, vis, s);
			if (accumulate(all(vis), 0ll) == n) {
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
