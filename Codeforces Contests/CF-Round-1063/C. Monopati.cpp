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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> a(2, vector<int>(n));
		arrput(a[0]);
		arrput(a[1]);

		vector<vector<int>> v(2 * n + 1), w(2 * n + 1);
		rep(i, 0, n) {
			v[a[0][i]].push_back(i);
			w[a[1][i]].push_back(i);
		}

		int x = 0, y = n - 1;
		int l = 0;
		set<int> c, d;
		int res = 0;
		bool flag = false;
		rep(r, 1, 2 * n + 1) {
			for (int j : v[r]) {
				c.insert(j);
				while (c.count(x)) {
					x++;
				}
			}
			for (int j : w[r]) {
				d.insert(j);
				while (d.count(y)) {
					y--;
				}
			}
			if (x - 1 >= y + 1) {
				flag = true;
			}
			while (x - 1 >= y + 1) {
				for (int j : v[l]) {
					c.erase(j);
					x = min(x, j);
				}
				for (int j : w[l]) {
					d.erase(j);
					y = max(y, j);
				}
				l++;
			}
			if (flag) {
				res += l - 1;
			}
		}
		print(res);
	}
}
