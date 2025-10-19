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

vector<int> conv(vector<int> &a, vector<int> &b) {
	vector<int> c(60, 0);
	rep(i, 0, 60) {
		rep(j, 0, 60) {
			if (i + j < 60) {
				c[i + j] = (c[i + j] + a[i] * b[j]) % MOD;
			}
		}
	}
	return c;
}

vector<int> solve(int n) {
	vector<int> dp(60, 0);
	dp[0] = 1;
	vector<int> a(60, 1);
	while (n) {
		if (n & 1) {
			dp = conv(dp, a);
		}
		a = conv(a, a);
		n >>= 1;
	}
	return dp;
}

void get(int i, vector<int> &s, vector<pair<int, int>> &l, int x, int y, map<int, int> &res, vector<int> &p) {
	if (i == l.size()) {
		p.push_back(x);
		res[x] = y;
		return;
	}

	int z = x;
	rep(j, 0, l[i].second + 1) {
		get(i + 1, s, l, z, y * s[j] % MOD, res, p);
		z *= l[i].first;
	}
}

int32_t main() {
	int N = 1e7;
	vector<int> spf(N + 1);
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
	vector<int> primes;
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}
		primes.push_back(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); rep(tt, 1, tc + 1) {
		int n, a, b;
		input(n, a, b);

		int x = b;
		map<int, int> m;
		for (int p : primes) {
			while (x % p == 0) {
				m[p]++;
				x /= p;
			}
		}
		if (x > 1) {
			m[x]++;
		}

		vector<int> s = solve(n);
		vector<pair<int, int>> l(m.begin(), m.end());

		vector<int> p; 
		map<int, int> t;
		get(0, s, l, 1, 1, t, p);
		
		int res = 0;
		for (int i : p) {
			if (i <= a) {
				res = (res + t[i] * t[b / i]) % MOD;
			}
		}
		cout << "Case #" << tt << ": " << res << endl;
	}
}
