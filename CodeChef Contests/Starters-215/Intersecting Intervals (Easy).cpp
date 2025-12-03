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

int get(vector<int> &a, vector<int> &b) {
	int n = a.size();
	vector<int> pa(n + 1), pb(n + 1);
	rep(i, 0, n) {
		pa[i + 1] = pa[i] + a[i];
		pb[i + 1] = pb[i] + b[i];
	}

	vector<int> x(n + 1, 0), y(n + 1, 0), z(n + 1, 0);
	rep(i, 0, n) {
		x[i + 1] = min(x[i], pa[i + 1]);
		y[i + 1] = min(y[i], pb[i + 1]);
	}
	z[n] = pb[n];
	for (int i = n - 1; i >= 0; i--) {
		z[i] = max(z[i + 1], pb[i]);
	}

	int res = -1e18;
	rep(i, 0, n) {
		res = max(res, pa[i + 1] - x[i] + z[i + 1] - y[i]);
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		print(max(get(a, b), get(b, a)));
	}
}
