#include <bits/stdc++.h>
#include <bits/extc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int N = 300, K = 1000, E = 1000;
vi graph[K][N];
int dp[N][N], ndp[N][N];
int x[N][N], y[N][N], z[N][N];

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

void matmul(int a[N][N], int b[N][N], int c[N][N], int n) {
	int res[N][N];
	rep(i, 0, n) {
		fill(res[i], res[i] + n, 0);
	}
	rep(i, 0, n) {
		rep(j, 0, n) {
			rep(k, 0, n) {
				res[i][k] = (res[i][k] + a[i][j] * b[j][k]) % MOD;
			}
		}
	}
	rep(i, 0, n) {
		copy(res[i], res[i] + n, c[i]);
	}
}

void matpow(int a[N][N], int c[N][N], int n, int b) {
	rep(i, 0, n) {
		rep(j, 0, n) {
			c[i][j] = i == j;
		}
	}
	while (b) {
		if (b & 1) {
			matmul(c, a, c, n);
		}
		matmul(a, a, a, n);
		b >>= 1;
	}
}

int32_t main() {
	setup();
	int n, k, m;
	input(n, k, m);

	int e;
	input(e);

	rep(i, 0, e) {
		int s, t;
		input(s, t);
		string w;
		input(w);

		s--;
		t--;
		rep(j, 0, k) {
			if (w[j] == '1') {
				graph[j][s].push_back(t);
			}
		}
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			dp[i][j] = i == j;
		}
	}
	rep(t, 0, k) {
		rep(i, 0, n) {
			if (t == m % k) {
				copy(dp[i], dp[i] + n, y[i]);
			}
			fill(ndp[i], ndp[i] + n, 0);
		}
		rep(u, 0, n) {
			int c = mdiv(1, sz(graph[t][u]));
			for (int v : graph[t][u]) {
				rep(i, 0, n) {
					ndp[i][v] = (ndp[i][v] + dp[i][u] * c) % MOD;
				}
			}
		}
		swap(dp, ndp);
	}

	matpow(dp, x, n, m / k);
	matmul(x, y, z, n);
	rep(i, 0, n) {
		cout << z[0][i] << ' ';
	}
	cout << endl;
}
