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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int solve(vi &a, int k) {
	if (a.empty()) {
		return 0;
	}

	int n = sz(a);
	vi x(n);
	x[0] = 0;
	rep(i, 1, n) {
		x[i] = a[x[i - 1]] > a[i] ? x[i - 1] : i;
	}

	array<int, 3> z = {-1, -1, -1};
	rep(i, 0, n) {
		z = max(z, {a[x[i]] - a[i], x[i], i});
	}
	if (k == 0) {
		return z[0];
	}

	vi b = a, c = b;
	b.erase(b.begin() + z[1]);
	c.erase(c.begin() + z[2]);
	return min(solve(b, k - 1), solve(c, k - 1));
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vi a(n);
		arrput(a);

		print(solve(a, k));
	}
}
