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
const int MOD = (int) 1e9 + 7; //998244353;

vector<vector<int>> mat_mul(vector<vector<int>> &a, vector<vector<int>> &b) {
	vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
	rep(i, 0, a.size()) {
		rep(j, 0, a.size()) {
			rep(k, 0, a.size()) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return res;
}

vector<vector<int>> mod_pow(vector<vector<int>> &a, int k) {
	vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
	rep(i, 0, a.size()) {
		res[i][i] = 1;
	}
	while (k) {
		if (k & 1) {
			res = mat_mul(res, a);
		}
		a = mat_mul(a, a);
		k >>= 1;
	}
	return res;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<vector<int>> a(n, vector<int>(n));
	rep(i, 0, n) {
		arrput(a[i]);
	}
	vector<vector<int>> b = mod_pow(a, k);
	int res = 0;
	rep(i, 0, n) {
		res = (res + accumulate(b[i].begin(), b[i].end(), 0ll)) % MOD;
	}
	print(res);
}
