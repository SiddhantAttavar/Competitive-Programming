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

int brute(int l, int r) {
	int res = 0;
	rep(x, 1, 4 * r + 1) {
		int a = 1e18, b = -1e18;
		rep(i, l, r + 1) {
			a = min(a, i ^ x);
			b = max(b, i ^ x);
		}
		res += a == l and b == r;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int l, r;
		input(l, r);

		int res = 0;
		rep(i, 0, 60) {
			int k = 1ll << (i + 1);
			res += l % k == 0 and r % k == k - 1;
		}
		int k = (l ^ r) + 1;
		if (__builtin_popcountll(k) == 1) {
			res += l % k and k - l % k == r % k + 1;
		}
		print((1ll << res) - 1);
	}
}
