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
const int MOD = 676767677;

const int N = 2e6;
vi pow2(N + 1, 1), fact(N + 1, 1), inv_fact(N + 1);

void dfs(vi &a, int l, int r, int c) {
	if (l > r) {
		return;
	}
	int m = (l + r) / 2;
	a[m] = c;
	if (l == r) {
		return;
	}
	dfs(a, l, m - 1, c + 1);
	dfs(a, m + 1, r, c + 1);
}

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

int comb(int n, int r) {
	return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int solve(int n, int k) {
	return comb(n + k - 1, k - 1);
}

int32_t main() {
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mpow(fact[N], MOD - 2);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vi a(n + 1);
		dfs(a, 1, n, 1);

		vi l(n + 1, 0), r(n + 1, n + 1);
		stack<int> s;
		rep(i, 1, n + 1) {
			while (!s.empty() and a[s.top()] > a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				l[i] = s.top();
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = n; i >= 1; i--) {
			while (!s.empty() and a[s.top()] >= a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top();
			}
			s.push(i);
		}

		int res = 0;
		rep(i, 1, n + 1) {
			int c = solve(m - 1, n + 1);
			if (l[i] > 0) {
				c = (c - solve(m - 1, n + 1 - (i - l[i])) + MOD) % MOD;
			}
			if (r[i] < n + 1) {
				c = (c - solve(m - 1, n + 1 - (r[i] - i)) + MOD) % MOD;
			}
			if (l[i] > 0 and r[i] < n + 1) {
				c = (c + solve(m - 1, n + 1 - (r[i] - l[i]))) % MOD;
			}
			res = (res + c * a[i]) % MOD;
		}
		print(res);
	}
}
