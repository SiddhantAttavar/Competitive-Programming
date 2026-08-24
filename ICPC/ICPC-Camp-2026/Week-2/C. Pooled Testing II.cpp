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
const int MOD = (int) 1e9 + 7; //998244353;

const int N = 1e5;
vi fact(N + 1, 1), inv_fact(N + 1, 1);

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

int get(int n, int k) {
	if (n < k) {
		return 0;
	}
	return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int solve(vector<bitset<N>> &b, bitset<N> y, int k, int r) {
	if (r == 0) {
		return get(y.count(), k);
	}

	int i = 63 - __builtin_clzll(r);
	r ^= 1 << i;
	return (solve(b, y, k, r) - solve(b, y & ~b[i], k, r) + MOD) % MOD;
}

int32_t main() {
	setup();

	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 1; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}

	int n, m, k;
	input(n, m, k);

	string s;
	input(s);

	vector<bitset<N>> b(m);
	vector<string> t(n);
	arrput(t);
	rep(i, 0, m) {
		rep(j, 0, n) {
			b[i][j] = t[j][i] == '1';
		}
	}

	bitset<N> x = 0, y = 0;
	rep(i, 0, n) {
		y[i] = true;
	}
	int r = 0;
	rep(i, 0, m) {
		if (s[i] == '0') {
			x |= b[i];
		}
		else {
			r |= 1 << i;
		}
	}
	y &= ~x;
	rep(i, 0, m) {
		b[i] &= ~x;
	}

	print(solve(b, y, k, r));
}
