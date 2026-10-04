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

vi compress(vi x) {
	vi a = x;
	sort(all(a));
	rep(i, 0, sz(x)) {
		x[i] = lower_bound(all(a), x[i]) - a.begin();
	}
	return x;
}

bool check(vi &s, vi &t) {
	int n = sz(s);
	vi b(n);
	rep(i, 0, n) {
		b[t[i]] = s[i];
	}

	int l = 0, r = n - 1;
	while (l < n - 1 and b[l] <= b[l + 1]) {
		l++;
	}
	if (l == n - 1) {
		return true;
	}

	while (r > 0 and b[r] >= b[r - 1]) {
		r--;
	}
	return l + 1 == r;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi x(n), y(n);
		rep(i, 0, n) {
			input(x[i], y[i]);
		}

		vi s = compress(x), t = compress(y);
		if (check(s, t) or check(t, s)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
