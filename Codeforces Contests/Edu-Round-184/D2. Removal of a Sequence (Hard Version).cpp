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
		int x, y, k;
		input(x, y, k);

		y--;
		if (y == 0) {
			print(-1);
			continue;
		}

		if (k - 1 < y) {
			print(k);
			continue;
		}

		while (x and k <= 1e12) {
			int a = (k - 1) / y;
			int p = y - (k - 1) % y;
			int t = min(x, (p + a - 1) / a);
			x -= t;
			k += t * a;
		}

		if (k > 1e12) {
			print(-1);
		}
		else {
			print(k);
		}
	}
}
