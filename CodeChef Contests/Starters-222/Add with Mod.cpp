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

int mpow(int a, int b, int m = MOD) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b, int m = MOD) {
	return a * mpow(b, m - 2) % m;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, p;
		input(n, p);

		rep(a, 0, n + 1) {
			rep(b, 0, n + 1) {
				vector<vi> dp(n + 1, vi(n + 1, 0)), x(n + 1, vi(n + 1, 0));
				x[a][b] = 1;
				rep(i, 1, n) {
					vector<vi> ndp(n + 1, vi(n + 1, 0)), nx(n + 1, vi(n + 1, 0));
					rep(c, a, n + 1) {
						rep(d, b, n + 1) {

						}
					}
				}
			}
		}
	}
}
