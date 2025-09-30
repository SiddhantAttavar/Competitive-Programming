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

int solve(vector<pair<int, bool>> &v) {
	sort(v.begin(), v.end());
	int l = 0, r = 0, s = 0, t = 0, res = 1e18;
	for (auto [x, b] : v) {
		if (b) {
			r++;
			t += x;
		}
	}
	for (auto [x, b] : v) {
		if (b) {
			r--;
			t -= x;
		}
		else {
			l++;
			s += x;
		}
		res = min(res, l * x - s + t - r * x);
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<pair<int, bool>> x, y;
		rep(i, 0, n) {
			int a, b, c, d;
			input(a, b, c, d);

			x.push_back({a, true});
			x.push_back({c, false});
			y.push_back({b, true});
			y.push_back({d, false});
		}

		print(solve(x) + solve(y));
	}
}
