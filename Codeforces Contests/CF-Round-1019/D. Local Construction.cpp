#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &l) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis, l);
		}
	}
	l.push_back(u);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int u = -1;
		int x = *max_element(a.begin(), a.end());
		rep(i, 0, n) {
			if (a[i] == -1) {
				a[i] = x + 1;
				u = i;
			}
		}

		stack<int> s;
		vector<int> p(n, -1), q(n, -1);
		rep(i, 0, n) {
			while (!s.empty() and a[s.top()] < a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				p[i] = s.top();
			}
			s.push(i);
		}

		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[s.top()] < a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				q[i] = s.top();
			}
			s.push(i);
		}

		vector<vector<int>> graph(n);
		rep(i, 0, n) {
			if (p[i] != -1) {
				if (a[i] == a[p[i]]) {
					if ((i < u) ^ (a[i] % 2 == 0)) {
						graph[i].push_back(p[i]);
					}
					else {
						graph[p[i]].push_back(i);
					}
				}
				else if (a[i] % 2 == 1) {
					graph[p[i]].push_back(i);
				}
				else {
					graph[i].push_back(p[i]);
				}
			}
			if (q[i] != -1) {
				if (a[i] == a[q[i]]) {
					if ((i < u) ^ (a[i] % 2 == 0)) {
						graph[q[i]].push_back(i);
					}
					else {
						graph[i].push_back(q[i]);
					}
				}
				else if (a[i] % 2 == 1) {
					graph[q[i]].push_back(i);
				}
				else {
					graph[i].push_back(q[i]);
				}
			}
		}

		vector<bool> vis(n, false);
		vector<int> l;
		rep(i, 0, n) {
			if (!vis[i]) {
				dfs(i, graph, vis, l);
			}
		}
		reverse(l.begin(), l.end());

		vector<int> res(n);
		rep(i, 0, n) {
			res[l[i]] = i + 1;
		}
		arrprint(res);
	}
}
