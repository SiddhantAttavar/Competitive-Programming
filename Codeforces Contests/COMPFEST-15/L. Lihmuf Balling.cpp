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

	int n, m;
	input(n, m);

	pair<int, int> res = {0, -1};
	rep(k, 2, m + 1) {
		set<int> s;
		int c = 0, y = 0, l = (k - 1) % n;
		while (!s.count(l) and c < n) {
			s.insert(l);
			int z = (n - l - 1) / k + 1;
			int w = c < l ? 0 : (c - l) / (k - 1) + 1;
			y += z * (2 * (l + 1) + (z - 1) * k) / 2;
			y -= w * (2 * (l + 1) + (w - 1) * k) / 2;
			c += z;
			l = (l + z * k) % n;
		}
		res = max(res, {y, -k});
	}
	print(-res.second);
}
