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

		string s;
		input(s);

		vector<int> f(n, 0), g(n, 0), h(n, 0);
		f[0] = 0;
		h[0] = s[0] == '1';
		g[0] = (s[0] == '0') * (n - 1);
		rep(i, 1, n) {
			if (s[i] == '1') {
				f[i] = 0;
				g[i] = 0;
				h[i] = 1 + g[i - 1];
			}
			else {
				f[i] = i + max(f[i - 1], h[i - 1]);
				g[i] = n - i - 1 + g[i - 1];
				h[i] = 0;
			}
		}

		print(max({
			*max_element(f.begin(), f.end()),
			*max_element(g.begin(), g.end()),
			*max_element(h.begin(), h.end())
		}));
	}
}
