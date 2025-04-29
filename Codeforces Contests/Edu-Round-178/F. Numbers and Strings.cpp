#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int f(int x) {
	if (x < 10) {
		return x;
	}

	vector<int> v;
	int o = x;
	while (o) {
		v.push_back(o % 10);
		o /= 10;
	}
	reverse(v.begin(), v.end());

	vector<vector<int>> dp(v.size(), vector<int>(10, 1));
	for (int i = v.size() - 2; i >= 0; i--) {
		int x = 0;
		for (int j = 9; j >= 0; j--) {
			x += dp[i + 1][j];
			dp[i][j] = x;
		}
	}

	int k = 0, t = 1;
	while (t * 10 <= x) {
		t *= 10;
	}
	int res = f(t - 1) + 1;
	rep(j, 1, v[0]) {
		res += dp[0][j] + dp[1][0];
	}
	rep(i, 0, v.size() - 1) {
		if (v[i] < k) {
			break;
		}
		k = v[i];
		rep(j, k, v[i + 1]) {
			res += dp[i + 1][j];
		}
		if (k > 0) {
			res += dp[i + 1][0];
		}
	}
	return res;
}

int solve(int n) {
	set<string> res;
	rep(i, 1, n) {
		string s = to_string(i);
		sort(s.begin(), s.end());
		res.insert(s);
	}
	return res.size();
}

bool check(int x) {
	int y = 9;
	while (x) {
		if (x % 10 > y) {
			return false;
		}
		y = x % 10;
		x /= 10;
	}
	return true;
}

int brute(int n) {
	set<string> res;
	rep(i, 1, n + 1) {
		string s = to_string(i) + to_string(i + 1);
		sort(s.begin(), s.end());
		res.insert(s);
	}
	return res.size();
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		debug(brute(n));

		int res = f(n / 10) * 9 - 1;
		res += check(n / 10) * min(9ll, n % 10 + 1);
		int k = 1;
		while (10 * k <= n) {
			k *= 10;
			int x = (n - k + 1) / k;
			print(res, x, k);
			res += f(x / 10) * 9;
			res += check(x / 10) * min(9ll, x % 10 + 1);
		}
		print(res);
	}
}
