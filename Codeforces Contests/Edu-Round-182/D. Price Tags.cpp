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

const int N = 2e5;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, y;
		input(n, y);

		vector<int> c(n);
		arrput(c);

		vector<int> f(N + 1, 0);
		for (int i : c) {
			f[i]++;
		}

		vector<int> p(N + 1, 0);
		rep(i, 1, N + 1) {
			p[i] += f[i] + p[i - 1];
		}

		int res = -1e18;
		rep(i, 2, N + 1) {
			int c = 0;
			for (int j = 1; i * (j - 1) + 1 <= N; j++) {
				int l = i * (j - 1) + 1, r = min(N, i * j);
				c -= y * max(0ll, p[r] - p[l - 1] - f[j]);
				c += (p[r] - p[l - 1]) * j;
			}
			res = max(res, c);
		}
		print(res);
	}
}
