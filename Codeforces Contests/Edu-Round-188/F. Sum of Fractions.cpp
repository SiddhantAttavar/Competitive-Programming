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

int32_t main() {
	setup();
	int n, m;
	input(n, m);

	vi a(n), b(m);
	arrput(a);
	arrput(b);

	vi l(n, -1), r(n, n);
	stack<int> s;
	rep(i, 0, n) {
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
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and a[s.top()] >= a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			r[i] = s.top();
		}
		s.push(i);
	}

	vi z(n);
	int res = 0;
	rep(i, 0, n) {
		res = (res + mdiv(1, a[i]) * (i + 1) % MOD * (n - i)) % MOD;
		z[i] = (i - l[i]) * (r[i] - i) % MOD;
	}

	vi q(n);
	iota(all(q), 0);
	sort(all(q), [&](int i, int j) {
		return a[i] < a[j];
	});

	int j = 0, u = 0, v = 0;
	rep(i, 0, n) {
		u = (u + z[i] * mdiv(1, a[i])) % MOD;
	}
	for (int k : b) {
		while (j < n and k > a[q[j]] - 1) {
			u = (u - z[q[j]] * mdiv(1, a[q[j]]) % MOD + MOD) % MOD;
			v = (v + z[q[j]]) % MOD;
			res = (res - z[q[j]] * (a[q[j]] + mdiv(1, a[q[j]])) % MOD + MOD) % MOD;
			j++;
		}
		print((res + k * (u + v) + 2 * v) % MOD);
	}
}
