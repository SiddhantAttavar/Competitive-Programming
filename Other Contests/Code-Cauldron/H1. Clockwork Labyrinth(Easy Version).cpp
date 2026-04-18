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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

vector<vi> matmul(vector<vi> &a, vector<vi> &b) {
	int n = sz(a);
	vector<vi> res(n, vi(n, 0));
	rep(j, 0, n) {
		rep(i, 0, n) {
			rep(k, 0, n) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return res;
}

vector<vi> matpow(vector<vi> &a, int b) {
	int n = sz(a);
	vector<vi> res(n, vi(n, 0));
	rep(i, 0, n) {
		res[i][i] = 1;
	}
	while (b) {
		if (b & 1) {
			res = matmul(res, a);
		}
		a = matmul(a, a);
		b >>= 1;
	}
	return res;
}

vector<vi> get(int n, int k, vector<tuple<int, int, string>> &q, vector<vi> &d) {
	vector<vi> dp(n, vi(n, 0));
	rep(i, 0, n) {
		dp[i][i] = 1;
	}
	rep(t, 0, k) {
		vector<vi> ndp(n, vi(n, 0));
		rep(i, 0, n) {
			for (auto &[u, v, w] : q) {
				if (w[t] == '1') {
					ndp[i][v] = (ndp[i][v] + dp[i][u] * d[u][t]) % MOD;
				}
			}
		}
		dp = ndp;
	}
	return dp;
}

int32_t main() {
	setup();
	int n, k, m;
	input(n, k, m);

	int e;
	input(e);

	vector<tuple<int, int, string>> q(e);
	vector<vi> d(n, vi(k));
	rep(i, 0, e) {
		int s, t;
		input(s, t);
		string w;
		input(w);

		s--;
		t--;
		q[i] = {s, t, w};
		rep(j, 0, k) {
			d[s][j] += w[j] == '1';
		}
	}
	rep(i, 0, n) {
		rep(j, 0, k) {
			d[i][j] = mdiv(1, d[i][j]);
		}
	}

	vector<vi> x = get(n, k, q, d), y = get(n, m % k, q, d);
	vector<vi> z = matpow(x, m / k);
	vi res = matmul(z, y)[0];
	arrprint(res);
}
