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

		vector<string> s(n);
		arrput(s);

		if (n == 1) {
			print("YES");
			continue;
		}

		int x = 0;
		rep(i, 0, n) {
			x += count(s[i].begin(), s[i].end(), '#');
		}

		int c = 0;
		rep(i, 1, n) {
			rep(j, 1, n) {
				c += (s[i][j] == '#') and (s[i - 1][j] == '#') and
					(s[i][j - 1] == '#') and (s[i - 1][j - 1] == '#');
			}
		}

		if (c == 1 and x == 4) {
			print("YES");
			continue;
		}

		int u = -1e9, v = 1e9;
		rep(i, 0ll, n) {
			rep(j, 0ll, n) {
				if (s[i][j] == '#') {
					u = max(u, i + j);
					v = min(v, i + j);
				}
			}
		}

		if (u - v <= 1) {
			print("YES");
			continue;
		}

		u = -1e9, v = 1e9;
		rep(i, 0ll, n) {
			rep(j, 0ll, n) {
				if (s[i][j] == '#') {
					u = max(u, i - j);
					v = min(v, i - j);
				}
			}
		}

		if (u - v <= 1) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
