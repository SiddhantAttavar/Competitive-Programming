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

int32_t main() {
	vector<vi> comb(30, vi(30));
	rep(n, 0, 30) {
		comb[n][0] = 1;
		rep(r, 1, n) {
			comb[n][r] = comb[n - 1][r] + comb[n - 1][r - 1];
		}
		comb[n][n] = 1;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		int x = 1, a = 0, res = 0;
		while (x < n) {
			rep(b, 0, a + 1) {
				if (a + b + 1 > k) {
					res += comb[a][b];
				}
			}
			x *= 2;
			a++;
		}
		res += a + 1 > k;
		print(res);
	}
}
