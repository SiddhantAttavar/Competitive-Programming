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
const int MOD = 998244353;

int get(int n, int p) {
	int res = 0;
	for (int i = p; i <= n; i *= p) {
		res += n / i;
	}
	return res;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	if (k > n - k) {
		k = n - k;
	}

	int N = 1e6;
	vector<int> q(k, true);
	rep(i, 0, k) {
		q[i] = i + n - k + 1;
	}
	vector<bool> p(N + 1, true);
	int res = 1;
	rep(i, 2, N + 1) {
		if (!p[i]) {
			continue;
		}

		int x = 1;
		for (int j = i; j <= N; j += i) {
			p[j] = false;
		}
		for (int j = i; j <= k; j += i) {
			int o = j;
			while (o % i == 0) {
				x--;
				o /= i;
			}
		}
		for (int j = ((n - k + i) / i) * i; j <= n; j += i) {
			while (q[j - (n - k + 1)] % i == 0) {
				x++;
				q[j - (n - k + 1)] /= i;
			}
		}
		x %= MOD;
		res = res * x % MOD;
	}

	rep(i, 0, k) {
		if (q[i] != 1) {
			res = res * 2 % MOD;
		}
	}
	print(res);
}
