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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi p(n);
		arrput(p);
		rep(i, 0, n) {
			p[i]--;
		}

		vi x(n);
		x[0] = 0;
		rep(i, 1, n) {
			x[i] = p[i] > p[x[i - 1]] ? i : x[i - 1];
		}

		stack<int> s;
		vi r(n, -1);
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and p[i] > p[s.top()]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top();
			}
			s.push(i);
		}

		vector<pii> dp(n);
		for (int i = n - 1; i >= 0; i--) {
			if (r[i] == -1) {
				dp[i] = {0, 1};
			}
			else {
				dp[i] = dp[r[i]];
				dp[i].first += dp[r[i]].second + 2 * (r[i] - i - 1);
				dp[i].second += r[i] - i;
			}
		}

		vi res(n, 0);
		rep(i, 0, n) {
			if (x[i] == i) {
				res[i] = dp[i].first + i;
			}
			else if (r[x[i]] == r[i]) {
				res[i] = dp[i].first + i;
			}
			else if (r[x[i]] == -1) {
				res[i] = dp[i].first + i;
			}
			else {
				res[i] = i;
				res[i] += 2 * (r[i] - i - 1) + 1;
				res[i] += 3 * (r[x[i]] - r[i] - 1) + 2;
				res[i] += dp[r[x[i]]].first + 2 * (dp[r[x[i]]].second - 1);
			}
		}
		// rep(i, 0, n) {
		// 	cout << dp[i].first << ',' << dp[i].second << ' ';
		// }
		// cout << endl;
		// arrprint(res);
		// arrprint(r);
		// arrprint(x);
		print(accumulate(all(res), 0ll));
	}
}
