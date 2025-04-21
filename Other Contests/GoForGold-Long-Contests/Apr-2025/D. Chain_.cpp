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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n == 1) {
			print("Yes");
			continue;
		}

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		bool flag = true;
		rep(i, 0, n) {
			if (graph[i].empty() or graph[i].size() > 2) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print("No");
			continue;
		}

		int u = 0;
		while (u < n and graph[u].size() != 1) {
			u++;
		}

		if (u == n) {
			print("No");
			continue;
		}

		vector<bool> b(n, false);
		b[u] = true;
		rep(i, 0, n - 1) {
			vector<int> l;
			for (int v : graph[u]) {
				if (!b[v]) {
					l.push_back(v);
				}
			}
			if (i != n - 2 and l.size() != 1) {
				flag = false;
				break;
			}
			u = l[0];
			b[u] = true;
		}

		if (!flag) {
			print("No");
		}
		else {
			print("Yes");
		}
	}
}
