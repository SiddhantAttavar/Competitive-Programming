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

int32_t main() {
	setup();

	int k, n, m;
	input(n, m, k);

	vector<int> a(k);
	arrput(a);

	vector<vector<int>> graph(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> d(n, -1);
	queue<int> q;
	set<int> s;
	vector<int> p(n, -1);
	for (int i : a) {
		d[i - 1] = 0;
		p[i - 1] = i - 1;
		s.insert(i - 1);
		q.push(i - 1);
	}
	vector<int> res(n, 1e18);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				res[v] = d[v];
				p[v] = p[u];
				q.push(v);
			}
			else if (p[u] != p[v] and p[v] != -1) {
				res[p[u]] = min(res[p[u]], d[u] + d[v] + 1);
				res[p[v]] = min(res[p[v]], d[u] + d[v] + 1);
			}
		}
	}
	rep(i, 0, n) {
		if (res[i] == 1e18) {
			res[i] = -1;
		}
	}
	arrprint(res);
}
