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

bool check(int a, int b, int x, int y) {
	if (abs(b - y) > 30) {
		return b < y;
	}
	int t = min(b, y);
	return (a << (b - t)) <= (x << (y - t));
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> b(n, 0);
		rep(i, 1, n) {
			int l = 0, r = 30 * n + 1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (check(a[i - 1], b[i - 1], a[i], m)) {
					b[i] = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
		}
		print(accumulate(b.begin(), b.end(), 0ll));
	}
}
