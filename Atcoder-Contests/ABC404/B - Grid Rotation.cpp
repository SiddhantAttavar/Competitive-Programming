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

int solve(vector<vector<bool>> &a, vector<vector<bool>> &b) {
	int res = 0;
	rep(i, 0, a.size()) {
		rep(j, 0, a.size()) {
			res += a[i][j] != b[i][j];
		}
	}
	return res;
}

void rotate(vector<vector<bool>> &a) {
	vector<vector<bool>> res(a.size(), vector<bool>(a.size()));
	rep(i, 0, a.size()) {
		rep(j, 0, a.size()) {
			res[j][a.size() - i - 1] = a[i][j];
		}
	}
	rep(i, 0, a.size()) {
		rep(j, 0, a.size()) {
			a[i][j] = res[i][j];
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<bool>> s(n, vector<bool>(n)), t(n, vector<bool>(n));
	rep(i, 0, n) {
		string a;
		input(a);
		rep(j, 0, n) {
			s[i][j] = a[j] == '.';
		}
	}
	rep(i, 0, n) {
		string a;
		input(a);
		rep(j, 0, n) {
			t[i][j] = a[j] == '.';
		}
	}

	int res = solve(s, t);
	rotate(s);
	res = min(res, solve(s, t) + 1);
	rotate(s);
	res = min(res, solve(s, t) + 2);
	rotate(s);
	res = min(res, solve(s, t) + 3);
	print(res);
}
