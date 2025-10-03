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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrput(a);

		vector<int> b(n + 1), c(n + 1);
		rep(i, 0, n) {
			b[i + 1] = b[i];
			c[i + 1] = c[i];
			if (__builtin_popcount(a[i]) - 1 - (a[i] & 1) > 0) {
				b[i + 1]++;
			}
			else if (a[i] & 1) {
				c[i + 1]++;
			}
			while (a[i] > 1) {
				a[i] /= 2;
				b[i + 1]++;
			}
		}

		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;

			print(b[r + 1] - b[l] + (c[r + 1] - c[l]) / 2);
		}
	}
}
