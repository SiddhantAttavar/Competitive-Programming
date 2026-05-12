#include <bits/stdc++.h>
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
	const int N = 2e5;
	vector<vi> div(N + 1);
	rep(i, 1, N + 1) {
		for (int j = i; j <= N; j += i) {
			div[j].push_back(i);
		}
	}
	rep(i, 0, N + 1) {
		reverse(all(div[i]));
	}

	setup();

	int n;
	input(n);

	vi a(n);
	arrput(a);

	vi dp(N + 1, 0), v(N + 1, 0);
	for (int j : div[a[0]]) {
		dp[j] = a[0];
	}
	rep(i, 1, n) {
		int x = 0;
		for (int j : div[a[i]]) {
			v[j] = dp[j];
		}

		for (int j : div[a[i]]) {
			for (int k : div[a[i]]) {
				if (k % j == 0 and k > j) {
					v[j] = (v[j] - v[k] + MOD) % MOD;
				}
			}
		}

		for (int j : div[a[i]]) {
			x = (x + a[i] * mdiv(v[j], j)) % MOD;
		}

		print(x);
		for (int j : div[a[i]]) {
			dp[j] = (dp[j] + a[i] * x) % MOD;
		}
	}
}
