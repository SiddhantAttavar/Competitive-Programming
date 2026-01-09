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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	int res = 1e18;
	rep(i, 0, n) {
		vector<int> d(n, -1), p(n, -1);
		d[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					p[v] = u;
					q.push(v);
				}
				else if (v != p[u]) {
					res = min(res, d[u] + d[v] + 1);
				}
			}
		}
	}

	if (res == 1e18) {
		print(-1);
	}
	else {
		print(res);
	}
}
