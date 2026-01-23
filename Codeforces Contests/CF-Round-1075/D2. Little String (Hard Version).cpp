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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c;
		input(n, c);

		string w;
		input(w);

		if (w[0] == '0' or w[n - 1] == '0') {
			print(-1);
			continue;
		}
		w[0] = '1'; 
		w[n - 1] = '1';

		int res = 1;
		vi l;
		rep(i, 0, n - 1) {
			if (w[i] == '?') {
				l.push_back(i);
				continue;
			}

			int x = w[i] == '1' ? 2 : i;
			c /= gcd(c, x);
			res = res * x % MOD;
		}

		if (c == 1) {
			print(-1);
			continue;
		}

		if (!l.empty() and l[0] == 1) {
			l.erase(l.begin());
		}
		
		vi nl;
		for (int i : l) {
			if (i % 2 == 0) {
				int x = 2;
				c /= gcd(c, x);
				res = res * x % MOD;
			}
			else {
				nl.push_back(i);
			}
		}
		l = nl;

		if (c == 1) {
			print(-1);
			continue;
		}

		int o = c, x = 0;
		while (o % 2 == 0) {
			o /= 2;
			x++;
		}

		if (o > 1) {
			for (int i : l) {
				int x = 2;
				c /= gcd(c, x);
				res = res * x % MOD;
			}
			l.clear();
		}
		else {
			rep(i, 0, x - 1) {
				if (!l.empty()) {
					int x = 2;
					c /= gcd(c, x);
					res = res * x % MOD;
					l.pop_back();
				}
			}
		}

		for (int i : l) {
			int x = i;
			c /= gcd(c, x);
			res = res * x % MOD;
		}

		if (c == 1) {
			print(-1);
		}
		else {
			print(res);
		}
	}
}
