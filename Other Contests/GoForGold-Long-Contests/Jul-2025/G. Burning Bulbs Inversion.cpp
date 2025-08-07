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
		int n, k;
		input(n, k);

		vector<int> p(k);
		arrput(p);

		vector<int> v(50, false);
		for (int i : p) {
			v[i - 1] = !v[i - 1];
		}
		
		p.clear();
		rep(i, 0, 50) {
			if (v[i]) {
				p.push_back(i + 1);
			}
		}

		int res = 0;
		rep(i, 1, 1 << p.size()) {
			int x = 1;
			rep(j, 0, p.size()) {
				if (i & (1 << j)) {
					x = x * p[j] / __gcd(x, p[j]);
				}
			}

			if (__builtin_popcount(i) % 2) {
				res += (n / x) * (__builtin_popcount(i) + 1);
			}
			else {
				res -= (n / x) * (__builtin_popcount(i) + 1);
			}
		}
		print(res);
	}
}
