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
const int MOD = 998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	string x, y, z;
	input(x, y, z);

	int a = sz(x), b = sz(y), c = sz(z);
	vector<vector<vi>> dp(a + 1, vector<vi>(b + 1, vi(c + 1, 0)));
	dp[0][0][0] = 1;
	rep(i, 0, n) {
		vector<vector<vi>> ndp(a + 1, vector<vi>(b + 1, vi(c + 1, 0)));
		rep(p, 0, a) {
			rep(q, 0, b) {
				rep(r, 0, c) {
					rep(j, 0, 26) {
						char d = (char) ('a' + j);
						int np = p + (d == x[p]), nq = q + (d == y[q]), nr = r + (d == z[r]);
						ndp[np][nq][nr] = (ndp[np][nq][nr] + dp[p][q][r]) % MOD;
					}
				}
			}
		}
		dp = ndp;
	}

	int res = 0;
	rep(p, 0, a) {
		rep(q, 0, b) {
			res = (res + accumulate(dp[p][q].begin(), dp[p][q].begin() + c, 0ll)) % MOD;
		}
	}
	print(res);
}
