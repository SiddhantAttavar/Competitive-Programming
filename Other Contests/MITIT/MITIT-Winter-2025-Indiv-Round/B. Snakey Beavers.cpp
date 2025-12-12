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

bool check(vector<int> &x, int m) {
	int l = -2e9;
	for (int i : x) {
		if (l > i + m) {
			return false;
		}
		l = max(l, i - m);
	}
	return true;
}

int solve(vector<int> &x) {
	int n = x.size();
	rep(i, 0, n) {
		x[i] *= 2;
	}
	sort(x.begin(), x.end());
	int l = 0, r = 2e9, res = 2e9;
	while (l <= r) {
		int m = (l + r) / 2;
		if (x.back() - x.front() - 2 * m) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> x(n), y(n);
		rep(i, 0, n) {
			input(x[i], y[i]);
		}

		vector<int> z(n);
		rep(i, 0, n) {
			z[i] = y[i] + x[i];
		}

		print(*max_element(z.begin(), z.end()) - *min_element(z.begin(), z.end()));
		// print(max(solve(x), solve(y)));
	}
}
