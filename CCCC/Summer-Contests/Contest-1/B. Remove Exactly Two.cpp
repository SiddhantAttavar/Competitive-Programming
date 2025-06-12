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

		vector<set<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].insert(v - 1);
			graph[v - 1].insert(u - 1);
		}

		vector<pair<int, int>> v(n);
		rep(i, 0, n) {
			v[i] = {graph[i].size(), i};
		}
		sort(v.begin(), v.end());

		int x = v[n - 1].first, y = v[n - 2].first;
		if (x != y) {
			bool flag = false;
			rep(i, 0, n) {
				if (v[i].first == y and !graph[v[n - 1].second].count(v[i].second)) {
					flag = true;
					break;
				}
			}
			print(x + y + flag - 2);
			continue;
		}

		int k = 0;
		rep(i, 0, n) {
			k += graph[i].size() == x;
		}
		int res = k * (k - 1) / 2;
		rep(i, 0, n) {
			for (int j : graph[i]) {
				res -= i < j and graph[i].size() == x and graph[j].size() == x;
			}
		}
		print(2 * x + (res > 0) - 2);
	}
}
