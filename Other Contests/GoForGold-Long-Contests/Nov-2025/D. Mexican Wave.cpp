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

int solve(vector<int> &x, vector<int> &y, int k) {
	int c = 0, res = 0, n = x.size() + y.size();
	while (c < n) {
		int i = lower_bound(x.begin(), x.end(), c) - x.begin();
		if (i + k - 1 >= x.size()) {
			break;
		}
		c = x[i + k - 1];
		i = lower_bound(y.begin(), y.end(), c) - y.begin();
		if (i + k - 1 >= y.size()) {
			break;
		}
		c = y[i + k - 1];
		res += 2 * k;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		vector<int> x, y;
		rep(i, 0, n) {
			if (s[i] == 'S') {
				x.push_back(i);
			}
			else {
				y.push_back(i);
			}
		}

		int res = 0;
		rep(k, 1, n / 2 + 1) {
			res= max({res, solve(x, y, k), solve(y, x, k)});
		}
		print(res);
	}
}
