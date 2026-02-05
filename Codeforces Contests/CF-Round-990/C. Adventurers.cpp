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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int check(ordered_set &a, ordered_set &b, int k) {
	int l1 = a.find_by_order(k - 1)->first, r1 = a.find_by_order(sz(a) - k)->first;
	int l2 = b.find_by_order(k - 1)->first, r2 = b.find_by_order(sz(b) - k)->first;
	if (max(l1, l2) < min(r1, r2)) {
		return min(r1, r2);
	}
	return 1e18;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi x(n), y(n);
		rep(i, 0, n) {
			input(x[i], y[i]);
		}

		map<int, vector<pii>> m;
		ordered_set a, b;
		rep(i, 0, n) {
			m[x[i]].push_back({y[i], i});
			b.insert({y[i], i});
		}
		ordered_set c = b;

		array<int, 3> res = {0, 0, 0};
		for (auto &[x, v] : m) {
			int l = res[0] + 1, r = min(sz(a) / 2, sz(b) / 2);
			while (l <= r) {
				int m = (l + r) / 2;
				int y = check(a, b, m);
				if (y != 1e18) {
					res = max(res, {m, x, y});
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}

			for (auto [y, i] : v) {
				a.insert({y, i});
				b.erase({y, i});
			}
		}
		print(res[0]);
		print(res[1], res[2]);
	}
}
