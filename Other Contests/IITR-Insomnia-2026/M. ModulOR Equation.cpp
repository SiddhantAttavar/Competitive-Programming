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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int solve(int a, int n, bool keep = false) {
	if (a == 0) {
		return 1;
	}

	int i = 63 - __builtin_clzll(a);
	if ((1ll << i) > n) {
		if (keep) {
			return 0;
		}
		return solve(a ^ (1ll << i), n);
	}

	int x = 0, y = 0;;
	rep(j, 0, i + 1) {
		if (a >> j & 1) {
			x++;
			y |= 1ll << j;
		}
	}
	if (y <= n) {
		if (keep) {
			return 1ll << (x - 1);
		}
		return 1ll << x;
	}

	if (keep) {
		return solve(a ^ (1ll << i), n ^ (1ll << i));
	}
	return (1ll << (x - 1)) + solve(a ^ (1ll << i), n ^ (1ll << i));
}

void brute(int n) {
	rep(a, 1, n + 1) {
		int c = 0;
		rep(b, 1, a + 1) {
			if ((a % b + b % a) == (a | b)) {
				c++;
				print(a, b);
			}
		}
		// print(a, c);
		// assert(c == (1ll << (__builtin_popcountll(a) - 1)) - 1);
	}
}

int32_t main() {
	// brute(1023);
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		if (n > m) {
			swap(n, m);
		}

		int res = 0;
		rep(a, 1, n + 1) {
			res += solve(a, m, true) - (a <= m);
		}
		rep(b, 1, m + 1) {
			res += solve(b, n, true) - (b <= n);
		}
		print(res);
	}
}
