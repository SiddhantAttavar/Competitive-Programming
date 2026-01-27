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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int brute(int n, int k, int x = 0, int l = 0, int s = 0) {
	if (k == 1) {
		x ^= n;
		if (x > n) {
			return 0;
		}
		return x + s;
	}

	int res = 0;
	rep(i, l, n + 1) {
		res = max(res, brute(n, k - 1, x ^ i, i, s + i));
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi res(k, n);
		if (k % 2) {
			arrprint(res);
			continue;
		}

		int u = 63 - __builtin_clzll(n);
		res[0] ^= 1ll << u;
		int l = 1;
		for (int i = u - 1; i >= 0; i--) {
			if (n >> i & 1) {
				if (l < k) {
					res[l] ^= 1ll << i;
					l++;
				}
				else {
					res[0] ^= 1ll << i;
				}
			}
			else {
				rep(j, 0, l - (l % 2)) {
					res[j] ^= 1ll << i;
				}
			}
		}
		arrprint(res);
		cout.flush();
		// assert(accumulate(all(res), 0ll) == brute(n, k));
	}
}
