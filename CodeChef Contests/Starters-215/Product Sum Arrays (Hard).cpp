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

int32_t main() {
	int N = 1e5;
	vector<int> spf(N + 1);
	iota(spf.begin(), spf.end(), 0);
	vector<int> p;
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}
		p.push_back(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		map<int, int> m;
		int x = n;
		for (int i : p) {
			while (x % i == 0) {
				m[i]++;
				x /= i;
			}
		}
		if (x > 1) {
			m[x]++;
		}

		vector<int> l = {1};
		for (auto [k, v] : m) {
			vector<int> nl = l;
			int z = 1;
			rep(i, 0, v) {
				z *= k;
				for (int j : l) {
					nl.push_back(j * z);
				}
			}
			l = nl;
		}
		sort(l.begin(), l.end());

		map<int, int> s;
		rep(i, 0, l.size()) {
			s[l[i]] = i;
		}

		int v = l.size();
		vector<int> dp(v, 0);
		dp[0] = 1;
		rep(i, 1, v) {
			vector<int> ndp = dp;
			rep(j, 0, v) {
				int k = l[i] * l[j];
				while (n % k == 0) {
					ndp[s[k]] += dp[j];
					k *= l[i];
				}
			}
			dp = ndp;
		}

		print(dp.back());
	}
}
