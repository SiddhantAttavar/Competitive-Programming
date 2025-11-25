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
const int MOD = 998244353;

int32_t main() {
	int N = 1e4;
	vector<bool> dp(N + 1, false);
	vector<int> spf(N + 1);
	iota(spf.begin(), spf.end(), 0);
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
			dp[j] = !dp[j];
		}
	}

	vector<int> pow2(1e5 + 1);
	pow2[0] = 1;
	rep(i, 1, (int) 1e5 + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> v(n);
		rep(i, 0, n) {
			set<int> s;
			int x = a[i];
			while (x > 1) {
				s.insert(spf[x]);
				x /= spf[x];
			}
			vector<int> l = {1};
			for (int j : s) {
				vector<int> nl = l;
				for (int k : l) {
					nl.push_back(k * j);
				}
				l = nl;
			}
			l.erase(l.begin());
			v[i] = l;
		}

		vector<int> p(N + 1, 0), q(N + 1, 0);
		for (vector<int> l : v) {
			for (int i : l) {
				q[i]++;
			}
		}

		int res = 0;
		rep(i, 0, n) {
			for (int j : v[i]) {
				q[j]--;
				int k = pow2[p[j]] * (n - i - 1 - q[j]) % MOD;
				if (dp[j]) {
					res = (res + k) % MOD;
				}
				else {
					res = (res - k + MOD) % MOD;
				}
				p[j]++;
			}
		}
		res = (res + count(a.begin(), a.end(), 1)) % MOD;
		print(res);
	}
}
