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

		vi a(n);
		arrput(a);

		vi dp(n + 1, false);
		dp[0] = true;

		stack<int> s;
		rep(i, 0, n) {
			while (!s.empty() and a[i] > a[s.top()]) {
				s.pop();
			}
			if (!s.empty() and a[i] == a[s.top()]) {
				dp[i + 1] = dp[s.top()] or dp[s.top() + 1];
			}
			s.push(i);
		}

		if (dp[n]) {
			print(0);
			continue;
		}

		vi rdp(n + 1, false);
		rdp[n] = true;

		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[i] > a[s.top()]) {
				s.pop();
			}
			if (!s.empty() and a[i] == a[s.top()]) {
				rdp[i] = rdp[s.top()] or rdp[s.top() + 1];
			}
			s.push(i);
		}

		int l = max_element(all(a)) - a.begin();
		int r = n - 1 - (max_element(a.rbegin(), a.rend()) - a.rbegin());
		if (l == 0) {
			print(1);
			print(n, a[l]);
			continue;
		}
		if (r == n - 1) {
			print(1);
			print(1, a[r]);
			continue;
		}
		if (dp[l]) {
			print(1);
			print(n, a[l]);
			continue;
		}
		if (rdp[r + 1]) {
			print(1);
			print(1, a[r]);
			continue;
		}
		if (l < r) {
			print(2);
			print(1, a[r]);
			print(n, a[l]);
			continue;
		}

		while (!s.empty()) {
			s.pop();
		}
		rep(i, 0, l) {
			while (!s.empty() and a[i] > a[s.top()]) {
				s.pop();
			}
			s.push(i);
		}
		set<int> f;
		while (!s.empty()) {
			if (dp[s.top()] or dp[s.top() + 1]) {
				f.insert(a[s.top()]);
			}
			s.pop();
		}

		for (int i = n - 1; i > r; i--) {
			while (!s.empty() and a[i] > a[s.top()]) {
				s.pop();
			}
			s.push(i);
		}
		int res = -1;
		while (!s.empty()) {
			if (f.count(a[s.top()]) and (rdp[s.top()] or rdp[s.top() + 1])) {
				res = a[s.top()];
				break;
			}
			s.pop();
		}
		if (res == -1) {
			print(2);
			print(1, a[r]);
			print(n, a[l]);
		}
		else {
			print(1);
			print(l + 1, res);
		}
	}
}
