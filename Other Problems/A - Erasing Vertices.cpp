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

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<bool>> v(n, vector<bool>(n, false));
	rep(i, 0, n) {
		string s;
		input(s);
		rep(j, 0, n) {
			v[j][i] = s[j] == '1';
		}
	}
	rep(i, 0, n) {
		v[i][i] = true;
	}

	rep(k, 0, n) {
		rep(i, 0, n) {
			rep(j, 0, n) {
				v[i][j] = v[i][j] or v[i][k] and v[k][j];
			}
		}
	}

	double res = 0;
	rep(i, 0, n) {
		res += 1.0 / accumulate(v[i].begin(), v[i].end(), 0ll);
	}
	cout << fixed << setprecision(15);
	print(res);
}
