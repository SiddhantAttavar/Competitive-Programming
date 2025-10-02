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

	int l, r;
	input(l, r);

	int x = 3;
	while (x * x * x * (x - 2) < l) {
		x++;
	}
	x--;

	l -= x * x * x * (x - 2);
	r -= x * x * x * (x - 2);
	x++;
	int a = 1, b = 1, c = 1, n = 3;
	int k = x * x * (x - 2) - (x - 1) * (x - 1) * (x - 3);
	while (a < x and l > k) {
		l -= k;
		r -= k;
		a++;
	}
	k = a == x ? x * (x - 2) : x * (x - 2) - (x - 1) * (x - 3);
	while (b < x and l > k) {
		l -= k;
		r -= k;
		b++;
	}
	k = a == x or b == x ? x - 2 : 1;
	while (c < x and l > k) {
		l -= k;
		r -= k;
		c++;
	}
	k = a == x or b == x or c == x;
	while (n < x and l > k) {
		l -= k;
		r -= k;
		n++;
	}
	rep(i, 0, r) {
		bool res = max(a, b) >= c or pow(a * 1.0 / c, n) + pow(b * 1.0 / c, n) > 1;
		printf("%lld^%lld+%lld^%lld%c%lld^%lld\n", a, n, b, n, "<>"[res], c, n);

		int z = max({a, b, c, n});
		if (n < z) {
			n++;
		}
		else if (c < z) {
			c++;
			n = a == z or b == z or c == z ? 3 : z;
		}
		else if (b < z) {
			b++;
			c = 1;
			n = a == z or b == z ? 3 : z;
		}
		else if (a < z) {
			a++;
			b = 1;
			c = 1;
			n = a == z ? 3 : z;
		}
		else {
			a = 1;
			b = 1;
			c = 1;
			n++;
		}
	}
}
