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

int query1(vector<int> v) {
	cout << "? 1 " << v.size() << ' ';
	for (int i : v) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
	cout.flush();
	int x;
	input(x);
	return x;
}

void query2(int i) {
	print("? 2", i + 1);
	cout.flush();
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		int x = query1({0});
		if (x == -1 or x == 1) {
			vector<int> res(n);
			res[0] = x;
			rep(i, 1, n) {
				res[i] = query1({i}) - x;
			}
			cout << "! ";
			arrprint(res);
			cout.flush();
			continue;
		}

		query2(0);
		int y = query1({0});
		vector<int> res(n);
		res[0] = y < x ? -1 : 1;
		if (res[0] == -1) {
			query2(0);
			res[0] = 1;
		}

		int l = 1, r = n - 1, u = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			vector<int> v;
			rep(i, 1, m + 1) {
				v.push_back(i);
			}
			int s = query1(v);
			query2(0);
			int t = query1(v);
			query2(0);
			if (s - t != 2 * v.size()) {
				u = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		res[u] = query1({u});
		rep(i, 1, n) {
			if (i != u) {
				res[i] = query1({i}) - 1 - res[u];
			}
		}

		cout << "! ";
		arrprint(res);
	}
}
