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

		vector<int> a(n);
		arrput(a);

		int x = accumulate(a.begin(), a.end(), 0ll);
		int k = *max_element(a.begin(), a.end());

		if (x % 2 or 2 * k > x) {
			print(-1);
			continue;
		}

		int c = a[0], l = 0;
		while (2 * c < x) {
			l++;
			c += a[l];
		}

		if (2 * c == x) {
			print(1);
			arrprint(a);
			continue;
		}

		c -= a[l];
		int w = x / 2 - a[l];
		vector<int> b(n);
		rep(i, 0, l) {
			b[i] = a[i];
		}
		b[l] = c - w;
		rep(i, l + 1, n) {
			b[i] = min(a[i], w);
			w -= b[i];
		}
		rep(i, 0, n) {
			a[i] -= b[i];
		}

		print(2);
		arrprint(b);
		arrprint(a);
	}
}
